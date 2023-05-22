#include <stdio.h>
#include <stdlib.h>

// estrutura lista de compras
typedef struct produto
{
    int codigo;
    char descricao[50];
    int quantidade;
    float preco;
    struct produto *prox;
} Produto;
// estrutura no da lista de compras
typedef struct lista
{
    Produto *inicio;
    Produto *fim;
    int tamanho;
} Lista;
// cria lista encadeada
void criaLista(Lista *l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}
// insere na lista encadeada
void insereLista(Lista *l, Produto *novo)
{
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
// verifica se a lista está vazia
int listaVazia(Lista *l)
{
    if (l->inicio == NULL)
        return 1;
    else
        return 0;
}
// exibe lista encadeada
void exibeLista(Lista *l)
{
    // verifica se a lista esta vazia
    if (listaVazia(l))
    {
        printf("Lista vazia!\n");
        return;
    }
    els

    {
        Produto *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("Código: %d\n", aux->codigo);
            printf("Descrição: %s\n", aux->descricao);
            printf("Quantidade: %d\n", aux->quantidade);
            printf("Preço: %.2f\n", aux->preco);
            aux = aux->prox;
        }
    }
}
// le um produto
void leProduto(Produto *p)
{
    printf("Código: ");
    scanf(" %d", &p->codigo);
    printf("Descrição: ");
    scanf(" %50[^\n]", p->descricao);
    printf("Quantidade: ");
    scanf(" %d", &p->quantidade);
    printf("Preço: ");
    scanf(" %f", &p->preco);
}
// consulta um produto
void consultaProduto(Lista *l, int codigo)
{
    // verifica se a lista esta vazia
    if (listaVazia(l))
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        Produto *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->codigo == codigo)
            {
                printf("Código: %d\n", aux->codigo);
                printf("Descrição: %s\n", aux->descricao);
                printf("Quantidade: %d\n", aux->quantidade);
                printf("Preço: %.2f\n", aux->preco);
                return;
            }
            aux = aux->prox;
        }
        printf("Produto não encontrado!\n");
    }
}
// exclui um produto
void excluiProduto(Lista *l, int codigo)
{
    // verifica se a lista esta vazia
    if (listaVazia(l))
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        Produto *aux, *ant;
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->codigo == codigo)
            {
                if (aux == l->inicio)
                {
                    l->inicio = aux->prox;
                    free(aux);
                    l->tamanho--;
                    return;
                }
                else
                {
                    ant->prox = aux->prox;
                    free(aux);
                    l->tamanho--;
                    return;
                }
            }
            ant = aux;
            aux = aux->prox;
        }
        printf("Produto não encontrado!\n");
    }
}
// altera um produto
void alteraProduto(Lista *l, int codigo)
{
    // verifica se a lista esta vazia
    if (listaVazia(l))
    {
        printf("Lista vazia!\n");
        return;
    }
    else
    {
        Produto *aux;
        aux = l->inicio;
        while (aux != NULL)
        {
            if (aux->codigo == codigo)
            {
                /* printf("Código: ");
                 scanf(" %d", &aux->codigo);
                 printf("Descrição: ");
                 scanf("%50[^\n]", aux->descricao);
                 printf("Quantidade: ");
                 scanf(" %d", &aux->quantidade);
                 printf("Preço: ");
                 scanf(" %f", &aux->preco);
                 return;
                 */
                leProduto(aux);
            }
            aux = aux->prox;
        }
        printf("Produto não encontrado!\n");
    }
}
// menu
void menu()
{
    printf("1 - Inserir produto\n");
    printf("2 - Excluir produto\n");
    printf("3 - Alterar produto\n");
    printf("4 - Consultar produto\n");
    printf("5 - Exibir lista\n");
    printf("6 - Sair\n");
}
// programa principal
int main()
{
    Lista lista;
    Produto *novo;
    int opcao, codigo;
    criaLista(&lista);
    do
    {
        menu();
        printf("Opção: ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            novo = (Produto *)malloc(sizeof(Produto));
            leProduto(novo);
            insereLista(&lista, novo);
            break;
        case 2:
            printf("Código: ");
            scanf(" %d", &codigo);
            excluiProduto(&lista, codigo);
            break;
        case 3:
            printf("Código: ");
            scanf(" %d", &codigo);
            alteraProduto(&lista, codigo);
            break;
        case 4:
            printf("Código: ");
            scanf(" %d", &codigo);
            consultaProduto(&lista, codigo);
            break;
        case 5:
            exibeLista(&lista);
            break;
        case 6:
            printf("Fim do programa!\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 6);
    return 0;
}