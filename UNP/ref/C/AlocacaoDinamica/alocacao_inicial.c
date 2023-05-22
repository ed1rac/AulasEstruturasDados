#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
  printf("Alocação de memória em C\n========================\n");

  int *vetor, i, tamanho;
  printf("Digite o tamanho do array: \n");
  scanf(" %d", &tamanho);
  vetor = (int *)malloc(tamanho * sizeof(int));

  if (vetor == NULL)
  { // verifica se tem espaço, se não tem, sai
    printf("Memória insuficiente");
    exit(1);
  }
  // se teve espaço, continua a execução do programa
  for (i = 0; i < tamanho; i++)
  { // faz a leitura do espaço alocado
    printf("Digite o elemento %d do vetor: ", i + 1);
    scanf(" %d", vetor + i); // referenciando usando aritmética de ponteiros
  }
  printf("O vetor digitado foi:\n");
  for (i = 0; i < tamanho; i++)
  {                                              // exibe o vetor alocado
    printf("vetor[%d] = %d\n", i + 1, vetor[i]); // referenciando usando variável indexada -                                                  //array
  }
  free(vetor); // libera a memória alocada
  getchar();

  return 0;
}