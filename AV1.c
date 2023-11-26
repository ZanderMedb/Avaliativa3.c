#include <stdio.h>
#include <string.h>

int romano_decimal(char roman[]) {
    int decimal = 0;
    int valor_anterior = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int valor;
        switch (roman[i]) {
            case 'I':
                valor = 1;
                break;
            case 'V':
                valor = 5;
                break;
            case 'X':
                valor = 10;
                break;
            case 'L':
                valor = 50;
                break;
            case 'C':
                valor = 100;
                break;
            case 'D':
                valor = 500;
                break;
            case 'M':
                valor = 1000;
                break;
            default:
                return -1;
        }

        if (valor < valor_anterior) {
            decimal -= valor;
        } else {
            decimal += valor;
        }
        valor_anterior = valor;
    }

    return decimal;
}

void decimal_binario(int decimal, char binario[]) {
    int x = 0;
    while (decimal > 0) {
        binario[x++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binario[x] = '\0';

    int y= 0;
    int z = x - 1;
    while (y < z) {
        char temp = binario[y];
        binario[y] = binario[z];
        binario[z] = temp;
        y++;
        z--;
    }
}

void decimal_hexal(int decimal, char hexadecimal[]) {
    sprintf(hexadecimal, "%x", decimal);
}

int main() {
    char leonidas[13];
    scanf("%s", leonidas);

    int re_decimal = romano_decimal(leonidas);
    if (re_decimal == -1) {
        printf("Entrada inválida.\n");
        return 1;
    }

    char re_bi[32];
    char re_hexa[32];

    decimal_binario(re_decimal, re_bi);
    decimal_hexal(re_decimal, re_hexa);

    printf("%s na base 2: %s\n", leonidas, re_bi);
    printf("%s na base 10: %d\n", leonidas, re_decimal);
    printf("%s na base 16: %s\n", leonidas, re_hexa);

    return 0;
}