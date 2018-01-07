#include <stdio.h>
#include <stdlib.h>

int main(){
    //entrada
    float massa, altura, imc;
    printf("Digite a massa: ");
    scanf(" %f", &massa);
    printf("Digite a altura: ");
    scanf(" %f", &altura);
    //processamento
    imc = massa/(altura*altura);
    //saídas
    printf("\nO IMC é: %f", imc);
}