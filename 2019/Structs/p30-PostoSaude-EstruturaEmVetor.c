// Programa p30.c
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[21];
  int idade;
  float peso, altura;
} pessoa;

pessoa nova_pessoa(){
  pessoa p;

  fflush(stdin);        //limpa buffer de entrada
  printf("Nome ..... ");
  gets(p.nome);
  printf("Idade .... ");
  scanf("%d",&(p.idade));
  printf("Peso ..... ");
  scanf("%f",&(p.peso));
  printf("Altura ... ");
  scanf("%f",&(p.altura));
  return p;
}

int main(){
  int i,n;
  pessoa *cad;

  printf("Numero de pessoas: ");
  scanf("%d", &n);
  cad = (pessoa *)malloc(n*sizeof(pessoa));
  for (i = 0; i < n; i++)  {
    printf("\nPessoa %d:\n",i+1);
    cad[i] = nova_pessoa();
  }
  printf("Cadastro atual:\n");
  printf("\n                Nome  Idade   Peso   Altura");
  printf("\n-------------------------------------------");
  for (i = 0; i < n; i++)
    printf("\n%20s  %5d  %5.1f  %7.2f",
           cad[i].nome,cad[i].idade,cad[i].peso,cad[i].altura);

  printf("\n");
  system("pause");
  return 0;
}

