#include <stdio.h>
#include <locale.h>

/*
** Função : Recebe dois parâmetros, x e n , e retorna o resultado da potência fatorial crescente de x elevado a n e, em seguida, a potência fatorial decrescente de x elevado a n.
** Autor : Felipe Nóbrega de Almeida
** Data : 27/03/2024
** Observações:
*/

long long potencia_fatorial_crescente(int x, int n);
long long potencia_fatorial_decrescente(int x, int n);
void escrever_txt(char tipo[30], int x, int n, long long resultado);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int x = 5, n;

    printf(" x | n | fatorial crescente\n");
    for (n = 2; n <= 10; n++)
    {
        long long resultado = potencia_fatorial_crescente(x, n);
        printf(" %d | %d | %lld\n", x, n, resultado);
        escrever_txt("crescente", x, n, resultado);
    }

    printf(" x | n | fatorial decrescente\n");
    for (n = 2; n <= 10; n++)
    {
        long long resultado = potencia_fatorial_decrescente(x, n);
        printf(" %d | %d | %lld\n", x, n, resultado);
        escrever_txt("decrescente", x, n, resultado);
    }

    return 0;
}

long long potencia_fatorial_crescente(int x, int n)
{
    int i;
    long long potencia = x;

    for (i = 1; i < n; i++)
    {
        potencia *= (x + i);
    }

    return potencia;
}

long long potencia_fatorial_decrescente(int x, int n)
{
    int i;
    long long potencia = x;

    for (i = 1; i < n; i++)
    {
        potencia *= (x - i);
    }

    return potencia;
}

void escrever_txt(char tipo[30], int x, int n, long long resultado)
{
    FILE *file = fopen("output/resultados.txt", "a");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo resultados.txt\n");
        return;
    }

    fprintf(file, "x: %d, n: %d, resultado %s: %lld\n", x, n, tipo, resultado);

    fclose(file);
}