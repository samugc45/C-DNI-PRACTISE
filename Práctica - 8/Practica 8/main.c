#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100


void rand_str_DNI(char str_DNI[9+1]); //Hecha
void rand_strings_DNIs(char string_DNIs[N][9+1]);//Hecha
void print_strings_DNIs(char string_DNIs[N][9+1]);//Hecha
void strings_swap(char [9+1], char [9+1]);
void strings_bubbleSort(char [N][9+1]);

int main()
{
    srand(time(NULL));
    char string_DNIs[N][9 + 1];

    rand_strings_DNIs(string_DNIs);
    print_strings_DNIs(string_DNIs);
    printf("\nDNIs Ordenados: \n");
    printf("\n");
    strings_bubbleSort(string_DNIs);
    print_strings_DNIs(string_DNIs);


    return 0;
}

void rand_str_DNI(char str_DNI[9+1]){
    int i,Digito,DNI = 0,resto,letraCalculada;
    char letraCalculadaDNI[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X',
    'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
    for(i = 0;i < 9;i++){
        Digito = rand() % 10;// numero del 0 - 9
        DNI = DNI * 10 + Digito;
        str_DNI[i] = Digito + '0' ;
    }
    resto = DNI % 23;
    letraCalculada = letraCalculadaDNI[resto];
    str_DNI[8] = letraCalculada;
    str_DNI[9] = '\0';

}

void rand_strings_DNIs(char string_DNIs[N][9+1]){
    int i,j;
    char str_DNI[9+1];
    for(i = 0;i < N;i++){
        rand_str_DNI(str_DNI);
        for(j = 0;j < 10;j++){
            string_DNIs[i][j] = str_DNI[j];
        }
    }
}

void print_strings_DNIs(char string_DNIs[N][9+1]){
    int i;
    for(i = 0;i < N;i++){
        printf("\t%s",string_DNIs[i]);
    }
    printf("\n");
}

void strings_swap(char StringDNI1[9+1], char StringDNI2[9+1]){
    char aux [9+1];
    memcpy(aux,StringDNI1,9+1);
    memcpy(StringDNI1,StringDNI2,9+1);
    memcpy(StringDNI2,aux,9+1);
}

void strings_bubbleSort(char DNIs[N][9+1]){
    int i,j;
    for (i = N - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if (memcmp(DNIs[j],DNIs[j+1],8) > 0){
                strings_swap(DNIs[j],DNIs[j+1]);
            }
        }
    }
}
