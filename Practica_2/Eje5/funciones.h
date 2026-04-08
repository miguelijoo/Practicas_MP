#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct jugador{
 char nombre[50];
 int dorsal; /* Nº entero */
 float peso; /* Expresado en kilos */
 int estatura; /* Expresado en centímetros*/
};

void reservarmemoria(struct jugador **lista, int *longitud);

void leerjugador(struct jugador lista[], int n);

void listarjugadores(struct jugador lista[], int longitud);

int borrarjugadores(struct jugador **lista, int *longitud);

#endif