#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include <stdlib.h>

void invertir(int v[], int iz, int de){
    if(iz>=de){
        return;
    }
    else{
        int aux;
        aux=v[iz];
        v[iz]=v[de];
        v[de]=aux;
        invertir(v, iz+1, de-1);
    }
}