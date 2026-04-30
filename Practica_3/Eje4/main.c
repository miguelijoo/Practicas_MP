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
            anadirlibro(fichero, argv[1]);
        }
        else if(opcion==3){
            contarlibros(fichero, argv[1]);
        }
        else if(opcion==4){
            listarlibros(fichero, argv[1]);
        }
        else if(opcion==5){
            libro *libros=NULL;
            int n=0;
            hacerstruct(fichero, argv[1], &libros, &n);
            subirprecio(fichero, argv[1], libros, n);
            free(libros);
        }
        else if(opcion==6){
            libro *libros=NULL;
            int n=0;
            hacerstruct(fichero, argv[1], &libros, &n);
            venderlibros(fichero, argv[1], libros, n);
            free(libros);
        }
        else if(opcion==7){
            renovarfichero(fichero, argv[1]);
        }
    }while(0<opcion && opcion<9);
}