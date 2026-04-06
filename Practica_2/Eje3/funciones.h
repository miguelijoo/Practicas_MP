#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **reservarmemoria(int *nfil,int *ncol);
void imprimematriz(int **matriz, int nfil, int ncol);
void rellenarmatriz(int **matriz, int nfil, int ncol);
int *mincol(int **matriz, int nfil, int ncol);
void liberarmemoria(int ***matriz, int nfil);