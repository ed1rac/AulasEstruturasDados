#include <stdio.h>

int main() {
  char nome[40];
  int idade;
  printf("Digite seu nome: ");
  fgets(nome, 40, stdin);
  printf("Digite sua idade: ");
  scanf(" %d", &idade);

  printf("Seu nome é: %s\n", nome);
  printf("Sua idade é: %d\n", idade);

  return 1;
}