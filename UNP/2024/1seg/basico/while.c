#include <stdio.h>

int main() {
  int num;
  printf("Digite um número: ");
  scanf(" %d", &num);

  // variável contadora
  int i = 1;
  while (i <= num) { // condição
    printf("%d  ", i);
    i++; // altera o contador
  }
  printf("\n");

  return 1;
}