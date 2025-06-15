#include <stdio.h>
#include <stdlib.h>

void scan_letra(char *);
void scan_dig(char * , unsigned );
void scan_DNI(unsigned *);
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void print_menu ();
void scan_opcion(char * );
void validar_letra_DNI (char , char );



int main()
{
    unsigned char opcion,letra,letraCalculada;
    unsigned int DNI;

    do {
    printf("\n");
    print_menu();
    scan_opcion(&opcion);

    if (opcion == '1'){
        scan_DNI(&DNI);
        printf("\nDNI: %08d      ", DNI);
        letra = letra_calculada(DNI);
        printf("Letra: %c\n", letra);
    }

    else if (opcion == '2'){
        scan_DNI(&DNI);
        printf("\nDNI: %08d\n", DNI);
        scan_letra(&letra);
        letraCalculada = letra_calculada(DNI);
        validar_letra_DNI(letra, letraCalculada);
    }

    } while (opcion != '0');

    return 0;
}

void print_menu () {
    printf("1 - Scan DNI y calcular letra\n");
    printf("2 - Scan DNI y letra y comprobar\n");
    printf("0 - END\n");
}

void scan_opcion(char *opcion) { // char letra --> &letra
    fflush(stdin);
    scanf("%c", opcion);
}

void scan_dig(char *dig, unsigned i) {
    printf("DNI digito %d ? ", i);
    fflush(stdin);
    scanf("%c", dig);
}

void scan_DNI(unsigned *DNI) {
    *DNI = 0;
    char digito;
    for (int i = 1; i <= 8; i++) {
        scan_dig(&digito, i);
        while (digito < '0' || digito > '9') {
            scan_dig(&digito, i);
        }

        *DNI = *DNI * 10 + (digito - '0');
    }
}

unsigned resto_DNI(unsigned DNI) {
    return DNI % 23;
}

char letra_calculada(unsigned DNI) {
    char letra;
    switch (resto_DNI(DNI)) {
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
    return letra;
}

void scan_letra(char *letra) {
    printf("\nletra DNI ? ");
    fflush(stdin);
    scanf("%c", letra);
    if (*letra >= 'a' && *letra <= 'z') {
        *letra = *letra - 32;
        printf("\nletra DNI: %c",*letra);
    }
}

void validar_letra_DNI (char letra, char letra_calculada) {
    if (letra == letra_calculada) {
        printf("\nLetra correcta: %c \n",letra);
        } else {
                printf("\nLetra DNI introducida incorrecta");
                printf("\nLetra correcta: %c\n",letra_calculada);
        }
}

