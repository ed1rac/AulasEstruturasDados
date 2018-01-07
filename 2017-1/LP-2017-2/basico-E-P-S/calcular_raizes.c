#include <stdio.h>
#include <math.h>
int main(){
    //entrada
    float num1, raizq, raiz3, raiz4;

    printf("Digite o primeiro valor: ");
    scanf(" %f", &num1); 
    //processamento    
    raizq = sqrt(num1);
    raiz3 = pow(num1, (float) 1/3);  //casting explícito
    raiz4 = pow(num1,1/4.0);    //colocar 4.


    //saídas    
    printf("A raizes de %g sao:\n", num1);
    printf("Raiz quadrada =\t%f\n",raizq);
    printf("Raiz cubica =\t%f\n",raiz3);    
    printf("Raiz quartica =\t%f\n",raiz4);
}