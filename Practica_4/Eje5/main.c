#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "colas.h"

int main(){
    struct nodo *colan=NULL, *colae=NULL;
    int opcion=0, k=3;
    do{
        printf("Elija una opción del menú:\n1.Introducir un trabajo en la cola normal\n2.Introducir un trabajo en la cola especial\n3.Mostrar el estado de las colas\n4.Imprimir\n5.Modificar el valor de la cola\n6.Terminar");
        scanf("%d", &opcion);
    switch (opcion)
    {
        case 1:{
            struct trabajo nuevo;
            printf("Introduzca un login: ");
            scanf("%d", &(nuevo.login));
            while(getchar()!='\n');
            fgets(nuevo.nombre, 25, stdin);
            insertaCola(&colan, nuevo);
            printf("Trabajo introducido.\n");
            break;
        }
        case 2:{
            struct trabajo nuevo;
            printf("Introduzca un login: ");
            scanf("%d", &(nuevo.login));
            while(getchar()!='\n');
            fgets(nuevo.nombre, 25, stdin);
            insertaCola(&colae, nuevo);
            printf("Trabajo introducido.\n");
            break;
        break;
        }
        case 3:{
            struct trabajo aux;
            struct nodo *colaux;
            int x=0;
            if(colan==NULL){
                printf("No hay trabajos en la cola normal.\n");
                break;
            }
            if(colae==NULL){
                printf("No hay trabajos en la cola especial.\n");
                break;
            }
            while(colan!=NULL){
                aux=sacaCola(&colan);
                insertaCola(&colaux,aux);
                x++;
            }
            colan=colaux;
            x=0;
            printf("La cola normal tiene %d trabajos.\n", x);
            while(colae!=NULL){
                aux=sacaCola(&colae);
                insertaCola(&colae, aux);
                x++;
            }
            colae=colaux;
            printf("La cola especial tiene %d trabajos.\n", x);
            break;
        }
        case 4:{
            int x=0;
            while(colae!=NULL && x!=k && colan!=NULL){

            }
            while(colae!=NULL && colan==NULL){
                
            }
        }
        case 5:{

        }
        case 6:
        return 0;
        default:
            printf("Esa opción no es válida, introduce una correcta: ");
            scanf("%d", &opcion);
        }
    }while(opcion!=6);
}