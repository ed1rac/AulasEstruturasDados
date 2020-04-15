/* Função : Programa que gera numeros pseudo aleatorios
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações:
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct lista
{
  int dig;
  struct lista *prox;
  struct lista *prev;
} lista;

lista *R;

int random(int n)
{
  return rand() % n;
}

void inserir_digito(int i)
{
  lista *p,*q;

  p = (lista *)calloc(1,sizeof(lista));
  p->dig = i;
  p->prox = p;
  p->prev = p;
  if (R == NULL)
    R = p;
  else
  {
    q = R->prev;
    R->prev = p;
    p->prev = q;
    q->prox = p;
    p->prox = R;
  }
}

void montar_lista()
{
  int i,d;

  R = NULL;
  printf("Entre com os 10 digitos iniciais: ");
  for (i = 0; i < 10; i++)
  {
    scanf("%d",&d);
    inserir_digito(d);
  }
}

void para_direita()
{
  lista *p;

  p = R;
  do
  {
    p->dig = (p->dig + p->prox->dig) % 10;
    p = p->prox;
  }
  while (p != R);
}

void para_esquerda()
{
  lista *p;

  p = R;
  do
  {
    p->dig = (p->dig + p->prev->dig) % 10;
    p = p->prev;
  }
  while (p != R);
}

int pseudo_aleatorio()
{
  int i,num;
  lista *p;

  num = 0;
  p = R;
  for (i = 0; i < 3; i++)
  {
    num = num*10 + p->dig;
    p = p->prox;
  }
  return num;
}

void gerar_numero()
{
  int i,voltas,sentido;

  voltas = 100;
  sentido = 0;

  for (i = 0; i < voltas; i++)
  {
    // Girar no sentido determinado
    if (sentido == 0)
      para_direita();
    else
      para_esquerda();

    // Inverter o sentido
    sentido = 1 - sentido;
  }
}

void mostrar_lista()
{
  lista *p;

  p = R;
  printf("\nLista: ");
  do
  {
    printf("%d",p->dig);
    p = p->prox;
  }
  while (p != R);
}

int main(int args, char * arg[])
{
  char op;
  int p;

  montar_lista();
  do
  {
    gerar_numero();
    mostrar_lista();
    p = pseudo_aleatorio();
    printf("\nNumero gerado = %d",p);
    printf("\nOutra vez? (S/N): ");
    op = toupper(getche());
  }
  while (op == 'S');
  printf("\n");
  system("pause");
  return 0;
}

