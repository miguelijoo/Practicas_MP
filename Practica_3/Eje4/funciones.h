#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char titulo[50];
    char autor[50];
    float precio;
    int unidades;
}libro;

void buscarlibro(FILE *fichero, char *nombre);

#endif