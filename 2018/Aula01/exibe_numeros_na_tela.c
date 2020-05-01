#include<stdio.h>
#include<stdlib.h>

int main(){
    int contador, numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    contador = 2;   //valor inicial do contador
    while(contador<=numero){    //numero é o valor final
        printf("%d\n", contador);        
        contador+=2;
    }
    system("pause");
}
