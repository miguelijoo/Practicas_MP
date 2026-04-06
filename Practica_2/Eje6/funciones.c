#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"

char **separarpalabras(char cadena[], int longitud){
    char *token, **stringarray=NULL;
    int cont=0;
    token=strtok(cadena, " \n" );
    while(token!=NULL){
        
        stringarray=(char**) realloc(stringarray, (cont+1)*sizeof(char*)); //Hacemos el realloc al puntero doble ya que buscamos ampliar la cantidad de arrays de char que puede recorrer. stringarray es un array de strings, es decir, contiene punteros char* y estos punteros tienen las letras de cada palabra.
    }

}