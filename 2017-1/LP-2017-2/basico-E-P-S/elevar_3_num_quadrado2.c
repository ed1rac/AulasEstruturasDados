#include <stdio.h>
#include <math.h>
int main(){
    //entrada
    float num1, raizq, raiz3, raiz4;

    printf("Digite o primeiro valor: ");
    scanf(" %f", &num1); 
    //processamento    
    raizq = sqrt(num1);
    raiz3 = pow(num1, 1/3);
    raiz4 = pow(num1,1/4);

    //saídas    
    printf("A raizes de %g sao:\n");
    printf("Raiz quadrada =\t%f",raizq);
    printf("Raiz cúbica =\t%f",raiz3);
    printf("Raiz quártica =\t%f",raizq4;
}