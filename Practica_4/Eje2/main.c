#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc!=2){
        printf("Pon el nombre del programa y 1 o 2 para la ordenación ascendente o descendente del vector.\n");
        return -1;
    }
    int z=atoi(argv[1]);
    if(z!=1 && z!=2){
        printf("Introduzca 1 o 2 para establecer la comparación.\n");
        return -1;
    }
    alumno *alumnos=NULL;
    int x=rellenarvector(&alumnos);
    if(x==0){
        printf("No se ha podido abrir el fichero\n");
        return 0;
    }
    int (*p)(int, int);
    if(z==1){
        p=ascendente;
    }
    else{
        p=descendente;
    }
    ordenarvector(alumnos, x, p);
    free(alumnos);
    return 0;
}