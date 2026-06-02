#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct monomio{
    int coef;
    int exp;
    struct monomio *siguiente;
}monomio;

void anadir(monomio **cabeza);

int comprobar(monomio *cabeza, monomio *nuevo);

void mostrarpolinomio(monomio *cabeza);

float evaluarpol(monomio *cabeza, float i);

void eliminarmonomio(monomio **cabeza);

#endif