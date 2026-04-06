#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

float **crearimagen(int alto, int ancho){
    float **imagen=NULL;
    imagen=(float **) calloc(alto, sizeof(float*));
    for(int i=0;i<alto;i++){
        imagen[i]=(float*) calloc(ancho, sizeof(float));
    }
}

void generarruido(float **imagen){
    
}