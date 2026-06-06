#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void crearvector(int **v, int inf, int sup){
    *v=(int*) malloc(15*sizeof(int));
    if(*v==NULL){
        printf("No se ha podido crear el vector.\n");
        exit -1;
    }
    printf("Vector actual: ");
    for(int i=0;i<15;i++){
        (*v)[i]=(rand()%(sup-inf+1))+inf;
        printf("%d, ", (*v)[i]);
    }
    printf("\n");
}

int compararasc(const void *a, const void *b){
    int n1=*(int*)a; /*int n1: declaro un entero y lo igualo a *(int*)a. En esto último le digo al puntero const void* que a lo que está apuntando es a un entero. Para que la igualdad no sea de un entero a puntero, lo que hago con el (int*) es desreferenciarlo mediante *(int*). Si quisiera igualar de puntero a puntero no hace falta el * delante de (int*).*/
    int n2=*(int*)b;
    if(n1>n2){
        return 1;
    }
    else if(n1<n2){
        return -1;
    }
    return 0;
}

int buscarvalor(int *v, int n, int valor){
    int inf=0;
    int sup=n-1;
    int centro;
    while(inf<=sup){
        centro=(sup+inf)/2;
        if(v[centro]==valor){
            return centro;
        }
        else if(valor>v[centro]){
            inf=centro+1;
        }
        else if(valor<v[centro]){
            sup=centro-1;
        }
    }
    return -1;
}