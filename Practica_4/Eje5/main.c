#include <stdio.h>
#include <stdlib.h>
#include "colas.h"

int main(){
    struct nodo *colan=NULL, *colae=NULL;
    int opcion=0, k=3, x=0;
    do{
        printf("Elija una opción del menú:\n1.Introducir un trabajo en la cola normal\n2.Introducir un trabajo en la cola especial\n3.Mostrar el estado de las colas\n4.Imprimir\n5.Modificar el valor de la cola\n6.Terminar\n");
        scanf("%d", &opcion);
    switch (opcion)
    {
        case 1:{
            struct trabajo nuevo;
            printf("Introduzca un login: ");
            scanf("%d", &(nuevo.login));
            while(getchar()!='\n');
            printf("Introduzca un nombre de fichero: ");
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
            printf("Introduzca un nombre de fichero: ");
            fgets(nuevo.nombre, 25, stdin);
            insertaCola(&colae, nuevo);
            printf("Trabajo introducido.\n");
            break;
        }
        case 3:{
            struct trabajo aux;
            struct nodo *colaux=NULL;
            int y=0;
            while(colan!=NULL){
                aux=sacaCola(&colan);
                insertaCola(&colaux,aux);
                y++;
            }
            colan=colaux;
            colaux=NULL;
            printf("La cola normal tiene %d trabajos.\n", y);
            y=0;
            while(colae!=NULL){
                aux=sacaCola(&colae);
                insertaCola(&colaux, aux);
                y++;
            }
            colae=colaux;
            printf("La cola especial tiene %d trabajos.\n", y);
            break;
        }
        case 4:{
            struct trabajo aux;
            if(colae==NULL){ /*Comprobar si la cola especial está vacía*/
                printf("No hay ficheros para imprimir en la cola especial.\n");
            }
            if(colan==NULL){ /*Lo mismo para la normal*/
                printf("No hay ficheros para imprimir de la cola normal\n");
            }
            if(colae!=NULL && x!=k){ /*Imprime trabajos de la cola especial hasta completar k*/
                aux=sacaCola(&colae);
                printf("Fichero impreso\nLogin: %d\nFichero: %s", aux.login, aux.nombre);
                x++;
            }
            else if(x==k && colan!=NULL){ /*Se imprimen datos de la cola normal si el valor de x es igual a k*/
                printf("La cola especial ha dejado de tener preferencia, ahora se pasa a la cola normal:\n"); 
                aux=sacaCola(&colan);
                printf("Fichero impreso\nLogin: %d\nFichero: %s", aux.login, aux.nombre);
                x=0;
            }
            else if(colan==NULL && colae!=NULL && x==k){ /*Si x es igual a k y la cola normal está vacía pero la cola especial no, se hace esto*/
                aux=sacaCola(&colae);
                printf("Fichero impreso\nLogin: %d\nFichero: %s", aux.login, aux.nombre);
            }
            else if(x!=k && colae==NULL && colan!=NULL){
                aux=sacaCola(&colan);
                printf("Fichero impreso\nLogin: %d\nFichero: %s", aux.login, aux.nombre);
            }
            break;
        }
        case 5:{
            printf("Introduce el nuevo valor de k: ");
            scanf("%d", &k);
            while(k<1){
                printf("Introduzca un valor mayor o igual a 1 de k: ");
                scanf("%d", &k);
            }
            break;
        }
        case 6:
        return 0;
        default:
            printf("Esa opción no es válida, introduce una correcta: ");
            scanf("%d", &opcion);
        }
    }while(opcion!=6);
}