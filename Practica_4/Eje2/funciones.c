#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int rellenarvector(alumno **alumnos){
    FILE *fichero;
    fichero=fopen("datos.bin", "rb");
    if(fichero==NULL){
        return -1;
    }
    alumno aux;
    int n=0;
    while(fread(&aux, sizeof(alumno), 1, fichero)==1){
        n+=1;
    }
    rewind(fichero);
    *alumnos=(alumno*) malloc(n*sizeof(alumno));
    fread(*alumnos, sizeof(alumno), n, fichero);
    fclose(fichero);
    return n;
}

int ascendente(int x, int y){
    if(x>y){
        return 1;
    }
    else{
        return 0;
    }
}

int descendente(int x, int y){
    if(x<y){
        return 1;
    }
    else{
        return 0;
    }
}
/*Con las funciones ascendente y descendente decido si intercambio en la ordenación burbuja cuando el struct de la posición i es menor que el de la i+1 (descendente) o cuando el de la posición i es mayor que i+1(ascendente)*/
void ordenarvector(alumno *alumnos, int n, int (*p)(int, int)){
    alumno aux;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p(alumnos[j].DNI,alumnos[j+1].DNI)==1){ /*Aquí compruebo cuándo la función asignada al puntero da el valor que permite intercambio.*/
                aux=alumnos[j];
                alumnos[j]=alumnos[j+1];
                alumnos[j+1]=aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("\n%s %d %f\n", alumnos[i].nombre, alumnos[i].DNI,alumnos[i].nota);
    }
}