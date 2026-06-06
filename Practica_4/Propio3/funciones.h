#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct muelle{
    int id_muelle;
    contenedor *inicio;
    muelle *sig;
}muelle;

typedef struct contenedor{
    int cod;
    contenedor *sig;
}contenedor;

typedef struct camion{

}camion;



#endif