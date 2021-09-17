#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{ //tipo Aluno
  char nome[40];
  int matricula;
  char curso[40];
  float valor_parcela;
} Aluno;

typedef struct lista *link; //link para uma lista igual
typedef struct lista
{ //tipo Lista
  Aluno aluno;
  link prox;
} Lista;

typedef struct pilha
{
  Lista *prim; //aponta para o topo da pilha
} Pilha;

//prototipos
Aluno le_aluno();
Lista *lista_cria();
int pilha_vazia(Pilha *p);
void exibe_aluno(Lista *aluno);
int pilha_vazia(Pilha *p);

Pilha *pilha_cria()
{ //cria uma pilha vazia
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->prim = NULL;
  return p;
}

void pilha_push(Pilha *pilha, Aluno temp)
{
  //cria nova célula na lista
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  //copia os dados para a célula
  strcpy(novo->aluno.nome, temp.nome);
  novo->aluno.matricula = temp.matricula;
  strcpy(novo->aluno.curso, temp.curso);
  novo->aluno.valor_parcela = temp.valor_parcela;
  //encadeia os elementos colocando novo no topo da pilha
  novo->prox = pilha->prim;
  pilha->prim = novo;
}

Aluno pilha_pop(Pilha *pilha)
{
  Lista *t;
  Aluno temp;
  if (pilha_vazia(pilha))
  {
    printf("Pilha Vazia!\n\n");
    exit(1);
  }
  t = pilha->prim;
  temp = t->aluno;
  pilha->prim = t->prox;
  free(t);

  return temp;
}

void pilha_peek(Pilha *pilha)
{
  Aluno temp;
  if (pilha_vazia(pilha))
  {
    printf("Pilha Vazia!\n\n");
    exit(1);
  }
  exibe_aluno(pilha->prim);
}

int pilha_vazia(Pilha *p)
{
  return (p->prim == NULL);
}

Aluno le_aluno()
{
  Aluno temp;
  printf("Digite o nome do aluno...: ");
  scanf(" %40[^\n]", temp.nome);
  printf("Digite a matrícula.......: ");
  scanf(" %d", &temp.matricula);
  printf("Digite o curso...........: ");
  scanf(" %40[^\n]", temp.curso);
  printf("Digite o valor da parcela: ");
  scanf(" %f", &temp.valor_parcela);
  printf("\n");
  return temp;
}

void exibe_aluno(Lista *aluno)
{
  printf("Nome do aluno......: %s\n", aluno->aluno.nome);
  printf("Matricula..........: %d\n", aluno->aluno.matricula);
  printf("Curso..............: %s\n", aluno->aluno.curso);
  printf("Valor da parcela...: %f\n", aluno->aluno.valor_parcela);
  printf("\n");
}
void exibe_conteudo(Aluno aluno)
{
  printf("Nome do aluno......: %s\n", aluno.nome);
  printf("Matricula..........: %d\n", aluno.matricula);
  printf("Curso..............: %s\n", aluno.curso);
  printf("Valor da parcela...: %f\n", aluno.valor_parcela);
  printf("\n");
}

void pilha_imprime(Pilha *pilha)
{
  Lista *p;
  for (p = pilha->prim; p != NULL; p = p->prox)
  {
    printf("Exibindo dados:\n=====================\n");
    printf("\n");
  }
}

int main()
{
  Pilha *p = pilha_cria();
  Aluno aluno;
  pilha_push(p, le_aluno());
  pilha_push(p, le_aluno());
  pilha_push(p, le_aluno());
  pilha_push(p, le_aluno());
  pilha_imprime(p);
  printf("\nUm pop:");
  aluno = pilha_pop(p);
  exibe_conteudo(aluno);
  printf("\nUm pop:");
  aluno = pilha_pop(p);
  exibe_conteudo(aluno);
  pilha_imprime(p);
  return 0;
}