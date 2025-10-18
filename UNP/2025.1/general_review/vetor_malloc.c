#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Quantos números? ");
    scanf(" %d", &n);

    int *vetor;
    vetor = (int *)calloc(n, sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocação!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Números lidos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}
