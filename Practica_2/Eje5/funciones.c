#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

void reservarmemoria(struct jugador **lista, int *longitud){
    printf("Escribe cuantos jugadores vas a listar: ");
    scanf("%d", longitud);
    printf("\n");
    *lista=(struct jugador*) calloc(*longitud, sizeof(struct jugador));
}

void leerjugador(struct jugador lista[], int n){
    printf("Introduce al jugador %d \n", n+1);
    printf("Nombre: ");
    scanf("%s", lista[n].nombre);
    printf("\n");
    printf("Dorsal: ");
    scanf("%d", &lista[n].dorsal);
    printf("\n");
    printf("Peso: ");
    scanf("%f", &lista[n].peso);
    printf("\n");
    printf("Estatura en cm: ");
    scanf("%d", &lista[n].estatura);
}

void listarjugadores(struct jugador lista[], int longitud){
    for(int i=0;i<longitud;i++){
        printf("Jugador nº %d \n", i+1);
        printf("Nombre: %s \n", lista[i].nombre);
        printf("Dorsal: %d \n", lista[i].dorsal);
        printf("Peso: %.3f \n", lista[i].peso);
        printf("Estatura: %d \n", lista[i].estatura);
    }
}

int borrarjugadores(struct jugador **lista, int *longitud){
    char letra;
    int cont=0;
    printf("Pon la letra para borrar a los jugadores: ");
    scanf(" %c", &letra);
    for(int i=0;i<*longitud;i++){
        if(strchr((*lista)[i].nombre,tolower(letra))==NULL && strchr((*lista)[i].nombre, toupper(letra))==NULL){
            (*lista)[cont]=(*lista)[i];
            cont++;
        }
    }
    *lista=(struct jugador*) realloc(*lista, cont*sizeof(struct jugador));
    return cont;
}