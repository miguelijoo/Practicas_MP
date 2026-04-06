#include <stdio.h>

float media(int n1, int n2){
    float media=0;
    media=(n1+n2)/2.0; //se divide entre 2.0 ya que si lo divido entre 2 sin nada más me lo detecta como int y se va al carajo
    return media;
}

int main(){
    int n1=0, n2=0;
    printf("Introduzca el valor de los dos numeros para hacer su media: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    float resultado=media(n1,n2);
    printf("La media es %.3f: \n",resultado);
    return 0;
    
}

