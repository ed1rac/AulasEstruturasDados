#include<stdio.h>
#include<stdlib.h>

int main(){
    int contador, numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    contador = 1;
    while(contador<=numero){
        printf("%d\n", contador);
        contador++;
    }
    system("pause");
}
