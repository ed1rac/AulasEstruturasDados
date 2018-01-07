#include <stdio.h>
#include <math.h>
int main(){
    //entrada
    int num1, num2, num3, num1q;
    float num2q, num3q;

    printf("Digite o primeiro valor: ");
    scanf(" %d", &num1);
    printf("Digite o segundo valor: ");
    scanf(" %d", &num2);
    printf("Digite o terceiro valor: ");
    scanf(" %d", &num3);
    //processamento    
    num1q = num1 * num1;
    num2q = pow(num2, 2);
    num3q = pow(num3,2);
    //sa√≠das    
    printf("os numeros elevados ao quadrado s„o: %d, %g, %g", num1q, num2q, num3q);
}