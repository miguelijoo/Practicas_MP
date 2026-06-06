#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void anadirmuelle(muelle **cabeza){
    muelle *aux=NULL, *ant=NULL, *aux2=NULL;
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
        *cabeza=aux; /*Le asigno a la cabeza el nuevo nodo creado si estaba vacía.*/
        aux->sig==NULL;
        aux->inicio=NULL;
        for(int i=0;i<n;i++){
            push(&(aux->inicio));
        }
    }
    else{
        aux2=*cabeza;
        while(aux2!=NULL){ /*Desplazo el auxiliar en el bucle hasta llegar al último elemento*/
            ant=aux2;
            aux2=aux2->sig;
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