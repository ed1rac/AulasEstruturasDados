#include<stdio.h>
#define MAX 10

int maximo (int, int*);

int maximo( int tamanho, int v[])
{
   int j, maximo;
   maximo = v[0];
   for (j = 1; j < tamanho; j += 1){
      if (v[j] > maximo)
        maximo = v[j];
   }
   return maximo;
}
main(){
    int maior, vetor[MAX]={1,20,3,4,5,6,20,8,9,10};

    maior = maximo(10, vetor);
    printf("O elemento maximo do vetor eh: %d\n", maior);
    getch();
}
