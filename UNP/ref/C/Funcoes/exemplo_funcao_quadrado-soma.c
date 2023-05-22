#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*  Função : Funcao quadrado(x)
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: Eleva um numero ao quadrado
*/
int quadrado (int);  //prototipo da funcao
int quad_soma(int, int);
int cubo(int);
int cubo_soma(int, int);

int main()
{
    int num, x, y;
    printf("\nDigite o valor de x: ");
    scanf("%d", &x);
    printf("\nDigite o valor de y: ");
    scanf("%d", &y);
    printf("\nO quadrado da soma de %d e %d eh: %d", x,y,quad_soma(x,y));
    printf("\nO cubo da soma de %d e %d eh: %d", x,y,cubo_soma(x,y));
    getchar();
    return 0;

}
int quad_soma(int x, int y){
    return quadrado(x)+(2*x*y)+quadrado(y);
}

int quadrado(int a){
    return(a * a);
}

int cubo(int merda){
   return (merda*merda*merda);
}

int cubo_soma(int x, int y){
    return cubo(x) + (3*quadrado(x)*y)+(3*y*quadrado(y))+cubo(y);
}
