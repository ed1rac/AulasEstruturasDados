#include <stdbool.h>
#include <stdio.h>

bool eh_primo(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int numero;
  printf("Digite um numero inteiro: ");
  scanf(" %d", &numero);
  if (eh_primo(numero)) {
    printf("%d e um numero primo\n", numero);
  } else {
    printf("%d nao e um numero primo\n", numero);
  }
  return 0;
}