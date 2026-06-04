#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>

typedef struct alumno{
    char nombre[50];
    int DNI;
    float nota;
}alumno;

int compararDNI(alumno alumno1, alumno alumno2);

int compararnota(alumno alumno1, alumno alumno2);

void ordenarburbuja(alumno *alumnos, int n, int (*p)(alumno, alumno));

#endif