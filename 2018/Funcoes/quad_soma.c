#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao quadrado(x)
    Autor : Edkallenn - Data : 06/04/2012
    Observações: Eleva um numero ao quadrado
*/
int quadrado (int);  //prototipo da funcao
int cubo(int);
double quad_soma(double, double);
int main(){
    int x, a, b;
    for(x = 1;x<=10;x++)
        printf("O quadrado de %3d eh: %d e o cubo eh: %3d\n", x, quadrado(x), cubo(x));
    printf("\n");
    a = 4; b = 5;
   printf("O quadrado da soma de 4 e 5 é: %g", quad_soma(a,b));    
    getchar();
    return 0;
}
//definicao da funcao
int quadrado(int a)
{
    return(a * a);
}
int cubo(int a){
    return (a * a * a);
}
double quad_soma(double a , double b){
  return quadrado(a) + 2 * a * b + quadrado(b);
}
