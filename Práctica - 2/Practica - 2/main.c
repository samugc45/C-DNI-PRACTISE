#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcion,dig,letra_Calculada,letra_Introducida;
    unsigned int DNI, restoDNI;
    do {
        printf("\n");
        printf("1 - Scan DNI y calcular letra_Calculada\n");
        printf("2 - Scan DNI y letra_Calculada y comprobar\n");
        printf("0 - END\n");

        printf("\nopcion ? ");
        fflush(stdin);
        scanf("%c", &opcion);

        if (opcion == '1') {
            DNI = 0;
            for (int i = 1; i <= 8; i++) {
                printf("DNI digito %i ? ", i);
                fflush(stdin);
                scanf("%c", &dig);
                while (dig < '0' || dig > '9') {
                    printf("DNI digito %i ? ", i);
                    fflush(stdin);
                    scanf("%c", &dig);
                }
                DNI = DNI * 10 + (dig - '0');
            }

            printf("\nDNI: %08d", DNI);

            restoDNI = DNI % 23;

            printf("\nrestoDNI: %i", restoDNI);

            switch (restoDNI) {
                case 0: letra_Calculada = 'T'; break;
                case 1: letra_Calculada = 'R'; break;
                case 2: letra_Calculada = 'W'; break;
                case 3: letra_Calculada = 'A'; break;
                case 4: letra_Calculada = 'G'; break;
                case 5: letra_Calculada = 'M'; break;
                case 6: letra_Calculada = 'Y'; break;
                case 7: letra_Calculada = 'F'; break;
                case 8: letra_Calculada = 'P'; break;
                case 9: letra_Calculada = 'D'; break;
                case 10: letra_Calculada = 'X'; break;
                case 11: letra_Calculada = 'B'; break;
                case 12: letra_Calculada = 'N'; break;
                case 13: letra_Calculada = 'J'; break;
                case 14: letra_Calculada = 'Z'; break;
                case 15: letra_Calculada = 'S'; break;
                case 16: letra_Calculada = 'Q'; break;
                case 17: letra_Calculada = 'V'; break;
                case 18: letra_Calculada = 'H'; break;
                case 19: letra_Calculada = 'L'; break;
                case 20: letra_Calculada = 'C'; break;
                case 21: letra_Calculada = 'K'; break;
                case 22: letra_Calculada = 'E'; break;
            }

            printf("\n");

            printf("\nLetra DNI: %c",letra_Calculada);

        } else if (opcion == '2') {
            DNI = 0;
            for (int i = 1; i <= 8; i++) {
                printf("DNI digito %i ? ", i);
                fflush(stdin);
                scanf("%c", &dig);
                while (dig < '0' || dig > '9') {
                    printf("DNI digito %i ? ", i);
                    fflush(stdin);
                    scanf("%c", &dig);
                }
                DNI = DNI * 10 + (dig - '0');
            }

            printf("\nDNI: %08d", DNI);

            printf("\nletra_Introducida DNI ? ");
            fflush(stdin);
            scanf("%c", &letra_Introducida);

            restoDNI = DNI % 23;
            printf("restoDNI: %d", restoDNI);

            switch (restoDNI) {
                case 0: letra_Calculada = 'T'; break;
                case 1: letra_Calculada = 'R'; break;
                case 2: letra_Calculada = 'W'; break;
                case 3: letra_Calculada = 'A'; break;
                case 4: letra_Calculada = 'G'; break;
                case 5: letra_Calculada = 'M'; break;
                case 6: letra_Calculada = 'Y'; break;
                case 7: letra_Calculada = 'F'; break;
                case 8: letra_Calculada = 'P'; break;
                case 9: letra_Calculada = 'D'; break;
                case 10: letra_Calculada = 'X'; break;
                case 11: letra_Calculada = 'B'; break;
                case 12: letra_Calculada = 'N'; break;
                case 13: letra_Calculada = 'J'; break;
                case 14: letra_Calculada = 'Z'; break;
                case 15: letra_Calculada = 'S'; break;
                case 16: letra_Calculada = 'Q'; break;
                case 17: letra_Calculada = 'V'; break;
                case 18: letra_Calculada = 'H'; break;
                case 19: letra_Calculada = 'L'; break;
                case 20: letra_Calculada = 'C'; break;
                case 21: letra_Calculada = 'K'; break;
                case 22: letra_Calculada = 'E'; break;
            }

            if (letra_Introducida == letra_Calculada) {
                printf("\nLetra correcta: %c\n", letra_Introducida);
            } else {
                printf("\nLetra DNI introducida incorrecta");
                printf("\nLetra correcta: %c\n", letra_Calculada);
            }

        }

    } while (opcion != '0');

    return 0;
}
