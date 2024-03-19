#include <stdio.h>

int main() {
  int idade;
  char nome[40];
  printf("Digite seu prenome: ");
  fgets(nome, 40, stdin);
  printf("Digite sua idade: ");
  scanf(" %d", &idade);
  printf("Seu prenome é: %s\n", nome);
  printf("Sua idade é: %d\n", idade);

  return 1;
}