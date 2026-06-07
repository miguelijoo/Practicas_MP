#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void anadirmuelle(muelle **cabeza, muelle *nuevo){

   
}

void push(contenedor **inicio){
    contenedor *aux=NULL;
    aux=(contenedor*) malloc(sizeof(contenedor));
    if(aux==NULL){
        printf("No se ha podido crear la pila de contenedores.\n");
        exit -1;
    }
    printf("Introduzca el código del contenedor: ");
    scanf("%d", &(aux->cod));
    while(aux->cod<=0){
        printf("Introduzca un código correcto: ");
        scanf("%d", &(aux->cod));
    }
    if(*inicio=NULL){
        *inicio=aux;
        (*inicio)->sig=NULL;
    }
    else{
    aux->sig=*inicio;
    *inicio=aux;
    }
}

void inspeccionAduana(muelle *cabeza, camion **cola){
    muelle *aux=cabeza;
    contenedor *pilaux=NULL, *aux2=NULL;
    while(aux!=NULL){
        while(aux->inicio!=NULL){ /*Metemos en una pila auxiliar a los contenedores de código par*/
            aux2=pop(&(aux->inicio));
            if(aux2->cod%2==0){
                push(&pilaux);
            }
        }
        while(pilaux!=NULL){ /*Revertimos el orden al original.*/
            aux2=pop(&pilaux);
            push(&(aux->inicio));
        }
    }
}

contenedor* pop(contenedor *inicio){

}