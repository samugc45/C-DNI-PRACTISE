#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 80

typedef struct

{

    unsigned dia, mes, anyo;

} DATE;


struct ALUMNO

{ char DNI[9+1];

  char nom_comp [20+1];

  DATE nac;

};

const char nombres[8][10+1]={"jose","roberto","fernando","mario",

"sandra", "raquel", "isabel", "pilar"};

const char apellidos[8][10+1]={"garcia", "hernandez", "gutierrez",

"gomez", "fernandez", "lopez", "sanchez", "perez" };

void print_DATE(DATE ); //Listo
void print_ALUMNO (struct ALUMNO);
void rand_DATE(DATE  *); //Listo
void rand_nom_comp(char [20+1]); //Listo
void rand_ALUMNO(struct ALUMNO  *); //Listo
unsigned es_fecha_valida(DATE); //Listo

void rand_str_DNI(char [9+1]);

int main()
{
    struct ALUMNO alumnos [A];
    srand(time(NULL));
    int i;
    for(i = 0;i < A;i++){
        rand_ALUMNO(&alumnos[i]);
        print_ALUMNO(alumnos[i]);
    }

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


unsigned es_fecha_valida(DATE fecha) {

    unsigned Diasmes [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((fecha.anyo % 4 == 0 && fecha.anyo % 100 != 0) || (fecha.anyo % 400 == 0)){
        Diasmes[1] = 29;
    }

    if(fecha.dia > Diasmes[fecha.mes - 1]){
        return 0;
    } else return 1;
}
void rand_DATE(DATE  *fecha){
    do{
        fecha->dia = (rand()%31)+1;
        fecha->mes = (rand() %12)+1;
        fecha->anyo = (rand() %7)+1999;
    }while(!es_fecha_valida(*fecha));
}

void print_DATE(DATE fecha){
    printf("%02u - %02u - %04u\n",fecha.dia,fecha.mes,fecha.anyo);
}


void rand_nom_comp(char nombre_completo[20+1]){ //strcat (concatena)
    nombre_completo [0] = '\0';
    strcat(nombre_completo,apellidos[rand()%8]);
    strcat(nombre_completo, ", ");
    strcat(nombre_completo,nombres[rand()%8]);
}

void rand_ALUMNO(struct ALUMNO  *alumno){
    rand_str_DNI(alumno->DNI);
    rand_nom_comp(alumno->nom_comp);
    rand_DATE(&alumno->nac);
}

void print_ALUMNO(struct ALUMNO alumno) {
    printf("%-15s%-32s", alumno.DNI, alumno.nom_comp);
    print_DATE(alumno.nac);
}


