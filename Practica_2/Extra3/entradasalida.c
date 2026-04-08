#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "entradasalida.h"

void rellenarmatriz(double **matriz, int fil, int col, double max, double min){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            matriz[i][j]= min + ((double)rand()/RAND_MAX)*(max-min);
        }
    }
}

void mostrarmatriz(double **matriz, int fil, int col){
    for(int i=0;i<fil;i++){
        printf("\n");
        for(int j=0;j<col;j++){
            printf("%lf ",matriz[i][j]);
        }
    }
}
