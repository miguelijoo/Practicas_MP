#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct libro {
    char titulo[50];
    char autor[50];
    float precio;
    int unidades;
};

void buscarlibro(FILE *fichero, char *nombre);

#endif