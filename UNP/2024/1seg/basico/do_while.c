#include <stdio.h>

int main() {
  int soma = 0;
  int i = 0, num;

  do {
    printf("Digite um número: ");
    scanf(" %d", &num);
    soma += num;
    i++;
  } while (num != 0);

  printf("Você leu %d números\n", --i);
  printf("A soma deles é: %d\n", soma);

  return 1;
}