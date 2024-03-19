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

void showArvore(Arvore *t)
{
    printf("<");
    if (!ArvoreIsEmpty(t))
    {
        printf("%d ", t->num);
        showArvore(t->direita);
        showArvore(t->esquerda);
    }
    printf(">");
}

void insertArvore(Arvore **t, int num)
{
    if (*t == NULL)
    {
        *t = (Arvore *)malloc(sizeof(Arvore));
        (*t)->direita = NULL;
        (*t)->esquerda = NULL;
        (*t)->num = num;
    }
    else
    {
        if (num > (*t)->num)
            insertArvore(&(*t)->direita, num);
        if (num < (*t)->num)
            insertArvore(&(*t)->esquerda, num);
    }
}

int isInArvore(Arvore *t, int num)
{
    if (ArvoreIsEmpty(t))
        return 0;
    return t->num == num || isInArvore(t->direita, num) || isInArvore(t->esquerda, num);
}

int contarNos(Arvore *a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + contarNos(a->esquerda) + contarNos(a->direita);
}

int Verificar_Ordem(Arvore *a)
{
    int vetor_ordenacao[contarNos(a)], i = 0;
    if (a != NULL)
    {
        Verificar_Ordem(a->esquerda);
        vetor_ordenacao[i] = a->num;
        i++;
        Verificar_Ordem(a->direita);
    }
    for (i = 0; i <= (contarNos(a)); i++)
    {
        if (vetor_ordenacao[i] <= vetor_ordenacao[i + 1])
            continue;
        else
            return 1;
    }
    return 0;
}

void pre_ordem(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }
    printf("%d ", tree->num);
    pre_ordem(tree->esquerda);
    pre_ordem(tree->direita);
}

void pos_ordem(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }

    pos_ordem(tree->esquerda);
    pos_ordem(tree->direita);
    printf("%d ", tree->num);
}

void em_ordem(Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }
    em_ordem(tree->esquerda);
    printf("%d ", tree->num);
    em_ordem(tree->direita);
}

void em_nivel(struct Arvore *tree)
{
    if (tree == NULL)
    {
        return;
    }
    // Usamos uma fila simples para percorrer os nós em nível
    struct Arvore *fila[100];
    int cabeca = 0, cauda = 0;
    fila[cauda++] = tree;

    while (cabeca < cauda)
    {
        Arvore *no = fila[cabeca++];
        printf("%d ", no->num);

        if (no->esquerda != NULL)
        {
            fila[cauda++] = no->esquerda;
        }
        if (no->direita != NULL)
        {
            fila[cauda++] = no->direita;
        }
    }
}

void print_tree_helper(Arvore *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    int i;
    // Incrementar a distancia entre os niveis
    space += 4;

    // Imprimir o n� da direita primeiro
    print_tree_helper(root->direita, space);

    // Imprimir espacos antes do n� atual
    printf("\n");
    for (i = 4; i < space; i++)
    {
        printf(" ");
    }

    // Imprimir o valor do n� atual
    printf(" %d\n", root->num);

    // Imprimir o n� da esquerda
    print_tree_helper(root->esquerda, space);
}

void exibe_tree(Arvore *root)
{
    print_tree_helper(root, 0);
}

int main()
{
    Arvore *t = createArvore();
    insertArvore(&t, 5);
    insertArvore(&t, 3);
    insertArvore(&t, 2);
    insertArvore(&t, 4);
    insertArvore(&t, 7);
    insertArvore(&t, 6);
    insertArvore(&t, 8);
    showArvore(t);
    exibe_tree(t);
    printf("\nExibindo a Arvore em ordem\n==================\n");
    em_ordem(t);
    printf("\n");
    printf("\nExibindo a Arvore em Pos-ordem\n==================\n");
    pos_ordem(t);
    printf("\n");
    printf("\nExibindo a Arvore em Pre-ordem\n==================\n");
    pre_ordem(t);
    printf("\n");
    printf("\nExibindo a Arvore em Nivel\n==================\n");
    em_nivel(t);
    printf("\n");
    if (isInArvore(t, 4))
        printf("4 pertence a arvore\n");
    else
        printf("4 nao pertence a arvore\n");
    if (isInArvore(t, 1))
        printf("1 pertence a arvore\n");
    else
        printf("1 nao pertence a arvore\n");

    return 1;
}