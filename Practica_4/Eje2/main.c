#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc!=2){
        printf("Pon el nombre del programa y 1 o 2 para la ordenación ascendente o descendente del vector.\n");
        return -1;
    }
    alumno *alumnos=NULL;
    int x=rellenarvector(&alumnos);
    ordenarvector(alumnos, x);

    free(alumnos);
    return 0;
}