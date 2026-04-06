#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main(){
    struct jugador *lista;
    int longitud=0;
    reservarmemoria(&lista, &longitud);
    for(int i=0;i<longitud;i++){
        leerjugador(lista, i);
    }
    listarjugadores(lista, longitud);
    int j=borrarjugadores(&lista, &longitud);
    printf("Quedan %d jugadores", j);
    free(lista);
    lista=NULL;
}