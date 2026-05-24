#include <stdio.h>
#include "funciones.h"

int triangular(int num, int x, int res){
    if(res>num){
        return 0;
    }
    else if(res<num){
        res=x+res;
        x+=1;
        return triangular(num, x, res);
    }
    else{
        return 1;
    }
}