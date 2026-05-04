#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc!=5){
        printf("Introduzca solamente el programa, el nombre del fichero, el numero de elementos en dicho fichero y los limites inferior y superior de los numeros aleatorios a generar.\n");
        return -1;
    }
    srand(time(NULL));
    int nelemen=atoi(argv[2]);
    int inf=atoi(argv[3]);
    int sup=atoi(argv[4]);
    rellenarfichero(argv[1], nelemen, inf, sup);
    printf("Introduzca el nombre del fichero: ");
    char nombre[50];
    if(fgets(nombre, 50, stdin)==NULL){
        return-1;
    }
    if(nombre[strlen(nombre)-1]=='\n'){
        nombre[strlen(nombre)-1]='\0';
    }
    leerfichero(nombre, nelemen);
    return 0;
}