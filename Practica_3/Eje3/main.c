#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char **argv){
    srand(time(NULL));
    if(argc!=2){
        printf("No hay suficientes argumentos o hay demasiados, introduzca el argumento para ejecutar el programa y el nombre del fichero únicamente\n");
        return -1;
    }
    FILE *fichero;
    crearfichero(&fichero, argv[1]);
     if(fichero==NULL){
        printf("No se ha podido abrir el fichero.");
        return -1;
    }
    rellenarfichero(fichero);
    float media=calcularmedia(fichero);
    printf("La media de los elementos es: %.2f\n", media);
    fclose(fichero);
    return 0;
}