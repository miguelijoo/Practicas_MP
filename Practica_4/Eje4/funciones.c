#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

void anadir(monomio **cabeza){
    monomio *aux=*cabeza, *ant=aux, *nuevo;
    nuevo=(monomio*) malloc(sizeof(monomio));
    if(nuevo==NULL){
        printf("No se ha podido reservar la memoria.\n");
        exit(-1);
    }
    printf("Introduzca los datos del monomio:\nCoeficiente: ");
    scanf("%d", &(nuevo->coef));
    if(nuevo->coef==0){
        return;
    }
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

void mostrarmonomio(monomio *cabeza){
    monomio *aux=cabeza;
    while(aux!=NULL){
        if(aux->coef>0 && aux->exp!=0 && aux==cabeza){ /*3x²*/
            printf("%dx^%d", aux->coef, aux->exp);
        }
        else if(aux->coef>0 && aux->exp==0 && aux==cabeza){ /*3*/
            printf("%d", aux->coef);
        }
        else if(aux->coef<0 && aux->exp==0){/*-3*/
            printf("-%d", aux->coef);
        }
        else if(aux->coef<0 && aux->exp!=0){ /*-3x²*/
            printf("-%dx^%d", aux->coef, aux->exp);
        }
        else if(aux->coef>0 && aux->exp==0 && aux!=cabeza){ /*+3*/
            printf("+%d",aux->coef);
        }
        else if(aux->coef>0 && aux->exp!=0 && aux!=cabeza){ /*+3x²*/
            printf("+%dx^%d", aux->coef, aux->exp);
        }
        aux=aux->siguiente;
    }
}

float evaluarpol(monomio *cabeza, float i){
    monomio *aux=cabeza;
    float suma=0;
    while(aux!=NULL){
        suma+=aux->coef*pow(i,aux->exp);
        aux=aux->siguiente;
    }
    return suma;
}