#include <stdio.h>

int main(void) {
  int numero;
  int count, multiplo;

  printf("Digite um número: ");
  scanf("%d", &numero);

  printf("TABUADA DE %d\n================\n", numero);

  for (count = 1; count <= 12; count++) {
    multiplo = numero * count;
    printf("%d x %-d = %-d \n", numero, count, multiplo);
  }
}