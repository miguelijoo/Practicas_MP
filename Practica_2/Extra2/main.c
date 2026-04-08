#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    printf("Indica cuantos videojuegos quieres guardar: ");
    int num=0;
    scanf("%d", &num);
    videojuego *biblioteca=crearvector(num);
    printf("Rellena la informacion de los videojuegos: \n");
    rellenarvector(biblioteca, num);
}