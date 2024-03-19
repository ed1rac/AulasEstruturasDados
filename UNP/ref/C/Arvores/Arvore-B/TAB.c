#include <stdio.h>
#include <stdlib.h>
#include "TAB.h"

void iNP(TAB *main, TAB *pagina, int num)
{ //	Insere na Página
  int i = main->n_chaves;
  int nAP = (i > 0); //	nAP: Não Achou Posição
  while (nAP)
  {
    if (num >= main->chaves[i - 1])
    {
      nAP = 0;
      break;
    }
    main->chaves[i] = main->chaves[i - 1];
    main->filhos[i + 1] = main->filhos[i];
    i--;
    if (i < 1)
      nAP = 0;
  }
  main->chaves[i] = num;
  main->filhos[i + 1] = pagina;
  main->n_chaves++;
}

void efetuaInsercao(TAB **main, TAB **pagina, int *valida, int *nI, int num, int ordem)
{ //	nI: Número Inserido
  if (!(*main))
  {
    *valida = 1;
    *nI = num;
    *pagina = NULL;
  }
  else
  {
    int i = 1;
    while ((i < (*main)->n_chaves) && (num > (*main)->chaves[i - 1]))
      i++;
    if (num == (*main)->chaves[i - 1])
    {
      printf("Erro: Chave ja inserida\n");
      *valida = 0;
    }
    else
    {
      if (num < (*main)->chaves[i - 1])
        i--;
      efetuaInsercao(&((*main)->filhos[i]), pagina, valida, nI, num, ordem); //	verifica se tem ou não filhos
      if (*valida)
      {
        if ((*main)->n_chaves < (2 * ordem))
        { //  Página tem espaço
          iNP(*main, *pagina, *nI);
          *valida = 0;
        }
        else
        { //  Overflow: Página tem que ser dividida
          TAB *temp = novaPagina(ordem);
          if (i < ordem + 1)
          {
            iNP(temp, (*main)->filhos[2 * ordem], (*main)->chaves[(2 * ordem) - 1]);
            (*main)->n_chaves--;
            iNP((*main), *pagina, *nI);
          }
          else
            iNP(temp, *pagina, *nI);
          int j;
          for (j = ordem + 2; j <= (2 * ordem); j++)
            iNP(temp, (*main)->filhos[j], (*main)->chaves[j - 1]);
          (*main)->n_chaves = ordem;
          temp->filhos[0] = temp->filhos[ordem + 1];
          *nI = (*main)->chaves[ordem];
          *pagina = temp;
        }
      }
    }
  }
}

void insercao(TAB **main, int num, int ordem)
{
  int *valida, nI;
  TAB *pagina;
  efetuaInsercao((&(*main)), &pagina, &valida, &nI, num, ordem);
  if (valida)
  { //	Arvore cresce na altura pela raiz
    TAB *temp = novaPagina(ordem);
    temp->n_chaves = 1;
    temp->chaves[0] = nI;
    temp->filhos[1] = pagina;
    temp->filhos[0] = *main;
    *main = temp;
  }
}

TAB *novaPagina(int ordem)
{
  TAB *temp = (TAB *)malloc(sizeof(TAB));
  temp->n_chaves = 0;
  temp->chaves = (int *)malloc(sizeof(int) * (2 * ordem));
  temp->filhos = (TAB **)malloc(sizeof(TAB) * ((2 * ordem) + 1));
  int i;
  for (i = 0; i <= (2 * ordem); i++)
    temp->filhos[i] = NULL;
  return temp;
}

void reconstitui(TAB **main, TAB *pai, int *valida, int indexP, int ordem)
{ //	indexP: Índice do pai

  TAB *temp;
  int aux, j;

  if (indexP < pai->n_chaves)
  { //	temp: Pagina a direita de main
    temp = pai->filhos[indexP + 1];
    aux = (temp->n_chaves - ordem + 1) / 2;
    (*main)->chaves[(*main)->n_chaves] = pai->chaves[indexP];
    (*main)->filhos[(*main)->n_chaves + 1] = temp->filhos[0];
    (*main)->n_chaves++;
    if (aux > 0)
    { //	Existe folga: transfere de temp para main
      for (j = 1; j < aux; j++)
        iNP(*main, temp->filhos[j], temp->chaves[j - 1]);
      pai->chaves[indexP] = temp->chaves[aux - 1];
      temp->n_chaves -= aux;
      for (j = 0; j < temp->n_chaves; j++)
        temp->chaves[j] = temp->chaves[j + aux];
      for (j = 0; j <= temp->n_chaves; j++)
        temp->filhos[j] = temp->filhos[j + aux];
      *valida = 0;
    }
    else
    { //	Fusao: intercala temp em main e libera temp
      for (j = 1; j <= ordem; j++)
        iNP(*main, temp->filhos[j], temp->chaves[j - 1]);
      free(temp);
      for (j = indexP + 1; j < pai->n_chaves; j++)
      {
        pai->chaves[j - 1] = pai->chaves[j];
        pai->filhos[j] = pai->filhos[j + 1];
      }
      pai->n_chaves--;
      if (pai->n_chaves >= ordem)
        *valida = 0;
    }
  }
  else
  { //	temp = Pagina a esquerda de main
    temp = pai->filhos[indexP - 1];
    aux = (temp->n_chaves - ordem + 1) / 2;
    for (j = (*main)->n_chaves; j >= 1; j--)
      (*main)->chaves[j] = (*main)->chaves[j - 1];
    (*main)->chaves[0] = pai->chaves[indexP - 1];
    for (j = (*main)->n_chaves; j >= 0; j--)
      (*main)->filhos[j + 1] = (*main)->filhos[j];
    (*main)->n_chaves++;
    if (aux > 0)
    { //	Existe folga: transfere de temp para main
      for (j = 1; j < aux; j++)
        iNP(*main, temp->filhos[temp->n_chaves - j + 1], temp->chaves[temp->n_chaves - j]);
      (*main)->filhos[0] = temp->filhos[temp->n_chaves - aux + 1];
      pai->chaves[indexP - 1] = temp->chaves[temp->n_chaves - aux];
      temp->n_chaves -= aux;
      *valida = 0;
    }
    else
    { //	Fusao: intercala main em temp e libera main
      for (j = 1; j <= ordem; j++)
        iNP(temp, (*main)->filhos[j], (*main)->chaves[j - 1]);
      free(*main);
      pai->n_chaves--;
      if (pai->n_chaves >= ordem)
        *valida = 0;
    }
  }
}

void antecessor(TAB *main, TAB *pai, int *valida, int indice, int ordem)
{
  if (pai->filhos[pai->n_chaves])
  {
    antecessor(main, pai->filhos[pai->n_chaves], valida, indice, ordem);
    if (*valida)
      reconstitui(&(pai->filhos[pai->n_chaves]), pai, valida, pai->n_chaves, ordem);
  }
  else
  {
    main->chaves[indice - 1] = pai->chaves[pai->n_chaves - 1];
    pai->n_chaves--;
    *valida = (pai->n_chaves < ordem);
  }
}

void efetuaRemocao(TAB **main, int *valida, int num, int ordem)
{
  int i = 1, j;

  if (!(*main))
  {
    printf("Erro: registro nao esta na arvore\n");
    *valida = 0;
  }
  else
  {
    TAB *temp = *main;
    while ((i < temp->n_chaves) && (num > temp->chaves[i - 1]))
      i++;
    if (num == temp->chaves[i - 1])
    {
      if (!(temp->filhos[i - 1]))
      { //	Pagina folha
        temp->n_chaves--;
        *valida = (temp->n_chaves < ordem);
        for (j = i; j <= temp->n_chaves; j++)
        {
          temp->chaves[j - 1] = temp->chaves[j];
          temp->filhos[j] = temp->filhos[j + 1];
        }
      }
      else
      {
        /* Pagina nao e folha: trocar com antecessor */
        antecessor(*main, temp->filhos[i - 1], valida, i, ordem);
        if (*valida)
          reconstitui(&(temp->filhos[i - 1]), *main, valida, i - 1, ordem);
      }
    }
    else
    {
      if (num > temp->chaves[i - 1])
        i++;
      efetuaRemocao(&(temp->filhos[i - 1]), valida, num, ordem);
      if (*valida)
        reconstitui(&(temp->filhos[i - 1]), *main, valida, i - 1, ordem);
    }
  }
}

void remocao(TAB **main, int num, int ordem)
{
  int *valida;
  efetuaRemocao((&(*main)), &valida, num, ordem);

  if (valida && (*main)->n_chaves == 0)
  { //	Arvore diminui na altura
    TAB *temp = *main;
    *main = temp->filhos[0];
    free(temp);
  }
}

TAB *busca(TAB *main, int num)
{
  if (!main)
    return NULL;
  else
  {
    int i = 1;
    while (i < main->n_chaves && num > main->chaves[i - 1])
      i++;
    if (num == main->chaves[i - 1])
    {
      return main;
    }
    else
    {
      if (num < main->chaves[i - 1])
        return busca(main->filhos[i - 1], num);
      else
        return busca(main->filhos[i], num);
    }
  }
}

void imprimir(TAB *main, int altura)
{
  if (main)
  {
    int i, j;
    for (i = 0; i <= main->n_chaves - 1; i++)
    {
      imprimir(main->filhos[i], altura + 1);
      for (j = 0; j <= altura; j++)
        printf("\t");
      printf("%d\n", main->chaves[i]);
    }
    imprimir(main->filhos[i], altura + 1);
  }
}