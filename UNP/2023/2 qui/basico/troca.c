#include <stdio.h>

int main(){
    int num1, num2, aux;

    printf("Digite um número: ");
    scanf(" %d", &num1);
    printf("Digite outro número: ");
    scanf(" %d", &num2);

    printf("ANTES da troca!\n");
    printf("O valor de num1 é %d e o valor de num2 é %d\n", num1, num2);

    aux = num1;
    num1 = num2;
    num2 = aux;

    printf("\nDEPOIS da troca!\n");
    printf("O valor de num1 é %d e o valor de num2 é %d\n", num1, num2);

    return 1;
}
