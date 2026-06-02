#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

int main(int argc, char **argv){
    monomio *cabeza=NULL;
    if(argc!=2){
        printf("Introduzca solamente el número de monomios que tendrá el polinomio.\n");
        return -1;
    }
    int x=atoi(argv[1]);
    if(x<=0){
        printf("Error, introduzca un número mayor que 0 para crear el polinomio.\n");
        return -1;
    }
    for(int i=0;i<x;i++){
        anadir(&cabeza);
    }
    mostrarpolinomio(cabeza);
    printf("\n");
    float j;
    for(float i=0;i<5;i+=0.5){
        j=evaluarpol(cabeza, i);
        printf("(x=%.2f,%.2f) ", i, j);
    }
    printf("\n");
    eliminarmonomio(&cabeza);
    mostrarpolinomio(cabeza);
}