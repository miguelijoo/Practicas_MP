#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "funciones.h"

int main(int argc, char **argv){
    srand(time(NULL));
    int nelemen=atoi(argv[2]);
    int inf=atoi(argv[3]);
    int sup=atoi(argv[4]);
    if(argc!=5){
        printf("Introduzca solamente el programa, el nombre del fichero, el numero de elementos en dicho fichero y los limites inferior y superior de los numeros aleatorios a generar.");
        return -1;
    }
    rellenarfichero(argv[1], nelemen, inf, sup);
    return 0;

}