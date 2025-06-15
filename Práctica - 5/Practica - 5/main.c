#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 75

unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );

void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
void calcular_frecuencias (char [N], unsigned [23], float [23]);
void print_frecuencias (unsigned [23], float [23]);
void print_barra (float);

int main()
{

    unsigned ArrayDNIS[N],Frecuencias_Absolutas[23] = {0};
    char LetrasDNIS[N];
    float Frecuencias_Relativas [23] = {0};

    srand(time(NULL));
    rand_DNIs(ArrayDNIS, LetrasDNIS);
    calcular_frecuencias(LetrasDNIS,Frecuencias_Absolutas,Frecuencias_Relativas);
    print_frecuencias(Frecuencias_Absolutas,Frecuencias_Relativas);
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
    print_DNIs(ArrayDNIS, LetrasDNIS);
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
        printf("%08u - %-10c", ArrayDNIS[i], LetrasDNIS[i]);
    }
}

void calcular_frecuencias(char LetrasDNIS[N], unsigned Absolutas[23], float Relativas[23]) {

    for (int i = 0; i < N; i++) {
        if (LetrasDNIS[i] >= 'A' && LetrasDNIS[i] <= 'W') {
            Absolutas[LetrasDNIS[i] - 'A']++;
        }
    }

    for (int i = 0; i < 23; i++) {
        Relativas[i] = (float)Absolutas[i] / N * 100;
    }
}

void print_barra(float barras) {
    int veces = barras;
    for (int i = 0; i < veces; i++) {
        printf("*");
    }
}

void print_frecuencias(unsigned Absoluto[23], float Relativo[23]) {
    char letras[23] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L',
    'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    printf("\n > frecuencias absolutas, relativa y diagramas de barra:\n");
    for (int i = 0; i < 23; i++) {
        printf("%c  %2u  %.2f  ", letras[i], Absoluto[i], Relativo[i]/100);
        print_barra(Relativo[i]);
        printf("\n");
    }
}


