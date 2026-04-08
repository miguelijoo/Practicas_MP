#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    int lanzamiento;
    float precio;
}videojuego;

videojuego *crearvector(int num);

void rellenarvector(videojuego *biblioteca, int num);

#endif