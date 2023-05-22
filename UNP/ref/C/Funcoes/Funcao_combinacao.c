#include <stdio.h>
#include <stdlib.h>
/*  Função: Fatorial nao recursivo
    Autor: Edkallenn
    Data:05/09/2013
    Observações:
*/
double fat(int n);
double combinacao(int n, int s);
double arranjo(int, int);

int main(){
   int num1, num2;
   double comb;
   printf("\n\nDigite um numero inteiro nao-negativo: ");
   scanf("%d", &num1);
   printf("\n\nDigite outro numero inteiro nao-negativo: ");
   scanf("%d", &num2);
   comb = combinacao(num1, num2);
   printf("\nA combinacao de %d elementos agrupados %d a %d eh: %.4f", num1, num2, num2, comb);
   printf("\nO arranjo de %d elementos agrupados %d a %d eh: %.4f\n", num1, num2, num2, arranjo(num1, num2));
   getchar();
}

double fat(int n){
    int cont;
    double fatorial;
    fatorial = 1;
    for(cont=1;cont<=n;cont++){
        fatorial*=cont;
    }
    return fatorial;
}

double combinacao(int n, int s){
    return fat(n)/(fat(s)*fat(n-s));
}

double arranjo(int n, int s){
    return fat(n)/fat(n-s);
}
