#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} No;

No *inserir_inicio(No *lista, int valor)
{
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void imprimir(No *lista)
{
    printf("Lista: ");
    while (lista != NULL)
    {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

void liberar(No *lista)
{
    No *temp;
    while (lista != NULL)
    {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

int main()
{
    No *lista = NULL;
    lista = inserir_inicio(lista, 10);
    lista = inserir_inicio(lista, 20);
    lista = inserir_inicio(lista, 30);
    imprimir(lista);
    liberar(lista);
    return 0;
}
