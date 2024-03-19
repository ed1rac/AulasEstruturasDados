#include <stdio.h>
#include <stdlib.h>
// #include "pilha-lista.h"

typedef struct arvore
{
    int num;
    struct arvore *esquerda;
    struct arvore *direita;
} Arvore;

Arvore *createArvore()
{
    return NULL;
}

int ArvoreIsEmpty(Arvore *t)
{
    return t == NULL;
}

void mostrarArvore(Arvore *t)
{

    if (t != NULL)
    {
        printf("Arvore vazia");

        return;
    }
    else
    {

        mostrarArvore(t->esquerda);
        mostrarArvore(t->direita);
        printf("%d", t->num);
        return;
    }
}
