#include <stdio.h>
float fatorial(int n);
float combinacao(float n, float p);

int main()
{
    int num1, num2;
    printf("Digite um número: ");
    scanf(" %d", &num1);
    printf("Digite outro número: ");
    scanf(" %d", &num2);

    printf("A combinação(%d, %d) = %f.2 \n", num1, num2, combinacao(num1, num2));

    return 1;
}

float fatorial(int n)
{
    int i;
    float fatorial;
    fatorial = 1;
    for (i = 1; i <= n; i++)
    {
        fatorial = fatorial * i;
    }
    // laço fatorial usando do while
    /*   i = 1;
       do
       {
           fatorial = fatorial * i;
           i++;
       } while (i <= n);
   */
    return fatorial;
}

float combinacao(float n, float p)
{
    return fatorial(n) / (fatorial(p) * fatorial(n - p));
}

// função para calcular arranjo
float arranjo(float n, float p)
{
    return fatorial(n) / fatorial(n - p);
}
