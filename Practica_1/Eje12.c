#include <stdio.h>

struct fraccion{
    int num;
    int den;
};

void leerfrac(struct fraccion *f1, struct fraccion *f2){
  printf("Introduzca la primera fraccion \n");
  scanf("%d", &f1->num);
  scanf("%d", &f1->den);
  printf("Introduzca la segunda fraccion \n");
  scanf("%d", &f2->num);
  scanf("%d", &f2->den);
}

void imprimirfrac(struct fraccion f1, struct fraccion f2){
  printf("La fraccion 1 es %d/%d \n", f1.num, f1.den);
  printf("La fraccion 2 es %d/%d \n", f2.num, f2.den);
}

void multiplicarfrac(struct fraccion f1, struct fraccion f2, struct fraccion *resultado){
  resultado->num=f1.num*f2.num;
  resultado->den=f1.den*f2.den;
}

int main(){
  struct fraccion f1, f2;
  leerfrac(&f1, &f2);
  imprimirfrac(f1, f2);
  struct fraccion resultado;
  multiplicarfrac(f1, f2, &resultado);
  printf("El resultado es %d/%d", resultado.num, resultado.den);
  return 0;
}
