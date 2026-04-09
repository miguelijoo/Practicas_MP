/**
 * @file funciones.c
 * @author Miguel Ángel Alijo Fernández
 * @brief Este fichero contiene las funciones relacionadas con la reserva de memoria, la comparación entre números positivos y negativos en la matriz y la liberación de memoria final.
 * @date 09-04-2026
 * @version 1.0.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

double **crearmatriz(int fil,int col){
    double **matriz;
    matriz=(double**) calloc(fil, sizeof(double*));
    if(matriz==NULL){
        return NULL;
    }
    for(int i=0;i<fil;i++){
        matriz[i]=(double*) calloc(col, sizeof(double));
        if(matriz[i]==NULL){
            return NULL;
        }
    }
    return matriz;
}

void comparar(double **matriz, int fil, int col, int *pos, int *neg){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            if(matriz[i][j]>0){
                *pos=*pos+1;
            }
            else if(matriz[i][j]<0){
                *neg=*neg+1;
            }
        }
    }
}

void liberarmatriz(double ***matriz, int fil){
    for(int i=0;i<fil;i++){
        free((*matriz)[i]);
        (*matriz)[i]=NULL;
    }
    free(*matriz);
    *matriz=NULL;
}