#include <stdio.h>

// Função para calcular a potência fatorial crescente
int potencia_fatorial_crescente(int x, int n)
{
    int resultado = 1;
    printf("Calculando potência fatorial crescente de %d^%d:\n", x, n);
    for (int i = 1; i <= n; i++)
    {
        int valor_atual = (x + i - 1);
        printf("Passo %d: %d * %d = %d\n", i, resultado, valor_atual, resultado * valor_atual);
        resultado *= valor_atual;
    }
    printf("Resultado final: %d\n", resultado);
    return resultado;
}

// Função para calcular a potência fatorial decrescente
int potencia_fatorial_decrescente(int x, int n)
{
    int resultado = 1;
    printf("Calculando potência fatorial decrescente de %d_%d:\n", x, n);
    for (int i = n; i > 0; i--)
    {
        int valor_atual = (x - i + 1);
        printf("Passo %d: %d * %d = %d\n", n - i + 1, resultado, valor_atual, resultado * valor_atual);
        resultado *= valor_atual;
    }
    printf("Resultado final: %d\n", resultado);
    return resultado;
}

int main()
{
    int x = 5;
    int n = 3;

    int resultado_crescente = potencia_fatorial_crescente(x, n);
    int resultado_decrescente = potencia_fatorial_decrescente(x, n);

    printf("A potência fatorial crescente de %d^%d é %d\n", x, n, resultado_crescente);
    printf("A potência fatorial decrescente de %d_%d é %d\n", x, n, resultado_decrescente);

    return 0;
}
