#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da lista encadeada
typedef struct No
{
    char *data;
    struct No *next;
} No;

// Estrutura da pilha
typedef struct
{
    No *top;
} Pilha;

// Função para criar uma pilha
Pilha *cria_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->top = NULL;
    }
    return p;
}

// Função para verificar se a pilha está vazia
int esta_vazia(Pilha *p)
{
    return p->top == NULL;
}

// Função para inserir um elemento na pilha
void push(Pilha *p, const char *elemento)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->data = (char *)malloc((strlen(elemento) + 1) * sizeof(char));
        strcpy(novo->data, elemento);
        novo->next = p->top;
        p->top = novo;
    }
    else
    {
        printf("Erro: Memória insuficiente.\n");
    }
}

// Função para remover e retornar o elemento do topo da pilha
char *pop(Pilha *p)
{
    if (esta_vazia(p))
    {
        return NULL;
    }
    else
    {
        No *remover = p->top;
        char *elemento = remover->data;
        p->top = remover->next;
        free(remover);
        return elemento;
    }
}

// Função para liberar a memória alocada pela pilha
void destroi_pilha(Pilha *p)
{
    while (!esta_vazia(p))
    {
        free(pop(p));
    }
    free(p);
}

int main()
{
    // Criação da pilha
    Pilha *pilha = cria_pilha();

    // Operações de push
    push(pilha, "Alice");
    push(pilha, "Bob");
    push(pilha, "Charlie");

    // Operações de pop e exibição dos elementos removidos
    char *elemento = pop(pilha);
    while (elemento != NULL)
    {
        printf("Elemento removido: %s\n", elemento);
        free(elemento); // Liberar a memória do elemento removido
        elemento = pop(pilha);
    }

    // Verificação do estado final da pilha
    if (esta_vazia(pilha))
    {
        printf("A pilha está vazia.\n");
    }
    else
    {
        printf("A pilha não está vazia.\n");
    }

    // Destruição da pilha e liberação de memória
    destroi_pilha(pilha);

    return 0;
}
