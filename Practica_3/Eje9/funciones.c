#include <stdio.h>
#include "funciones.h"

int mcd(int x, int y){
    if(y==0){
        return x;
    }
    else{
        return mcd(y, x%y);
    }
}