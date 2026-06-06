#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearvector(int **v, int inf, int sup);

int compararasc(const void *a, const void *b);

int buscarvalor(int *v, int n, int valor);

#endif