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
    muelle *nuevo=NULL;
    nuevo=(muelle*) malloc(sizeof(muelle));
    if(nuevo==NULL){
        exit -1;
    }
    int x=0;
    for(int i=0;i<n;i++){
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
        anadirmuelle(&cabeza, nuevo);
    }
    camion *cola=NULL;
    inspeccionAduana(cabeza, &cola);
    return 0;
}