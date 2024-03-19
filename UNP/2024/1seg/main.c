#include "cs50.h"
#include <stdio.h>
#include <string.h>

int main(void) {

  char nome[41];
  string names[] = {"Vanessa", "Ana Ester"};
  string numbers[] = {"+55-083-9495-1000", "+55-083-9468-2750"};

  printf("Escreva algo: ");
  scanf(" %40[^\n]", nome);
  printf("Você digitou: %s\n", nome);

  for (int i = 0; i < 2; i++) {
    if (strcmp(names[i], "Ana Ester") == 0) {
      printf("Encontrado %s\n", numbers[i]);
      return 0;
    }
  }
  printf("Não encontrado\n");
  return 1;
}
