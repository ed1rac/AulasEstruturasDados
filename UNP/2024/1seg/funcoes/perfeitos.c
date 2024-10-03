#include <stdbool.h>
#include <stdio.h>

// Função para verificar se um número é perfeito
bool eh_numero_perfeito(int n)
{
    int soma = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            soma += i;
        }
    }
    return soma == n;
}

int main()
{

    int num;
    printf("Digite um número inteiro: ");
    scanf(" %d", &num);
    printf("Números perfeitos entre 1 e %d:\n", num);
    for (int i = 1; i <= num; i++)
    {
        if (eh_numero_perfeito(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
