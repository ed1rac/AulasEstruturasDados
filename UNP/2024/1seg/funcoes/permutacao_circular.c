#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para verificar se um array é uma permutação circular de outro
int permutacao_circular(int *array1, int *array2, int tamanho)
{
    // Verifica se os arrays são diferentes
    bool sao_diferentes = true;
    for (int i = 0; i < tamanho; i++)
    {
        if (array1[i] != array2[i])
        {
            sao_diferentes = false;
            break;
        }
    }
    if (sao_diferentes)
        return 0; // Se forem iguais, não é uma permutação circular

    // Verifica se é uma permutação circular
    for (int i = 0; i < tamanho; i++)
    {
        bool sao_iguais = true;
        for (int j = 0; j < tamanho; j++)
        {
            if (array1[(i + j) % tamanho] != array2[j])
            {
                sao_iguais = false;
                break;
            }
        }
        if (sao_iguais)
            return 1;
    }
    return 0;
}

int main()
{
    int tamanho = 5;
    int *array1 = malloc(tamanho * sizeof(int));
    int *array2 = malloc(tamanho * sizeof(int));

    // Arrays de teste
    int teste1[] = {1, 2, 3, 4, 5};
    int teste2[] = {3, 4, 5, 1, 2}; // É uma permutação circular de teste1
    int teste3[] = {5, 4, 3, 2, 1}; // Não é uma permutação circular de teste1

    // Copia os valores dos arrays de teste para os arrays alocados dinamicamente
    for (int i = 0; i < tamanho; i++)
    {
        array1[i] = teste1[i];
        array2[i] = teste2[i];
    }

    // Exibe os arrays de teste
    printf("Array 1: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

    // Testa a função
    printf("Resultado do teste 1: %d\n", permutacao_circular(array1, teste2, tamanho)); // Deve retornar 1
    printf("Resultado do teste 2: %d\n", permutacao_circular(array1, teste3, tamanho)); // Deve retornar 0

    free(array1);
    free(array2);

    return 0;
}
