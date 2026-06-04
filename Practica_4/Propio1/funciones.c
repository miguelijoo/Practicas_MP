#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int compararDNI(alumno alumno1, alumno alumno2){
    if(alumno1.DNI>alumno2.DNI){
        return 1;
    }
    return 0;
}

int compararnota(alumno alumno1, alumno alumno2){
    if(alumno1.nota>alumno2.nota){
        return 1;
    }
    return 0;
}

void ordenarburbuja(alumno *alumnos, int n, int (*p)(alumno, alumno)){
    alumno aux;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p(alumnos[j], alumnos[j+1])==1){
                aux=alumnos[j+1];
                alumnos[j+1]=alumnos[j];
                alumnos[j]=aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("Alumno %d:\n", i+1);
        printf("Nombre: %s", alumnos[i].nombre);
        printf("DNI: %d\n", alumnos[i].DNI);
        printf("Nota: %.2f\n", alumnos[i].nota);
    }
}