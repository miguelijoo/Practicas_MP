#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

int main(){
    int n=0, cod=0, codaux=0, x=0;
    struct nodo *pila=NULL, *pilaux=NULL;
    printf("Introduzca el número de contenedores que tendrá la pila: ");
    scanf("%d", &n);
    while(n<=0){
        printf("Error, debe haber al menos 1 contenedor en la pila: ");
        scanf("%d", &n);
    }
    for(int i=0;i<n;i++){
        printf("Introduzca el código del contenedor %d: ", i+1);
        scanf("%d", &cod);
        while(cod<=0){
            printf("Error, introduzca un código correcto para el contenedor.\n");
            printf("Código: ");
            scanf("%d", &cod);
        }
        push(&pila, cod);
    }
    printf("Ahora se procede a sacar los contenedores de la pila: \n");
    for(int i=0;i<n;i++){ /*Este bucle mete a los contenedores de la pila en una pila auxiliar pero en este proceso se invierte el orden.*/
        cod=pop(&pila);
        printf("Contenedor %d: %d\n", i+1, cod);
        push(&pilaux, cod);
    }
    for(int i=0;i<n;i++){ /*Revertimos al orden natural de la pila.*/
        cod=pop(&pilaux);
        push(&pila, cod);
    }
    printf("Introduzca un código para buscarlo en la pila: ");
    scanf("%d", &codaux);
        while(codaux<=0){
            printf("Error, introduzca un código correcto para el contenedor.\n");
            printf("Código: ");
            scanf("%d", &codaux);
        }
    for(int i=0;i<n;i++){
        cod=pop(&pila);
        if(cod==codaux){
            printf("Se ha encontrado el contenedor buscado.\n");
            x=1;
        }
        else if(i==n-1 && codaux!=cod && x!=1){
            printf("No se ha podido encontrar el código.\n");
        }
        push(&pilaux, cod);
    }
    for(int i=0;i<n;i++){
        cod=pop(&pilaux);
        push(&pila, cod);
    }
    printf("Introduzca el código del contenedor a sacar de la pila.\n");
    scanf("%d", &codaux);
        while(codaux<=0){
            printf("Error, introduzca un código correcto para el contenedor.\n");
            printf("Código: ");
            scanf("%d", &codaux);
        }
    while(pilaVacia(pila)==0){
        cod=pop(&pila);
        if(cod!=codaux){ /*Si el código no coincide con el del contenedor a eliminar, se repone en la pila auxiliar.*/
            push(&pilaux, cod);
        }
    }
    while(pilaVacia(pilaux)==0){
        cod=pop(&pilaux);
        push(&pila, cod);
    }
    return 0;
}