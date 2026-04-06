#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

float **crearimagen(int alto, int ancho){
    float **imagen=NULL;
    imagen=(float **) calloc(alto, sizeof(float*));
    if(imagen==NULL){
        return NULL;
    }
    imagen[0]=(float *) calloc(alto*ancho, sizeof(float)); //Creamos todos los espacios de memoria de la matriz en la fila 0.
    if(imagen[0]==NULL){
        return NULL;
    }
    for(int i=1;i<alto;i++){
        imagen[i]=imagen[i-1]+ancho;
        /* * Como cada imagen[i] es un puntero (una fila), hacemos que apunten 
        * justo donde acaba el ancho de la fila anterior. 
        * * Ejemplo con alto=3 y ancho=3:
        * - imagen[0] contiene el bloque gigante de 9 casillas consecutivas.
        * - imagen[1] no empieza al principio, sino 3 casillas más adelante.
         * - imagen[2] apuntará 3 casillas después de donde empieza imagen[1].
        * * Así, cada fila lee solo los datos que le corresponden dentro de la línea recta.
        */
    }
    return imagen;
}

void generarruido(float **imagen, int alto, int ancho){

}