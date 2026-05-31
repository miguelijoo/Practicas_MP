#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    int DNI;
    float nota;
}alumno;

int rellenarvector(alumno **alumnos);

int ascendente(int x, int y);

int descendente(int x, int y);

void ordenarvector(alumno *alumnos, int n, int (*p)(int, int));

#endif