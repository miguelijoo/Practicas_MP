#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int* elementomayor(int v[], int longitud, int num, int *tam1){
    int *vmayor=NULL;
    int cont=0;
    for(int i=0;i<longitud;i++){
        if(v[i]>num){
            cont+=1;
            vmayor=(int*) realloc(vmayor, cont * sizeof(int));
            vmayor[cont-1]=v[i];
        }
    }
    *tam1=cont;
    return vmayor;
}

int* elementomenor(int v[], int longitud, int num, int *tam2){
int *vmenor=NULL;
    int cont=0;
    for(int i=0;i<longitud;i++){
        if(v[i]<=num){
            cont+=1;
            vmenor=(int*) realloc(vmenor, cont * sizeof(int));
            vmenor[cont-1]=v[i];
        }
    }
    *tam2=cont;
    return vmenor;
}