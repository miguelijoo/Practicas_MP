#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

float **reservarmemoria(int nfil,int ncol){
    float **matrizdinamica=NULL;
    matrizdinamica=(float**) malloc(nfil*sizeof(float*));
    if(matrizdinamica==NULL){
        printf("No hay memoria suficiente.");
        EXIT_FAILURE;
    }
    matrizdinamica[0]=(float*) malloc(nfil*ncol*sizeof(float));
    if(matrizdinamica[0]==NULL){
        printf("No hay memoria suficiente");
        EXIT_FAILURE;
    }
    for(int i=1;i<nfil;i++){
        matrizdinamica[i]=matrizdinamica[i-1]+ncol;
    }
    return matrizdinamica;
}

void rellenarmatriz(float **matriz, int nfil, int ncol){
    float *v=matriz[0];
    for(int i=0;i<nfil*ncol;i++){
        v[i]=(float)rand()/RAND_MAX;
    }
}

void imprimematriz(float **matriz, int nfil, int ncol){
    for(int i=0;i<nfil;i++){
        printf("\n");
        for(int j=0;j<ncol;j++){
        printf("%.2f ", matriz[i][j]);
        }  
    }
}

float *maxfila(float **matriz, int nfil, int ncol){
    float *v=NULL;
    v=(float*) malloc(nfil*sizeof(float));
    if(v==NULL){
        printf("No hay memoria suficiente.");
        EXIT_FAILURE;
    }
    for(int i=0;i<nfil;i++){
        v[i]=matriz[i][0];
        for(int j=0;j<ncol;j++){
            if(matriz[i][j]>matriz[i][0]){
                v[i]=matriz[i][j];
            }
        }
    }
    return v;
}

void liberarmemoria(float ***matriz){
    free ((*matriz)[0]);
    free(*matriz);
    *matriz=NULL;
}