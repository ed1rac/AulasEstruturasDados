#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate_n(char *palavra, int n);
void pega_string_e_exibe();

int main(int argc, char *argv[]) {
  if (argc != 1) {
    if (argc == 2) {
      rotate_n(argv[1], (int)argv[2]);
    }
    rotate_n(argv[1], 13);
  } else {
    pega_string_e_exibe();
  }
}

void rotate_n(char *palavra, int n) {
  int i;
  printf("Antes: %s\n", palavra);
  for (i = 0; i < strlen(palavra); i++) {
    palavra[i] = palavra[i] + n;
  }
  printf("Depois: %s\n", palavra);
}

void pega_string_e_exibe() {
  char palavra[100];
  printf("Digite uma frase: ");
  fgets(palavra, 100, stdin);
  printf("Digite o valor da cifra: ");
  int n = scanf(" %d", &n);
  rotate_n(palavra, n);
}