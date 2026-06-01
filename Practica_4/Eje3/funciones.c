#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int rellenarvector(alumno **alumnos){
    FILE *fichero;
    fichero=fopen("datos.bin", "rb");
    if(fichero==NULL){
        return -1;
    }
    alumno aux;
    int n=0;
    while(fread(&aux, sizeof(alumno), 1, fichero)==1){
        n+=1;
    }
    rewind(fichero);
    *alumnos=(alumno*) malloc(n*sizeof(alumno));
    fread(*alumnos, sizeof(alumno), n, fichero);
    fclose(fichero);
    return n;
}

void imprimirvector(alumno *alumnos, int n){
    for(int i=0;i<n;i++){
        printf("\n%s %d %f\n", alumnos[i].nombre, alumnos[i].DNI, alumnos[i].nota);
    }
}

int nota_asc(const void *a, const void *b){
    alumno *alumnoA= (alumno*)a;
    alumno *alumnoB= (alumno*)b;
    if(alumnoA->nota>alumnoB->nota){
        return 1;
    }
    if(alumnoA->nota<alumnoB->nota){
        return -1;
    }
    return 0;
}

int nota_desc(const void *a, const void *b){
    alumno *alumnoA= (alumno*)a;
    alumno *alumnoB= (alumno*)b;
    if(alumnoA->nota>alumnoB->nota){
        return -1;
    }
    if(alumnoA->nota<alumnoB->nota){
        return 1;
    }
    return 0;
}

int nombre_asc(const void *a, const void *b){
    alumno *alumnoA = (alumno*)a;
    alumno *alumnoB = (alumno*)b;
    return strcmp(alumnoA->nombre, alumnoB->nombre);
}

int nombre_desc(const void *a, const void *b){
    alumno *alumnoA = (alumno*)a;
    alumno *alumnoB = (alumno*)b;
    return strcmp(alumnoB->nombre, alumnoA->nombre); /*Si devuelve un número negativo, la cadena B va antes que la A, si es positivo lo contrario, si es 0 son iguales.*/
}