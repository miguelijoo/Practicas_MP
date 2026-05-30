#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

float f(float x){
    float res;
    res=3*exp(x)-2*x;
    return res;
}

float g(float x){
    float res;
    res=-x*sin(x)+1.5;
    return res;
}

float z(float x){
    float res;
    res=pow(x,3)-2*x+1;
    return res;
}