/* Função : Exemplo de Lista - programa pedidos simples
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações:
*/
#include <stdio.h>
#include <stdlib.h>
/* caso haja problemas com touppeer e getch - retira coment
#include <ctype.h>
#include <conio.h>
*/
typedef struct lista
{
  int cli;
  float val;
  struct lista *prox;
} lista;

lista * plista;

int cliente;
float valor;

char opcao_menu()
{
  system("cls");
  printf(" (I)ncluir pedido\n");
  printf(" (E)xcluir pedido\n");
  printf(" (L)istar pedidos\n");
  printf(" (F)im\n");
  printf("> ");
  return (toupper(getche()));
}

void ler_pedido()
{
  printf("\nNumero do cliente ..... ");
  scanf("%d",&cliente);
  printf("Valor do pedido ...... ");
  scanf("%f",&valor);
}

void incluir_pedido()
{
  lista *p,*q,*r;

  ler_pedido();

  p = (lista *)calloc(1,sizeof(lista));

  p->cli = cliente;
  p->val = valor;
  p->prox = NULL;

  /* Incluir pedido na lista */
  if (plista == NULL)
    plista = p;
  else
  {
    r = NULL;
    q = plista;
    while ((q != NULL) && (q->val > valor))
    {
      r = q;
      q = q->prox;
    }
    if (r == NULL)
      plista = p;
    else
      r->prox = p;
    p->prox = q;
  }
}

void excluir_pedido()
{
  lista *p,*q;

  ler_pedido();

  q = NULL;
  p = plista;
  while ((p != NULL) && ((p->cli != cliente) || (p->val != valor)))
  {
    q = p;
    p = p->prox;
  }
  if (p == NULL)
    printf("Esse pedido nao existe!\n");
  else
  {
    if (q != NULL)
      q->prox = p->prox;
    else
      plista = p->prox;
    free(p);
    printf("Pedido cancelado!\n");
  }
}

void listar_pedidos()
{
  lista *p;

  p = plista;
  printf("\n  Lista de Pedidos\n");
  printf("--------+-----------\n");
  printf("CLIENTE |   VALOR   \n");
  printf("--------+-----------\n");
  while (p != NULL)
  {
    printf("  %04d  | %10.2f\n",p->cli,p->val);
    p = p->prox;
  }
}

int main(int args, char * arg[])
{
  char op;

  plista = NULL;

  do
  {
    op = opcao_menu();
    switch (op)
    {
      case 'I': incluir_pedido(); break;
      case 'E': excluir_pedido(); break;
      case 'L': listar_pedidos(); break;
    }
    printf("\n");
    system("pause");
  }
  while (op != 'F');
  return 0;
}
