#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc!=2){
        printf("Pon el nombre del programa y 1 o 2 para la ordenación por nota o por nombre del vector.\n");
        return -1;
    }
    int z=atoi(argv[1]);
    if(z!=1 && z!=2){
        printf("Introduzca 1 o 2 para establecer la comparación.\n");
        return -1;
    }
    alumno *alumnos=NULL;
    int x=rellenarvector(&alumnos);
    if(x<=0){
        printf("No se ha podido abrir el fichero\n");
        return 0;
    }
    printf("Vector original:\n");
    imprimirvector(alumnos, x);
    if(z==1){
        qsort(alumnos, x, sizeof(alumno), nota_asc);
        printf("Ordenación por nota ascendente:\n");
        imprimirvector(alumnos, x);
        qsort(alumnos, x, sizeof(alumno), nota_desc);
        printf("Ordenación por nota descendente:\n");
        imprimirvector(alumnos, x);
    }
    else if(z==2){
        qsort(alumnos, x, sizeof(alumno), nombre_asc);
        printf("Ordenación por nombre ascendente:\n");
        imprimirvector(alumnos, x);
        qsort(alumnos, x, sizeof(alumno), nombre_desc);
        printf("Ordenación por nombre descendente:\n");
        imprimirvector(alumnos, x);
    }
    free(alumnos);
    return 0;
}