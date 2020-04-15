#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao quadrado da soma(x)
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/
float quadrado (float);  //prototipo da funcao
float quad_soma(float x, float y);
float cubo(float n);
float cubo_soma(float x, float y);
main()
{
   float num1, num2;
   printf("Digite um numero: ");    scanf("%f", &num1);
   printf("\nDigite outro numero: "); scanf("%f", &num2);
   printf("\n(%g + %g)^2 = %g\n", num1, num2, quad_soma(num1,num2));
   printf("\n(%g + %g)^3 = %g\n", num1, num2, cubo_soma(num1,num2));
   getchar();
}
//definicao da funcao
float quadrado(float a)
{
    return(a * a);
}
float quad_soma(float x, float y){
    float soma_quad;
    soma_quad = quadrado(x)+(2*x*y)+quadrado(y);
    return soma_quad;
}
float cubo(float n){
    return n*n*n;
}
float cubo_soma(float x, float y){
    return cubo(x)+(3*quadrado(x)*y)+(3*x*quadrado(y))+cubo(y);
}
