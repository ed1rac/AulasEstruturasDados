#include <stdio.h>
int le_int(char mensagem[]);
void exibe_aprovacao(float media);
const int N = 3;
int main(void) {

  //  int quant = le_int("Quantas notas serão lidas: ");
  int notas[N];
  int soma = 0;

  for (int i = 0; i < N; i++) {
    notas[i] = le_int("Digite a nota: ");
    soma += notas[i]; // soma = soma + notas[i];
  }
  float media = soma / (float)N;
  printf("Sua média foi: %f\n", media);

  exibe_aprovacao(media);

  return 666;
}

int le_int(char mensagem[]) {
  int num;
  printf("%s\n", mensagem);
  scanf(" %d", &num);
  return num;
}

void exibe_aprovacao(float media) {
  if (media >= 70) {
    printf("Você foi aprovado com média %f\n", media);
  } else {
    if (media > 40) {
      printf("Você está na final por %f\n", 100 - media);
    } else {
      printf("Você está reprovado");
    }
  }
}