#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo Aluno
typedef struct aluno
{
  int matricula;
  char curso[40];
  float valor_parcela;
} Aluno;

//sinônimo do ponteiro para uma lista
typedef struct lista *link;

//Tipo Lista
typedef struct lista
{
  Aluno aluno; //int info
  link prox;
} Lista;

//prototipos
Aluno le_aluno();
Lista *lista_insere(Lista *, Aluno);
Lista *lista_cria();
void lista_imprime(Lista *lista);

int main(void)
{
  Lista *banco_alunos;
  Aluno temp;
  banco_alunos = lista_cria();
  for (int i = 0; i < 3; i++)
  {
    temp = le_aluno();
    banco_alunos = lista_insere(banco_alunos, temp);
  }
  lista_imprime(banco_alunos);
  return 0;
}

Lista *lista_cria()
{
  return NULL;
}

Lista *lista_insere(Lista *lista, Aluno temp)
{

  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->aluno.matricula = temp.matricula;
  strcpy(novo->aluno.curso, temp.curso);
  novo->aluno.valor_parcela = temp.valor_parcela;
  novo->prox = lista;

  return novo;
}

void lista_imprime(Lista *lista)
{
  Lista *p;
  for (p = lista; p != NULL; p = p->prox)
  {
    printf("Digite a matricula.........: %d\n", p->aluno.matricula);
    printf("Digite o curso.............: %s\n", p->aluno.curso);
    printf("Digite o valor da parcela..: %f\n", p->aluno.valor_parcela);
    printf("\n");
  }
}

Aluno le_aluno()
{
  Aluno temp;
  printf("Digite a matricula.........: ");
  scanf(" %d", &temp.matricula);
  printf("Digite o curso.............: ");
  scanf(" %40[^\n]", temp.curso);
  printf("Digite o valor da parcela..: ");
  scanf(" %f", &temp.valor_parcela);
  printf("\n");
  return temp;
}