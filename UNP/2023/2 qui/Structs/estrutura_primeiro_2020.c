#include <stdio.h>
#include <string.h>
#define QL printf("\n");
// estruturas de dados heterogêneas
struct cadastro
{ // definição da estrutura
  // campos da estrutura (ou membros do registro)
  char nome[80];
  int idade;
  char endereco[80];
  int numero;
};
int main()
{
  // tipo nome_variável
  struct cadastro pessoa; // declarei a variável pessoa do
                          // tipo 'struct cadastro'
  // nomenclatura para acessar os campos de uma variável do tipo estrutura:
  // nome-variável.campo = valor;
  strcpy(pessoa.nome, "Janaína Souza");
  pessoa.idade = 28;
  strcpy(pessoa.endereco, "Rua dos Prazeres, 26 - Boca do Acre");
  pessoa.numero = 69;

  printf("Nome........: %s", pessoa.nome);
  QL;
  printf("Idade.......: %d", pessoa.idade);
  QL;
  printf("Endereço....: %s", pessoa.endereco);
  QL;
  printf("Número......: %d", pessoa.numero);
  QL;
  return 0;
}