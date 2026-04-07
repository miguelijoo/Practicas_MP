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
    for(int i=0;i<alto*ancho;i++){
        *(imagen[0]+i)=((float)rand() / RAND_MAX) * 255.0;
        printf("%.2f ", *(imagen[0]+i));
        if((i+1)%ancho==0){
            printf("\n");
        }
    }
}

void aplicarumbral(float **imagen, int alto, int ancho, float umbral){
    printf("La nueva imagen tras aplicar el umbral es: \n");
    for(int i=0;i<alto;i++){
        printf("\n");
        for(int j=0;j<ancho;j++){
            if(imagen[i][j]<umbral){
                imagen[i][j]=0;
            }
            printf("%.2f ", imagen[i][j]);
        }
    }
}

void destruirimagen(float ***imagen){
    free((*imagen)[0]); /*Primero señalamos con * antes de la imagen que estamos accediendo a la imagen del main, no al puntero que permite hacer este paso por referencia. En segundo lugar liberamos por completo el array generado. Como hemos hecho toda la matriz en la fila 0 y luego simplemente hemos asignado cada puntero de las otras filas a una posición del array hecho en la fila 0, con liberar la fila 0 vamos sobrados y además nos aseguramos evitar errores ya que debe haber tantos free como calloc, malloc y realloc haya, nada más.*/
    free(*imagen); /*Una vez liberado el array completo, liberamos la matriz en general, es decir, hacemos un free al array de punteros, a las filas, tras haber liberado las columnas.*/
    *imagen=NULL; /*Ponemos la matriz a NULL para asegurarnos que no da problemas en memoria*/
}