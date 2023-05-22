#include<stdio.h>
#include<stdlib.h>

int main(){
    //declarar as variaveis
    float salario, aumento;
    //ENTRADA
    printf("Digite um salário: ");
    scanf("%f", &salario);
    //PROCESSAMENTO
    aumento=salario+(salario*(12/100.0));
    //SAIDA
    printf("O salario com aumento é: %.2f", aumento);
    
}
