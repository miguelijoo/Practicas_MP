#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(){
    srand(time(NULL));
    int **matriz=NULL;
    int nfil=0,ncol=0;
    matriz=reservarmemoria(&nfil,&ncol);
    if (matriz==NULL){
        printf("No ha habido memoria suficiente para generar la matriz");
        return -1;
    }
    rellenarmatriz(matriz, nfil, ncol);
    imprimematriz(matriz, nfil, ncol);
    int *p=mincol(matriz, nfil, ncol);
    if(p==NULL){
        printf("No hay memoria suficiente para el vector");
        return -1;
    }
    for(int i=0;i<ncol;i++){
        printf("El minimo de la columna %d es: %d \n", i+1, p[i]);
    }
    liberarmemoria(&matriz, nfil);
    return 0;
}