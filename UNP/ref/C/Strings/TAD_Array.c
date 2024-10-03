#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;    // Array de inteiros
    int size;     // Tamanho atual do array
    int capacity; // Capacidade total do array
} Array;

// Função para criar um novo array com capacidade inicial
Array criarArray(int capacity)
{
    Array arr;
    arr.data = (int *)malloc(capacity * sizeof(int));
    arr.size = 0;
    arr.capacity = capacity;
    return arr;
}

// Função para inserir um elemento no final do array
void inserirFim(Array *arr, int elemento)
{
    if (arr->size >= arr->capacity)
    {
        printf("Erro: Array está cheio.\n");
        return;
    }
    arr->data[arr->size++] = elemento;
}

// Função para inserir um elemento no início do array
void inserirInicio(Array *arr, int elemento)
{
    if (arr->size >= arr->capacity)
    {
        printf("Erro: Array está cheio.\n");
        return;
    }
    for (int i = arr->size; i > 0; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = elemento;
    arr->size++;
}

// Função para inserir um elemento em uma posição específica do array
void inserirPosicao(Array *arr, int elemento, int posicao)
{
    if (arr->size >= arr->capacity)
    {
        printf("Erro: Array está cheio.\n");
        return;
    }
    if (posicao < 0 || posicao > arr->size)
    {
        printf("Erro: Posição inválida.\n");
        return;
    }
    for (int i = arr->size; i > posicao; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[posicao] = elemento;
    arr->size++;
}

// Função para excluir um elemento de uma posição específica do array
void excluirPosicao(Array *arr, int posicao)
{
    if (posicao < 0 || posicao >= arr->size)
    {
        printf("Erro: Posição inválida.\n");
        return;
    }
    for (int i = posicao; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Função para obter o tamanho atual do array
int tamanho(Array arr)
{
    return arr.size;
}

// Função para liberar a memória alocada para o array
void liberarArray(Array *arr)
{
    free(arr->data);
    arr->size = 0;
    arr->capacity = 0;
}

int main()
{
    // Exemplo de uso do TAD Array
    Array arr = criarArray(10); // Cria um array com capacidade inicial de 10 elementos

    inserirFim(&arr, 5);        // Insere o elemento 5 no final do array
    inserirInicio(&arr, 3);     // Insere o elemento 3 no início do array
    inserirPosicao(&arr, 7, 1); // Insere o elemento 7 na posição 1 do array
    excluirPosicao(&arr, 1);    // Exclui o elemento na posição 1 do array

    for (int i = 0; i < tamanho(arr); i++)
    {
        printf("%d ", arr.data[i]); // Imprime os elementos do array
    }
    printf("\n");

    liberarArray(&arr); // Libera a memória alocada para o array

    return 0;
}
