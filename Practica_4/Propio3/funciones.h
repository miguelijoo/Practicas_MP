#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct contenedor{
    int cod;
    struct contenedor *sig;
}contenedor;

typedef struct muelle{
    int id_muelle;
    contenedor *inicio;
    struct muelle *sig;
}muelle;

typedef struct camion{
    contenedor *carga;
    struct camion *sig;
}camion;

void anadirmuelle(muelle **cabeza, muelle *nuevo, int x);

void push(contenedor **inicio,contenedor *nuevo);

void inspeccionAduana(muelle *cabeza, camion **cola);

contenedor* pop(contenedor **inicio);

void encolar(camion **cabeza, contenedor *nuevo);

#endif