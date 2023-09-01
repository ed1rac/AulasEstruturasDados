
// Estrutura de Dados 2 - 2018.1

// -------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// lista encadeada em C usando arrays
// -------------------------------------------------------------------
#define MAX 100
#define NULO -1

typedef int Apontador;
typedef int TipoChave;

typedef struct
{
    TipoChave chave;
    int valor;
} TipoItem;

typedef struct
{
    TipoItem item[MAX];
    Apontador primeiro, ultimo, prox;
} TipoLista;

void FLVazia(TipoLista *lista)
{
    lista->primeiro = NULO;
    lista->ultimo = lista->primeiro;
}

int Vazia(TipoLista lista)
{
    return (lista.primeiro == NULO);
}

void Insere(TipoItem x, TipoLista *lista)
{
    if (lista->ultimo == MAX - 1)
    {
        printf("Lista cheia\n");
        return;
    }
    lista->ultimo++;
    lista->item[lista->ultimo] = x;
}

void Imprime(TipoLista lista)
{
    int i;
    for (i = lista.primeiro; i <= lista.ultimo; i++)
        printf("%d ", lista.item[i].chave);
    printf("\n");
}

int main()
{
    TipoLista lista;
    TipoItem item;
    int i;
    FLVazia(&lista);
    for (i = 0; i < 10; i++)
    {
        item.chave = i;
        Insere(item, &lista);
    }
    Imprime(lista);
    return 0;
}
