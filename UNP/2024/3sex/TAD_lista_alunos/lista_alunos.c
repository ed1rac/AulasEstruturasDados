#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Aluno
typedef struct
{
    char nome[50];
    int idade;
    char curso[50];
} Aluno;

// Definição do TAD ListaDinamica para manipulação de alunos
typedef struct No
{
    Aluno aluno;
    struct No *prox;
} No;

typedef struct
{
    No *inicio;
} ListaDinamica;

// Função para inicializar a lista dinâmica
void inicializarLista(ListaDinamica *lista)
{
    lista->inicio = NULL;
}

// Função para adicionar um aluno à lista
void adicionarAluno(ListaDinamica *lista, Aluno aluno)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro: falha ao alocar memória.\n");
        return;
    }
    novoNo->aluno = aluno;
    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;
}

// Função para remover um aluno da lista
void removerAluno(ListaDinamica *lista, char *nome)
{
    No *atual = lista->inicio;
    No *anterior = NULL;
    while (atual != NULL && strcmp(atual->aluno.nome, nome) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        printf("Aluno não encontrado.\n");
        return;
    }
    if (anterior == NULL)
    {
        lista->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }
    free(atual);
}

// Função para exibir todos os alunos da lista
void exibirAlunos(ListaDinamica *lista)
{
    No *atual = lista->inicio;
    while (atual != NULL)
    {
        printf("Nome: %s, Idade: %d, Curso: %s\n", atual->aluno.nome, atual->aluno.idade, atual->aluno.curso);
        atual = atual->prox;
    }
}

int main()
{
    ListaDinamica lista;
    inicializarLista(&lista);

    // Adicionando alguns alunos à lista
    Aluno aluno1 = {"Joao", 20, "Engenharia"};
    Aluno aluno2 = {"Maria", 21, "Ciencia da Computacao"};
    Aluno aluno3 = {"Pedro", 22, "Matematica"};

    adicionarAluno(&lista, aluno1);
    adicionarAluno(&lista, aluno2);
    adicionarAluno(&lista, aluno3);

    // Exibindo os alunos
    printf("Alunos cadastrados:\n");
    exibirAlunos(&lista);

    // Removendo um aluno
    printf("\nRemovendo o aluno Joao:\n");
    removerAluno(&lista, "Joao");

    // Exibindo os alunos novamente após a remoção
    printf("\nAlunos cadastrados após a remocao:\n");
    exibirAlunos(&lista);

    return 0;
}
