// Programa p25.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITO 999999
#define TAM_MAX  50

void SelectionSort(int x[], int n);
void troca(int v[], int i, int j);

void troca(int v[], int i, int j){   //funcao para trocar dois elementos
  int aux;
  aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

void SelectionSort(int x[], int n){
  int menor,pos;
  int i,k = 0;

  while (k < n){
    menor = INFINITO;
    for (i = k; i < n; i++)
      if (x[i] < menor){
        menor = x[i];
        pos = i;
      }
    troca(x,k,pos);
    k++;
  }
}

int main(){
  int i,n,a[TAM_MAX];

  // Inicializar gerador de números aleatórios
  srand((unsigned)time(NULL));

  // Vetor gerado aleatoriamente
  n = (rand() % TAM_MAX)+1;
  printf("Vetor original: ");
  for (i = 0; i < n; i++)
  {
    a[i] = (rand() % 100);
    printf("%d ",a[i]);
  }
  printf("\n");

  // Classificar vetor
  SelectionSort(a,n);
  printf("Vetor ordenado: ");
  for (i = 0; i < n; i++)
    printf("%d ",a[i]);
  printf("\n");
  system("PAUSE");
  return 0;
}
