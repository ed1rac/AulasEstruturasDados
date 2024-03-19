#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;    // Array de inteiros
    int length;   // Tamanho atual do array
    int capacity; // Capacidade máxima do array
} Array;

// Função para criar um novo array com capacidade inicial
Array criarArray(int capacity)
{
    Array arr;
    arr.data = (int *)malloc(capacity * sizeof(int));
    arr.length = 0;
    arr.capacity = capacity;
    return arr;
}

// Função para liberar a memória alocada para o array
void liberarArray(Array *arr)
{
    free(arr->data);
    arr->length = 0;
    arr->capacity = 0;
}

// Função para inserir um elemento no final do array
void inserirFim(Array *arr, int elemento)
{
    if (arr->length >= arr->capacity)
    {
        printf("Capacidade do array excedida.\n");
        return;
    }
    arr->data[arr->length++] = elemento;
}

// Função para inserir um elemento no início do array
void inserirInicio(Array *arr, int elemento)
{
    if (arr->length >= arr->capacity)
    {
        printf("Capacidade do array excedida.\n");
        return;
    }
    for (int i = arr->length; i > 0; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[0] = elemento;
    arr->length++;
}

// Função para inserir um elemento em uma posição específica do array
void inserirMeio(Array *arr, int elemento, int posicao)
{
    if (arr->length >= arr->capacity)
    {
        printf("Capacidade do array excedida.\n");
        return;
    }
    if (posicao < 0 || posicao > arr->length)
    {
        printf("Posição inválida.\n");
        return;
    }
    for (int i = arr->length; i > posicao; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[posicao] = elemento;
    arr->length++;
}

// Função para remover um elemento de uma posição específica do array
void remover(Array *arr, int posicao)
{
    if (posicao < 0 || posicao >= arr->length)
    {
        printf("Posição inválida.\n");
        return;
    }
    for (int i = posicao; i < arr->length - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
}

// Função para obter o tamanho atual do array
int tamanho(Array arr)
{
    return arr.length;
}

// Função para exibir os elementos do array
void exibirArray(Array arr)
{
    printf("Array: [");
    for (int i = 0; i < arr.length; i++)
    {
        printf(" %d", arr.data[i]);
    }
    printf(" ]\n");
}

int main()
{
    // Exemplo de uso do TAD Array
    Array arr = criarArray(5);
    inserirFim(&arr, 10);
    inserirFim(&arr, 20);
    inserirInicio(&arr, 5);
    exibirArray(arr);
    inserirMeio(&arr, 15, 2);
    exibirArray(arr); // Array: [ 5 10 15 20 ]
    remover(&arr, 1);
    exibirArray(arr); // Array: [ 5 15 20 ]
    liberarArray(&arr);
    return 0;
}
