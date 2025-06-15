#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100


unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);

void swap_unsigned(unsigned*, unsigned*);
void swap_char(char*, char*);
void bubbleSort(unsigned [N], char [N]);

int main()
{
    unsigned *ArrayDNIS;
    ArrayDNIS = (unsigned *)malloc(N * sizeof(unsigned));
    char *LetrasDNIS;
    LetrasDNIS= (char *)malloc(N * sizeof(char));

    srand(time(NULL));
    rand_DNIs(ArrayDNIS, LetrasDNIS);
    print_DNIs(ArrayDNIS, LetrasDNIS);
    printf("\nDNIs Ordenados: \n");
    bubbleSort(ArrayDNIS, LetrasDNIS);
    print_DNIs(ArrayDNIS, LetrasDNIS);

    free(ArrayDNIS);
    free(LetrasDNIS);


    return 0;

}

void rand_dig(char* dig) {
    *dig = '0' + (rand() % 10);
}

void rand_DNI(unsigned* DNI) {
    *DNI = 0;
    char digito;
    for (int i = 1; i <= 8; i++) {
        rand_dig(&digito);
        *DNI = *DNI * 10 + (digito - '0');
    }
}

void rand_DNIs(unsigned ArrayDNIS[N], char LetrasDNIS[N]) {
    unsigned DNI = 0;
    int resto, letraCalculada;

    for (int i = 0; i < N; i++) {
        rand_DNI(&DNI);
        ArrayDNIS[i] = DNI;
        resto = resto_DNI(DNI);
        letraCalculada = letra_calculada(resto);
        LetrasDNIS[i] = letraCalculada;
    }
}

unsigned resto_DNI(unsigned DNI) {
    return DNI % 23;
}

char letra_calculada(unsigned resto) {
    char letraCalculadaDNI[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X',
                                 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
    return letraCalculadaDNI[resto];
}

void print_DNIs(unsigned ArrayDNIS[N], char LetrasDNIS[N]) {
    printf("  >DNIs Y Letras: \n");
    for (int i = 0; i < N; i++) {
        printf("%08u - %c\t ", ArrayDNIS[i], LetrasDNIS[i]);
    }
}

void swap_unsigned(unsigned *DNIAnt, unsigned *DNISig){
    int aux;
    aux = *DNIAnt;
    *DNIAnt = *DNISig;
    *DNISig = aux;
}

void swap_char(char *LetraAnt, char *LetraSig) {
    char aux;
    aux = *LetraAnt;
    *LetraAnt = *LetraSig;
    *LetraSig = aux;
}

void bubbleSort(unsigned ArrayDNIs[N], char LetrasDNIs[N]) {
    int i,j;
    for (i = N - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (ArrayDNIs[j] > ArrayDNIs[j + 1]) {
                swap_unsigned(&ArrayDNIs[j], &ArrayDNIs[j + 1]);
                swap_char(&LetrasDNIs[j], &LetrasDNIs[j + 1]);
            }
        }
    }
}
