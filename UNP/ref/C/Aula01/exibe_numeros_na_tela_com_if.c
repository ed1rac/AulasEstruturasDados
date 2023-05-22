#include<stdio.h>
#include<stdlib.h>

int main(){
    int contador, numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    contador = 1;   //valor inicial do contador
    while(contador<=numero){    //numero é o valor final
        if(contador%2!=0){
            printf("%d\n", contador);        
        }
        contador++;
    }
    system("pause");
}
