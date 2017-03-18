#include<stdio.h>
#define MAX 10
/* Ao receber v e n >= 1, a função devolve o valor */
/* de um elemento máximo do vetor v[0..n-1].       */
int maximo_r (int, int*);

int maximo_r( int tamanho, int v[]){
   if (tamanho == 1)
      return v[0];
   else{
      int x;
      x = maximo_r(tamanho-1, v);  /* máximo de v[0..n-2] */
      if (x > v[tamanho-1])
         return x;
      else
         return v[tamanho-1];
   }
}
main(){
    int maior, vetor[MAX]={1,20,3,4,5,6,20,8,90,10};

    maior = maximo_r(10, vetor);
    printf("O elemento maximo do vetor eh: %d\n", maior);
    getch();
}
