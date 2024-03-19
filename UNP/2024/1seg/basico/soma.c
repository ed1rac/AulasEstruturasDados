#include <stdio.h>

int main() {
  int N, i, soma = 0;
  printf("Digite um número inteiro positivo: ");
  scanf(" %d", &N);

  for (i = 1; i <= N; i++) {
    soma += i;
  }

  printf("A soma dos %d primeiros numeros naturais é: %d\n", N, soma);

  return 666;
}