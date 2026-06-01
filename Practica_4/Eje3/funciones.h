#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    int DNI;
    float nota;
}alumno;

int rellenarvector(alumno **alumnos);

void imprimirvector(alumno *alumnos, int n);

int nota_asc(const void *a, const void *b);

int nota_desc(const void *a, const void *b);

int nombre_asc(const void *a, const void *b);

int nombre_desc(const void *a, const void *b);

#endif