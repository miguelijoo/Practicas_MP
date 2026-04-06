#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(){
    srand(time(NULL));
    int fil=0, col=0;
    printf("Ponga la cantidad de filas y columnas que quieres que tenga la matriz: \n");
    scanf("%d", &fil);
    scanf("%d", &col);
    float **matriz=reservarmemoria(fil, col);
    rellenarmatriz(matriz, fil,col);
    imprimematriz(matriz, fil, col);
    float *maximofila;
    maximofila=maxfila(matriz, fil, col);
    for(int i=0;i<fil;i++){
        printf("\nEl maximo de la fila %d es: %.2f \n", i+1, maximofila[i]);
    }
    liberarmemoria(&matriz);
    return 0;

}