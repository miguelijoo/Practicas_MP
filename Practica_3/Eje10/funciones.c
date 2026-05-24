#include <stdio.h>
#include "funciones.h"

int div(int x, int y, int n){
    x=x-y;
    if(x<0){
        return n;
    }
    else{
        n+=1;
        return div(x, y, n); /*Le decimos a la función que asocie un entero al return que sería en este caso la función div*/
    }
}