#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void anadirmuelle(muelle **cabeza, muelle *nuevo, int x){
    muelle *aux=*cabeza;
    if(*cabeza==NULL){ /*Si no hay ningún muelle, el nuevo pasa a ser el primero*/
        *cabeza=nuevo;
    }
    else{ /*Si no se cumple lo anterior, movemos el nuevo muelle al final*/
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->sig=NULL;
    }
}

void push(contenedor **inicio,contenedor *nuevo){
    contenedor *aux=NULL;
    if(*inicio==NULL){
        *inicio=nuevo;
        nuevo->sig=NULL;
    }
    else{
        aux=*inicio;
        *inicio=nuevo;
        nuevo->sig=aux;
    }
}

void inspeccionAduana(muelle *cabeza, camion **cola){
    muelle *aux=cabeza;
    contenedor *pilaux=NULL, *aux2=NULL;
    while(aux!=NULL){
        while(aux->inicio!=NULL){
            aux2=pop(&(aux->inicio));
            if(aux2->cod%2!=0){
                encolar(cola, aux2);
            }
            else{
                push(&pilaux, aux2);
            }
        }
            while(pilaux!=NULL){ /*Revertimos el orden de la pila de cada muelle a su orden original*/
            aux2=pop(&pilaux);
            push(&(aux->inicio),aux2);
            }
        aux=aux->sig;
    }
}

contenedor* pop(contenedor **inicio){
    contenedor *aux=*inicio;
    *inicio=aux->sig;
    return aux;
}

void encolar(camion **cabeza, contenedor *nuevo){
    camion *aux=*cabeza;
    if(*cabeza==NULL){
        *cabeza=(camion*) malloc(sizeof(camion));
        if(cabeza==NULL){
            exit(-1);
        }
        (*cabeza)->carga=nuevo;
        nuevo->sig=NULL; /*Desvinculo al contenedor de cualquier pila posible a la que estuviese enganchado.*/
        (*cabeza)->sig=NULL;
    }
    else{
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=(camion*) malloc(sizeof(camion));
        (aux->sig)->carga=nuevo;
        (aux->sig)->sig=NULL;
    }
}