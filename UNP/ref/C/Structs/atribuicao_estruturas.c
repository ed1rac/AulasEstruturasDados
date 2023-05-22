#include <stdio.h>

typedef struct {
    char nome[80];
    int idade;
}Pessoa;

int main() {

  Pessoa pessoa = {"Edkallenn Lima", 39};
  Pessoa pessoa1;

  printf("Exibindo dados da 1ª variável:\n");
  printf("%s\n%d", pessoa.nome, pessoa.idade);

  pessoa1 = pessoa; //atribuição simples
  
  printf("\n\n");
  
  printf("Exibindo dados da 2ª variável:\n");
  printf("%s\n%d", pessoa1.nome, pessoa1.idade);
  
  return 0;
}