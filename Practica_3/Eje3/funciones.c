#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

void crearfichero(FILE **fichero, char *nombre){
    *fichero=fopen(nombre, "w+");
}

void rellenarfichero(FILE *fichero){
    printf("Indica la cantidad de elementos que quieres introducir en el fichero: ");
    int n;
    scanf("%d", &n);
    printf("Indica el maximo y minimo de los numeros a generar aleatoriamente: ");
    int max, min;
    scanf("%d", &max);
    scanf("%d", &min);
    for(int i=0;i<n;i++){
    fprintf(fichero,"%d ", (rand() % (max-min+1)) + min);
    }
}

float calcularmedia(FILE *fichero){
    rewind(fichero);
    int n=0, x=0;
    int *v=NULL;
    while(fscanf(fichero, "%d", &n)!=EOF){
        if(n%2==0){
            x++;
            v=(int*) realloc(v, x * sizeof(int));
            v[x-1]=n;
        }
    }
    float suma=0;
    for(int i=0;i<x;i++){
        suma=suma+v[i];
    }
    suma=suma/x;
    return suma;
}