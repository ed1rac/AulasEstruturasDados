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
    
    // classificação do IMC
    if (imc < 18.5) {
        printf("\nClassificação: Abaixo do peso");
    } else if (imc >= 18.5 && imc < 24.9) {
        printf("\nClassificação: Peso normal");
    } else if (imc >= 25 && imc < 29.9) {
        printf("\nClassificação: Sobrepeso");
    } else {
        printf("\nClassificação: Obesidade");
    }

    printf("\nFim do programa.\n");
    return 0;
}