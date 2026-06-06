#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void anadirmuelle(muelle **cabeza){
    muelle *aux=NULL, *ant=NULL;
    aux=(muelle*) malloc(sizeof(muelle));
    if(aux==NULL){
        exit -1;
    }
    if(*cabeza==NULL){
        printf("Introduzca el código del muelle: ");
        scanf("%d", &(aux->id_muelle));
        while(aux->id_muelle<=0){
            printf("Error, introduzca un código correcto: ");
            scanf("%d", &(aux->id_muelle));
        }
        printf("Introduzca el número de contenedores a introducir en el muelle: ");
        int n;
        scanf("%d", &n);
        while(n<=0){
            printf("Error, introduzca un número correcto de contenedores: ");
            scanf("%d", &n);
        }
        *cabeza=aux;
        aux->sig==NULL;
        aux->inicio=NULL;
        for(int i=0;i<n;i++){
            push(&(aux->inicio));
        }
    }
    else{
        while(aux!=NULL){
            ant=aux;
            aux=aux->sig;
        }
        printf("Introduzca el número de contenedores a introducir en el muelle: ");
        int n;
        scanf("%d", &n);
        while(n<=0){
            printf("Error, introduzca un número correcto de contenedores: ");
            scanf("%d", &n);
        }
        for(int i=0;i<n;i++){
            push(&(ant->inicio));
        }
    }
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