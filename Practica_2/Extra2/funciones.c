#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

videojuego *crearvector(int num){
    videojuego *vector;
    vector=(videojuego*) calloc(num, sizeof(videojuego));
    return vector;
}

void rellenarvector(videojuego *biblioteca, int num){
    for(int i=0;i<num;i++){
        printf("\nNombre: ");
        scanf("%s", biblioteca[i].nombre);
        printf("\nAno lanzamiento: ");
        scanf("%d", &biblioteca[i].lanzamiento);
        printf("\nPrecio: ");
        scanf("%f", &biblioteca[i].precio);
    }
}