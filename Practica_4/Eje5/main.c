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
            struct trabajo aux;
            struct nodo *colaux=NULL, *colaux2=NULL;
            int x=0; /*Si tengo errores de variables repetidas, declaro las repetidas al inicio del programa.*/
            while(colae!=NULL && x!=k && colan!=NULL){ /*Imprimo los k primeros elementos de la cola especial si la cola normal no está vacía*/
                aux=sacaCola(&colae);
                printf("Fichero impreso\nlogin: %d\nfichero: %s\n", aux.login, aux.nombre);
                insertaCola(&colaux, aux);
                x++;
            }
            if(x==k){
                printf("Cola especial en pausa, continúa cuando finalice la normal.\n");
            }
            while(colan!=NULL){ /*Imprimo los ficheros de la cola normal*/
                aux=sacaCola(&colan);
                printf("Fichero impreso\nlogin: %d\nfichero: %s\n", aux.login, aux.nombre);
                insertaCola(&colaux2, aux);
            }
            while(colae!=NULL && colan==NULL){ /**/
                
            }
            colae=colaux;
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