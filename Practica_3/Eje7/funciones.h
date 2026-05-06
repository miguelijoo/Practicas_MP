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

void buscarlibro(char *nombre);
void anadirlibro(char *nombre);
void contarlibros(char *nombre);
void listarlibros(char *nombre);
void hacerstruct(char *nombre, libro **libros, int *k);
void subirprecio(char *nombre, libro *libros, int n);
void venderlibros(char *nombre, libro *libros, int n);
void nuevofichero(char *nombre);
void renovarfichero(char *nombre);

#endif