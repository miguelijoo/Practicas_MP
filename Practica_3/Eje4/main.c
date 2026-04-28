#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char **argv){
    if(argc!=2){
        printf("Necesitas poner el nombre del fichero unicamente.");
        return -1;
    }
    FILE *fichero;
    int opcion=0;
    do{
        printf("Elija una de las siguientes opciones:\n");
        printf("1.Comprobar la existencia de un libro en el stock por título\n2.Introducir un nuevo libro en el stock\n3.Contar el numero de libros diferentes en el stock\n4.Listar los libros del stock por titulo\n5.Incrementar el precio de los libros en un porcentaje deseado\n6.Vender las unidades disponibles de un libro, si hay menos se venden todos los disponibles\n7.Generar un fichero solamente con los libros con menos unidades de las especificadas\n8.Borrar registros con 0 unidades\n9.Salir\n");
        scanf("%d", &opcion);
        if(0>opcion || 9<opcion){
            printf("Elija una opcion de las que hay");
            return -1;
        }
        else if(opcion==1){
            buscarlibro(fichero, argv[1]);
        }
        else if(opcion==2){
            añadirlibro(fichero, argv[1]);
        }
    }while(0<opcion<9);
    char titaut[50];
    float precio;
    int unidades;


/*
        printf("Introduzca los datos del libro: \n");
        printf("Nombre (separado por _): ");
        fgets(titaut, 50, stdin);
        if(titaut[strlen(titaut)-1]=='\n'){
            titaut[strlen(titaut)-1]='\0';
        }
        fprintf(fichero,"%s\n", titaut);
        printf("Nombre del autor(separado por _): ");
        fgets(titaut, 50, stdin);
        if(titaut[strlen(titaut)-1]=='\n'){
            titaut[strlen(titaut)-1]='\0';
        }

        fprintf(fichero,"%s\n", titaut);
        printf("Precio: ");
        scanf("%f", &precio);
        printf("Unidades del producto: ");
        scanf("%d", &unidades);
        fprintf(fichero,"%.2f %d\n", precio, unidades);
        while(getchar() != '\n');
    }
*/
}