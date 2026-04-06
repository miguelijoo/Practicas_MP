#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(){
    printf("Especifica el alto y ancho de la imagen a crear: \n");
    int ancho=0, alto=0;
    scanf("%d", &alto);
    scanf("%d", &ancho);
    float **imagen=crearimagen(alto, ancho);

}