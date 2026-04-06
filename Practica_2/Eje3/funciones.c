#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int **reservarmemoria(int *nfil,int *ncol){
    int **matrizcopia=NULL;
    printf("Introduzca el numero de filas y columnas que quiere que tenga la matriz: \n");
    scanf("%d", nfil);
    scanf("%d", ncol);
    matrizcopia=(int **) calloc(*nfil, sizeof(int*));
    if(matrizcopia==NULL){
        return matrizcopia;
    }
    for(int i=0;i<*nfil;i++){
        matrizcopia[i]=(int*) calloc(*ncol, sizeof(int));
        if(matrizcopia[i]==NULL){
            matrizcopia=NULL;
            return matrizcopia;
        }
    }
    return matrizcopia;
}

void rellenarmatriz(int **matriz, int nfil, int ncol){
    for(int i=0;i<nfil;i++){
        for(int j=0;j<ncol;j++){
            *(*(matriz+i)+j)=(rand() %20)+1;
        }
    }
}

void imprimematriz(int **matriz, int nfil, int ncol){
    printf("La matriz generada es esta:");
    for(int i=0;i<nfil;i++){
        printf("\n");
        for(int j=0;j<ncol;j++){
            printf("%d ",*(*(matriz+i)+j));
        }
    }
    printf("\n");
}

int *mincol(int **matriz, int nfil, int ncol){
    int *v=NULL;
    v=(int*) calloc(ncol, sizeof(int));
    if(v==NULL){
        return v;
    }
    for(int j=0;j<ncol;j++){
        v[j]= *(*matriz+j);
        for(int i=0;i<nfil;i++){
            if(*(*(matriz+i)+j)<*(*matriz+j)){
                v[j]=*(*(matriz+i)+j);
            }
        }
    }
    return v;
}

void liberarmemoria(int ***matriz, int nfil){
    for(int i=0;i<nfil;i++){
        free((*matriz)[i]);
        (*matriz)[i]=NULL;
    }
    free(*matriz);
    *matriz=NULL;
}