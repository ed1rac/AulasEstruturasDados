#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *proximo;
} Lista;

Lista *lista_cria();
Lista *lista_insere(Lista *l1, int elemento);
int lista_vazia(Lista *lista);
void aguarda();
int lista_vazia(Lista *lista);
int lista_busca(Lista *lista, int elemento);
void lista_imprime(Lista *l1);

Lista *lista_cria()
{
    return NULL;
}

Lista *lista_insere(Lista *l1, int elemento)
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->dado = elemento;
    nova->proximo = l1;
    return nova;
}
int lista_vazia(Lista *lista)
{
    return (lista == NULL);
}
void aguarda()
{
    // system("pause");
    system("read -p 'Pressione Enter para continuar...' var");
}

int lista_busca(Lista *lista, int elemento)
{
    if (!lista_vazia(lista))
    {
        Lista *temp;
        for (temp = lista; temp != NULL; temp = temp->proximo)
        {
            if (temp->dado == elemento)
            {
                printf("Elemento %d encontrado!\n", temp->dado);
                aguarda();
                return 1;
            }
        }
        printf("Elemento %d nao encontrado!\n", elemento);
        aguarda();
    }
    return 0;
}

void lista_imprime(Lista *l1)
{
    if (!lista_vazia(l1))
    {
        printf("lista = [ ");
        Lista *temp;
        for (temp = l1; temp != NULL; temp = temp->proximo)
        {
            printf("%d, ", temp->dado);
        }
        printf("\b\b ]\n");
        aguarda();
    }
    else
    {
        printf("A lista está vazia\n");
        aguarda();
    }
}

int main()
{
    Lista *l1 = lista_cria();
    l1 = lista_insere(l1, 5);
    l1 = lista_insere(l1, 13);
    l1 = lista_insere(l1, 22);
    l1 = lista_insere(l1, 45);
    l1 = lista_insere(l1, 33);
    l1 = lista_insere(l1, 43);
    lista_imprime(l1);
}