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
void anadirlibro(FILE *fichero, char *nombre);
void contarlibros(FILE *fichero, char *nombre);
void listarlibros(FILE *fichero, char *nombre);
void hacerstruct(FILE *fichero, char *nombre, libro **libros, int *k);
void subirprecio(FILE *fichero, char *nombre, libro *libros, int n);

#endif