#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Define o tamanho máximo da pilha

typedef struct
{
    char **data; // Array de strings
    int top;     // Índice do topo da pilha
} Pilha;

// Função para criar uma pilha
Pilha *cria_pilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->data = (char **)malloc(MAX * sizeof(char *));
        p->top = -1; // Inicialmente, a pilha está vazia
    }
    return p;
}

// Função para verificar se a pilha está vazia
int esta_vazia(Pilha *p)
{
    return p->top == -1;
}

// Função para inserir um elemento na pilha
void push(Pilha *p, const char *elemento)
{
    if (p->top < MAX - 1)
    {
        p->top++;
        p->data[p->top] = (char *)malloc((strlen(elemento) + 1) * sizeof(char));
        strcpy(p->data[p->top], elemento);
    }
    else
    {
        printf("Erro: A pilha está cheia.\n");
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
        char *elemento = p->data[p->top];
        p->top--;
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
    free(p->data);
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
