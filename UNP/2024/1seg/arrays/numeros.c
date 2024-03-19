#include <stdio.h>
int get_int(char *mensagem);
const int N = 3;

int main() {
  int notas[N];
  int i = 0;
  float soma = 0;
  while (i < N) {
    notas[i] = get_int("Digite a nota : ");
    soma += notas[i];
    i++;
  }
  printf("A média das notas é: %f\n", soma / (float)N);
  return 1;
}

int get_int(char *mensagem) {
  int num;
  printf("%s\n", mensagem);
  scanf(" %d", &num);
  return num;
}
