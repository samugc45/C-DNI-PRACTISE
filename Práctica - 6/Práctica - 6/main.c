#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 100

void print_menu (); //Hecha
void rand_str_DNI(char str_DNI[9+1]); //Hecha
void rand_strings_DNIs(char string_DNIs[N][9+1]);//Hecha
void print_strings_DNIs(char string_DNIs[N][9+1]);//Hecha
void buscar_substring(char _string_DNIs[N][9+1]); //strstr //strcpy
void buscar_letra(char _string_DNIs[N][9+1]);


int main(){

    srand(time(NULL));
    char opcion;
    char string_DNIs[N][9 + 1];

    rand_strings_DNIs(string_DNIs);
    print_strings_DNIs(string_DNIs);

    do{

    printf("\n");
    print_menu();
    opcion = getch();

    if(opcion == '1'){
        buscar_letra(string_DNIs);
    }

    else if(opcion == '2'){
        buscar_substring(string_DNIs);
    }

    }while(opcion != '0');

return 0;

}

void print_menu (){
    printf("1 - Buscar letra\n");
    printf("2 - Buscar substring\n");
    printf("0 - END\n");
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

void buscar_letra(char _string_DNIs[N][9+1]){
    int i;
    char letra;
    printf("Letra a buscar ? ");
    scanf("%c", &letra);
    for(i = 0;i < N;i++){
        if(strchr(_string_DNIs[i],letra)!= NULL){
            printf("%s\n", _string_DNIs[i]);
        }
    }
}

void buscar_substring(char _string_DNIs[N][9+1]){//strstr //strcpy
    int i;
    char substring[9+1];
    printf("Substring a buscar ? ");
    scanf("%s", substring);
    for(i = 0;i < N;i++){
        if(strstr(_string_DNIs[i],substring)!= NULL){
            printf("%s\n", _string_DNIs[i]);
        }
    }
}


