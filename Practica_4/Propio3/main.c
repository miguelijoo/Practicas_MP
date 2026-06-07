#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    muelle *cabeza=NULL;
    printf("Introduzca cuántos muelles quiere añadir al puerto: ");
    int n;
    scanf("%d", &n);
    while(n<=0){
        printf("Error, introduzca un número positivo.\n");
        scanf("%d", &n);
    }
    int x=0;
    
    for(int i=0;i<n;i++){
        muelle *nuevo=NULL;
        nuevo=(muelle*) malloc(sizeof(muelle));
        if(nuevo==NULL){
            exit(-1);
        }
        nuevo->inicio=NULL;
        nuevo->sig=NULL;
        printf("Introduce el código del nuevo muelle: ");
        scanf("%d", &(nuevo->id_muelle));
        while(nuevo->id_muelle<=0){
            printf("Introduce un código correcto: ");
            scanf("%d", &(nuevo->id_muelle));
        }
        printf("Introduce el número de contenedores a poner en el muelle: ");
        scanf("%d", &x);
        while(x<=0){
            printf("Introduce un número de contenedores correcto a introducir: ");
            scanf("%d", &x);
        }
        for(int j=0;j<x;j++){ /*Metemos en el muelle toda la pila de contenedores entera y alojada en el puntero especificado en el muelle*/
            contenedor *nuevo2=NULL;
            nuevo2=(contenedor*) malloc(sizeof(contenedor));
            if(nuevo2==NULL){
                exit(-1);
            }
            printf("Introduce el código del contenedor: ");
            scanf("%d", &(nuevo2->cod));
            while(nuevo2->cod<=0){
                printf("Error, introduce un código correcto: ");
                scanf("%d", &(nuevo2->cod));
            }
            push(&(nuevo->inicio), nuevo2);
        }
        anadirmuelle(&cabeza, nuevo, x);
    }
    camion *cola=NULL;
    inspeccionAduana(cabeza, &cola);
    return 0;
}