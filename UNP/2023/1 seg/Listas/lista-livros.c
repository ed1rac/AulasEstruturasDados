#include <stdio.h>
#include <stdlib.h>

// estrutura livro
typedef struct livro
{
    int codigo;
    char titulo[50];
    char autor[50];
    char editora[50];
    int ano;
    int edicao;
    int paginas;
    struct livro *prox;
} Livro;

// estrutura lista
typedef struct lista
{
    Livro *inicio;
    Livro *fim;
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
void insereLista(Lista *l, Livro *novo)
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
// exibe lista encadeada
void exibeLista(Lista *l)
{
    Livro *aux;
    aux = l->inicio;
    while (aux != NULL)
    {
        printf("Código: %d\n", aux->codigo);
        printf("Título: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Editora: %s\n", aux->editora);
        printf("Ano: %d\n", aux->ano);
        printf("Edição: %d\n", aux->edicao);
        printf("Páginas: %d\n", aux->paginas);
        printf("====================================\n");
        aux = aux->prox;
    }
}
// exibe lista encadeada inversa
void exibeListaInversa(Livro *aux)
{
    if (aux != NULL)
    {
        exibeListaInversa(aux->prox);
        printf("Código: %d\n", aux->codigo);
        printf("Título: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Editora: %s\n", aux->editora);
        printf("Ano: %d\n", aux->ano);
        printf("Edição: %d\n", aux->edicao);
        printf("Páginas: %d\n", aux->paginas);
        printf("====================================\n");
    }
}
// le um livro
void leLivro(Livro *l)
{
    printf("Código: ");
    scanf(" %d", &l->codigo);
    printf("Título: ");
    scanf(" %50[^\n]", l->titulo);
    printf("Autor: ");
    scanf(" %50[^\n]", l->autor);
    printf("Editora: ");
    scanf(" %50[^\n]", l->editora);
    printf("Ano: ");
    scanf(" %d", &l->ano);
    printf("Edição: ");
    scanf(" %d", &l->edicao);
    printf("Páginas: ");
    scanf(" %d", &l->paginas);
}
// excluir um livro
void excluiLivro(Lista *l, int codigo)
{
    Livro *aux, *ant;
    aux = l->inicio;
    while (aux != NULL && aux->codigo != codigo)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        if (aux == l->inicio)
        {
            l->inicio = aux->prox;
        }
        else
        {
            ant->prox = aux->prox;
        }
        if (aux == l->fim)
        {
            l->fim = ant;
        }
        free(aux);
        l->tamanho--;
    }
}
// consultar um livro
void consultaLivro(Lista *l, int codigo)
{
    Livro *aux;
    aux = l->inicio;
    while (aux != NULL && aux->codigo != codigo)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        printf("Código: %d\n", aux->codigo);
        printf("Título: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Editora: %s\n", aux->editora);
        printf("Ano: %d\n", aux->ano);
        printf("Edição: %d\n", aux->edicao);
        printf("Páginas: %d\n", aux->paginas);
        printf("====================================\n");
    }
}
// alterar um livro
void alteraLivro(Lista *l, int codigo)
{
    Livro *aux;
    aux = l->inicio;
    while (aux != NULL && aux->codigo != codigo)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        printf("Código: ");
        scanf("%d", &aux->codigo);
        printf("Título: ");
        scanf("%s", aux->titulo);
        printf("Autor: ");
        scanf("%s", aux->autor);
        printf("Editora: ");
        scanf("%s", aux->editora);
        printf("Ano: ");
        scanf("%d", &aux->ano);
        printf("Edição: ");
        scanf("%d", &aux->edicao);
        printf("Páginas: ");
        scanf("%d", &aux->paginas);
    }
}
// menu com as opcoes e chamada das funcoes
int main()
{
    Lista l;
    Livro *novo;
    int opcao, codigo;
    criaLista(&l);
    do
    {
        printf("1 - Inserir livro\n");
        printf("2 - Excluir livro\n");
        printf("3 - Consultar livro\n");
        printf("4 - Alterar livro\n");
        printf("5 - Exibir lista\n");
        printf("6 - Exibir lista inversa\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            novo = (Livro *)malloc(sizeof(Livro));
            leLivro(novo);
            novo->prox = NULL;
            insereLista(&l, novo);
            break;
        case 2:
            printf("Código: ");
            scanf("%d", &codigo);
            excluiLivro(&l, codigo);
            break;
        case 3:
            printf("Código: ");
            scanf("%d", &codigo);
            consultaLivro(&l, codigo);
            break;
        case 4:
            printf("Código: ");
            scanf("%d", &codigo);
            alteraLivro(&l, codigo);
            break;
        case 5:
            exibeLista(&l);
            break;
        case 6:
            exibeListaInversa(l.inicio);
            break;
        }
    } while (opcao != 0);
    return 0;
}
