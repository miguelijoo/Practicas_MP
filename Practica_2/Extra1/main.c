#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(){
    srand(time(NULL));
    printf("Especifica el alto y ancho de la imagen a crear: \n");
    int ancho=0, alto=0;
    scanf("%d", &alto);
    scanf("%d", &ancho);
    float **imagen=crearimagen(alto, ancho);
    if(imagen==NULL){
        printf("No hay memoria suficiente");
        return -1;
    }
    generarruido(imagen, alto, ancho);
    printf("\nElija el umbral para la matriz: ");
    float umbral=0;
    scanf("%f", &umbral);
    aplicarumbral(imagen, alto, ancho, umbral);
    destruirimagen(&imagen);
    return 0;
}