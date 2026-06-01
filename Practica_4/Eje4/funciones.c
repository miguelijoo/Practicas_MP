#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

void anadir(monomio **cabeza){
    monomio *aux=*cabeza, *ant=aux, *nuevo;
    nuevo=(monomio*) malloc(sizeof(monomio));
    printf("Introduzca los datos del monomio:\nCoeficiente: ");
    scanf("%d", &(nuevo->coef));
    printf("Exponente: ");
    scanf("%d", &(nuevo->exp));
    while(nuevo->exp<0){
        printf("Introduzca un exponente positivo: ");
        scanf("%d", &(nuevo->exp));
    }
    nuevo->siguiente=NULL;
    if(aux==NULL){
        (*cabeza)=nuevo;
        return;
    }
    int z=comprobar(*cabeza, nuevo);
    while(z==1){
        printf("Ese exponente ya existe, introduzca uno correcto.\n");
        printf("Exponente: ");
        scanf("%d", &(nuevo->exp));
        while(nuevo->exp<0){
            printf("Introduzca un exponente positivo: ");
            scanf("%d", &(nuevo->exp));
        }
        z=comprobar(*cabeza, nuevo);
    }
    if(z==0){
        while(aux!=NULL){
            if(nuevo->exp<aux->exp){
                if(aux->siguiente==NULL){
                    aux->siguiente=nuevo;
                    return;
                }
                else if(aux->siguiente!=NULL){
                    ant=aux;
                    aux=aux->siguiente;
                }
            }
            else if(nuevo->exp>aux->exp){
                if(aux==(*cabeza)){
                    (*cabeza)=nuevo;
                    nuevo->siguiente=aux;
                    return;
                }
                else{
                    ant->siguiente=nuevo;
                    nuevo->siguiente=aux;
                    return;
                }
            }
        }
    }
}

int comprobar(monomio *cabeza, monomio *nuevo){
    monomio *aux=cabeza;
    while(aux!=NULL){
        if(nuevo->exp==aux->exp){
            return 1;
        }
        aux=aux->siguiente;
    }
    return 0;
}