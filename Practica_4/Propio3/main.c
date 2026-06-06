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
    for(int i=0;i<5;i++){
        anadirmuelle(&cabeza);
    }
    camion *cola=NULL;
    inspeccionAduana(cabeza, &cola);
    return 0;
}