#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "funciones.h"



int main(){
    srand(time(NULL));
    FILE *fichero;
    crearfichero(&fichero);
    if(fichero==NULL){
        printf("No se ha podido abrir el ichero.");
        return -1;
    }
    rellenarfichero(fichero);
    fclose(fichero);
    return 0;
}