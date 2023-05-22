#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define QL printf("\n")

typedef struct no
{
    int valor;
    struct no *prox;
} no;

typedef struct lista
{
    no *inicio;
    no *fim;
    int tamanho;
} lista;

int random(int n);
void criaLista(lista *l);
void insereLista(lista *l, int valor);
void exibeLista(lista *l);
void exibeListaInversa(no *aux);
void exibeListaInversa2(lista *l);
void menu(lista *l);

int random(int n)
{
    return rand() % n;
}
// cria lista encadeada
void criaLista(lista *l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}
// insere na lista encadeada
void insereLista(lista *l, int valor)
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = NULL;
    if (l->inicio == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->tamanho++;
}
// exibe lista encadeada
void exibeLista(lista *l)
{
    no *aux;
    aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}
// exibe lista encadeada
void exibeListaInversa(no *aux)
{
    if (aux != NULL)
    {
        exibeListaInversa(aux->prox);
        printf("%d ", aux->valor);
    }
}
// exibe lista encadeada
void exibeListaInversa2(lista *l)
{
    exibeListaInversa(l->inicio);
}
// exclui elemento da lista
void excluiElemento(lista *l, int valor)
{
    no *aux, *ant;
    aux = l->inicio;
    ant = NULL;
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            if (ant == NULL)
            {
                l->inicio = aux->prox;
                free(aux);
                aux = l->inicio;
            }
            else
            {
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox;
            }
            l->tamanho--;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }
}

// consultar elemento na lista
int consultaElemento(lista *l, int valor)
{
    no *aux;
    aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

// programa principal
int main()
{
    int i, valor;
    lista l;
    criaLista(&l);
    menu(&l);
    /*   for (i = 0; i < MAX; i++)
       {
           valor = random(100);
           insereLista(&l, valor);
       }
       printf("Lista: ");
       exibeLista(&l);
       QL;
       printf("Lista Inversa: ");
       exibeListaInversa2(&l);
       QL;
       printf("Digite um valor para consultar: ");
       scanf("%d", &valor);
       if (consultaElemento(&l, valor))
       {
           printf("Valor %d encontrado na lista\n", valor);
       }
       else
       {
           printf("Valor %d nao encontrado na lista\n", valor);
       }
       QL;
       printf("Digite um valor para excluir: ");
       scanf("%d", &valor);
       excluiElemento(&l, valor);
       printf("Lista: ");
       exibeLista(&l);
       QL;
       */
    return 0;
}

// função para exibir um menu com as opções de incluir, consultar, exibir e excluir na lista
void menu(lista *l)
{
    int opcao, valor;
    do
    {
        printf("1 - Incluir\n");
        printf("2 - Consultar\n");
        printf("3 - Exibir\n");
        printf("4 - Excluir\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser incluido: ");
            scanf("%d", &valor);
            insereLista(l, valor);
            break;
        case 2:
            printf("Digite o valor a ser consultado: ");
            scanf("%d", &valor);
            if (consultaElemento(l, valor))
            {
                printf("Valor %d encontrado na lista\n", valor);
            }
            else
            {
                printf("Valor %d nao encontrado na lista\n", valor);
            }
            break;
        case 3:
            printf("Lista: ");
            exibeLista(l);
            QL;
            break;
        case 4:
            printf("Digite o valor a ser excluido: ");
            scanf("%d", &valor);
            excluiElemento(l, valor);
            break;
        case 5:
            printf("Saindo do programa\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 5);
}