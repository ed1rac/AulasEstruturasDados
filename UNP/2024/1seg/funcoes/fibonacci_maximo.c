#include <stdio.h>
#include <stdlib.h>

int *fibonacci_max(int max)
{
    int n = 2;
    int *fibs = malloc(sizeof(int) * (max + 2));
    fibs[0] = 0;
    fibs[1] = 1;

    while (fibs[n - 1] <= max)
    {
        fibs[n] = fibs[n - 1] + fibs[n - 2];
        n++;
    }

    fibs[n] = -1;
    return fibs;
}

int main()
{
    int max;
    printf("Digite o valor máximo: ");
    scanf("%d", &max);

    int *fibs = fibonacci_max(max);
    int i = 0;

    printf("Sequência de Fibonacci até %d: ", max);
    while (fibs[i] != -1)
    {
        printf("%d ", fibs[i]);
        i++;
    }

    printf("\n");

    free(fibs);
    return 0;
}
