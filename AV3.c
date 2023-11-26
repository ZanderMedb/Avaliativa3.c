#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    char placa[10], dia[20];

    scanf("%s", placa);
    scanf(" %[^\n]s", dia);

    int pla_ca = strlen(placa);
    if (pla_ca != 8 &&pla_ca != 7) {
        printf("Placa invalida\n");
        return 0;
    }

    int maior = 0;
    for (int i = 0; i < pla_ca; i++) {
        if (isalpha(placa[i])) {
            maior++;
        }
    }
    if (maior < 3) {
        printf("Placa invalida\n");
        return 0;
    }
    

    for (int i = 0; i < strlen(dia); i++) {
        dia[i] = tolower(dia[i]);
    }

    int invalida = (strlen(placa) != 7 && strlen(placa) != 8) || (strlen(placa) == 8 && placa[3] != '-');
    int dia_invalido = 1;
    const char *valido[] = {"segunda-feira", "terca-feira", "quarta-feira", "quinta-feira", "sexta-feira", "sabado", "domingo"};

    for (int i = 0; i < sizeof(valido) / sizeof(valido[0]); i++) {
        char dia_minusculo[strlen(valido[i]) + 1];
        for (int j = 0; j < strlen(valido[i]); j++) {
            dia_minusculo[j] = tolower(valido[i][j]);
        }
        dia_minusculo[strlen(valido[i])] = '\0';

        if (strcmp(dia, dia_minusculo) == 0) {
            dia_invalido = 0;
            break;
        }
    }

    if (invalida && dia_invalido) {
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
    } else if (invalida) {
        printf("Placa invalida\n");
    } else if (dia_invalido) {
        printf("Dia da semana invalido\n");
    } else {
        int final_placa = placa[7] - '0';
        if ((strstr(dia, "segunda-feira") != NULL && (final_placa == 0 || final_placa == 1)) ||
            (strstr(dia, "terca-feira") != NULL && (final_placa == 2 || final_placa == 3)) ||
            (strstr(dia, "quarta-feira") != NULL && (final_placa == 4 || final_placa == 5)) ||
            (strstr(dia, "quinta-feira") != NULL && (final_placa == 6 || final_placa == 7)) ||
            (strstr(dia, "sexta-feira") != NULL && (final_placa == 8 || final_placa == 9))) {
            printf("%s nao pode circular %s\n", placa, dia);
        } else if (strstr(dia, "sabado") != NULL || strstr(dia, "domingo") != NULL) {
            printf("Nao ha proibicao no fim de semana\n");
        } else {
            printf("%s pode circular %s\n", placa, dia);
        }
    }

    return 0;
}