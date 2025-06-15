#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dig,letra;
    unsigned int DNI = 0,restoDNI;

    printf("DNI digito 1 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 2 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 3 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 4 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 5 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 6 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 7 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("DNI digito 8 ? ");
    fflush(stdin);
    scanf("%c", &dig);
    DNI = DNI * 10 + dig - '0';

    printf("\nDNI: %08d",DNI);

    restoDNI = DNI % 23;

    printf("\nrestoDNI: %i",restoDNI);

    printf("\nDNI: %08d",DNI);

    switch (restoDNI) {
        case 0: letra = 'T'; break;
        case 1: letra = 'R'; break;
        case 2: letra = 'W'; break;
        case 3: letra = 'A'; break;
        case 4: letra = 'G'; break;
        case 5: letra = 'M'; break;
        case 6: letra = 'Y'; break;
        case 7: letra = 'F'; break;
        case 8: letra = 'P'; break;
        case 9: letra = 'D'; break;
        case 10: letra = 'X'; break;
        case 11: letra = 'B'; break;
        case 12: letra = 'N'; break;
        case 13: letra = 'J'; break;
        case 14: letra = 'Z'; break;
        case 15: letra = 'S'; break;
        case 16: letra = 'Q'; break;
        case 17: letra = 'V'; break;
        case 18: letra = 'H'; break;
        case 19: letra = 'L'; break;
        case 20: letra = 'C'; break;
        case 21: letra = 'K'; break;
        case 22: letra = 'E'; break;
    }

    printf("\nLetra = %c",letra);

    return 0;
}
