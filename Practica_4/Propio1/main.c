#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(){
    alumno alumnos[5];
    for(int i=0;i<5;i++){
        printf("Nombre: ");
        fgets(alumnos[i].nombre, 50, stdin);
        printf("DNI: ");
        scanf("%d", &(alumnos[i].DNI));
        printf("Nota: ");
        scanf("%f", &(alumnos[i].nota));
        while(getchar()!='\n');
    }
    int (*p)(alumno, alumno);
    printf("\nOrdenación por DNI:\n");
    p=compararDNI;
    ordenarburbuja(alumnos, 5, p);
    p=compararnota;
    printf("\nOrdenación por nota:\n");
    ordenarburbuja(alumnos, 5, p);
    return 0;
}