#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

void crearfichero(FILE **fichero){
    printf("Introduzca el nombre del fichero: ");
    char nombre[30];
    fgets(nombre, 30, stdin);
    if(nombre[(strlen(nombre)-1)]=='\n'){
        nombre[(strlen(nombre)-1)]='\0';
    }
    *fichero=fopen(nombre, "w");
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