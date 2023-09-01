#include <stdio.h>
int tamanho(int array[]);
int soma(int array[], int n);
int main()
{
    // soma de um array recursiva
    int array[5] = {1, 2, 3, 4, 5};
    int sum = soma(array, tamanho(array));
    printf("soma = %d\n", sum);
    return 0;
}

int soma(int array[], int n)
{
    if (n == 0)
        return 0;
    else
        return soma(array, n - 1) + array[n - 1];
}
// funcao para calcular o tamanho de um array
int tamanho(int array[])
{
    return (int)sizeof(array) / sizeof(array[0]);
}