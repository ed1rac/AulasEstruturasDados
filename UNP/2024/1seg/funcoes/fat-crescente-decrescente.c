#include <stdio.h>

// Função para calcular a potência fatorial crescente
int potencia_fatorial_crescente(int x, int n)
{
    int resultado = 1;
    for (int i = 1; i <= n; i++)
    {
        resultado *= (x + i - 1);
    }
    return resultado;
}

// Função para calcular a potência fatorial decrescente
int potencia_fatorial_decrescente(int x, int n)
{
    int resultado = 1;
    for (int i = n; i > 0; i--)
    {
        resultado *= (x - i + 1);
    }
    return resultado;
}

int main()
{
    int x = 3;
    int n = 5;

    int resultado_crescente = potencia_fatorial_crescente(x, n);
    int resultado_decrescente = potencia_fatorial_decrescente(x, n);

    printf("A potência fatorial crescente de %d^%d = %d\n", x, n, resultado_crescente);
    printf("A potência fatorial decrescente de %d_%d = %d\n", x, n, resultado_decrescente);

    return 0;
}
