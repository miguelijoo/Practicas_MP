#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **reservarmemoria(int nfil,int ncol);
void rellenarmatriz(float **matriz, int nfil, int ncol);
void imprimematriz(float **matriz, int nfil, int ncol);
float *maxfila(float **matriz, int nfil, int ncol);
void liberarmemoria(float ***matriz);

#endif