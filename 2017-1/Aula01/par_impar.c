#include<stdio.h>
#include<stdlib.h>

int main(){
    //declarar as variaveis
    int num;
    //ENTRADA
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num%2==0){
        printf("O numero %d e' par!\n", num);
    }else{
        printf("O numero %d e' impar!\n", num);
    }    
    system("pause");
}
