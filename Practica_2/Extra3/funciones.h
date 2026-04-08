#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **crearmatriz(int fil, int col);

void comparar(double **matriz, int fil, int col, int *pos, int *neg);

void liberarmatriz(double ***matriz, int fil);
#endif