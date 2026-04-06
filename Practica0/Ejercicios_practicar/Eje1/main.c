#include <stdio.h>

int main(){
    float saldo=1000.00, retirada=0;
    int opcion=0;
    while(opcion!=3){
        printf("Elige una opcion: \n");
        printf("Opcion 1: consultar saldo \n");
        printf("Opcion 2: sacar dinero \n");
        printf("Opcion 3: Salir\n");
        scanf("%d", &opcion);
        if (opcion==1){
        printf("Tu saldo es: %.2f \n", saldo);
        }
        else if(opcion==2){
            printf("Pon cuanto saldo vas a retirar. \n");
            scanf("%f", &retirada);
            saldo-=retirada;
        }
        else if(opcion<1 || opcion>3){
            printf("Elija una opcion correcta");
        }
    }
    return 0;
}