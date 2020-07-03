#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X -50
#define Y 50

int aleatorio_entre(int, int);

int main(){
  int i;
  srand(time(NULL));
  printf("O valor de RAND_MAX é: %d\n\n", RAND_MAX);
  printf("Gerando 100 aleatorios entre %d e %d: \n", X, Y);
  for (i = 0; i<= 100;i++){
    printf("%d\t", aleatorio_entre(X, Y));
  }
  printf("\n\n");
  getchar();
}

int aleatorio_entre(int x, int y){
  double random, num, R_MAX = RAND_MAX;
  int valor;
  random = rand();
  num = random / (R_MAX + 1);
  valor = num * (y - x + 1 );
  return x + valor;
}