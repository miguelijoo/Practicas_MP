#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "entradasalida.h"

int main(){
    srand(time(NULL));
    printf("Introduzca el numero de filas y columnas de la matriz: \n");
    int fil=0, col=0;
    scanf("%d", &fil);
    scanf("%d", &col);
    double **matriz=crearmatriz(fil, col);
    if(matriz==NULL){
        printf("No hay memoria suficiente.");
        return -1;
    }
    double max=0, min=0;
    printf("Elige un maximo y un minimo para los numeros a generar en la matriz: \n");
    scanf("%lf", &max);
    scanf("%lf", &min);
    rellenarmatriz(matriz, fil, col, max, min);
    mostrarmatriz(matriz, fil, col);
    int pos=0, neg=0;
    comparar(matriz, fil, col, &pos, &neg);
    printf("\nHay %d numeros positivos en la matriz. \n", pos);
    printf("Hay %d numeros negativos en la matriz. \n", neg);
    liberarmatriz(&matriz, fil);
    return 0;
}