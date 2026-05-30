#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int rellenarvector(alumno **alumnos){
    FILE *fichero;
    fichero=fopen("datos.bin", "rb");
    if(fichero==NULL){
        printf("Error, no se ha podido abrir el fichero.\n");
        return;
    }
    alumno aux;
    int n=0;
    while(fread(&aux, sizeof(alumno), 1, fichero)!=NULL){
        n+=1;
    }
    rewind(fichero);
    *alumnos=(alumno*) malloc(n*sizeof(alumno));
    fread(alumnos, sizeof(alumno), n, fichero);
    fclose(fichero);
    return n;
}

void ordenarvector(alumno alumnos, int n){
    /*Aquí hay que hacer los algoritmos de ordenación, usaré el burbuja*/
}