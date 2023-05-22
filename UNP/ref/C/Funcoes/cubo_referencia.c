#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*  Função :
    Autor : Edkallenn
    Data : 28/03/2019
    Observações: quadrado e cubo por referencia
*/
void cubo_por_valor(int);
void cubo_por_referencia(int *);

int main(){
  int valor, valor2;
  valor = 2;
  cubo_por_valor(valor);
  valor2 = 3;
   cubo_por_referencia(&valor2);
   printf("%d\n", valor2);
   getchar();

}
void cubo_por_valor(int x){
    printf("O cubo de %d = %d\n", x, x*x*x);
    getchar();
}

void cubo_por_referencia(int *x){
    printf("O cubo de %d = %g\n", *x, pow(*x,3));
    *x = *x + 1;  //alterando o valor da variável valor2
    getchar();
}
