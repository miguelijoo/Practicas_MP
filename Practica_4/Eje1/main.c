#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

int main(){
    float n;
    printf("Introduzca un valor N para calcular el valor medio del intervalo [0,N] de una función a elegir: ");
    scanf("%f", &n);
    if(n<=0){
        printf("Error, el número debe ser mayor que 0");
        scanf("%f", &n);
    }
    float (*funcion)(float); /*Declaro el puntero a función, llamándolo funcion, que apunta a una función que devuelve un dato float y que tiene como argumento un float.*/
    int opcion;
    printf("Elija una función a evaluar con ese intervalo:\n1.f(x): 3*e^x-2x\n2.g(x): -x*sin(x)+1.5\n3.z(x): x^3-2x+1\n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
        funcion=f; /*Al puntero le asigno la función a la que va dirigida*/
        break;
        case 2:
        funcion=g;
        break;
        case 3:
        funcion=z;
        break;
        default:
        printf("Error, esa opción no está en el menú.\n");
        return -1;
    }
    float suma=0;
    for(float i=0;i<n;i+=0.2){
        suma+=funcion(i); /*Como cada función es del mismo tipo y le he asignado al puntero una de ellas, con llamar a la función usando el puntero con el argumento que le pasaremos a la función es como llamar a la función en el main pasándole el correspondiente parámetro. El puntero es básicamente un mando de televisión que permite elegir cómodamente a qué función llamamos, por eso se hace el switch para elegir la función y así ahorramos hacer 3 bucles diferentes para cada función.*/
    }
    suma=suma/n;
    printf("El valor medio del intervalo es: %.2f\n", suma);
    return 0;
}