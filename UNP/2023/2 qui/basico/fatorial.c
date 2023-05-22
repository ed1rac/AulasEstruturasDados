#include <stdio.h>
float fatorial(int);
int main()
{
    int num, i;
    do
    {
        printf("Digite um número positivo: ");
        scanf(" %d", &num);
    } while (num < 0);
    for (i = 1; i <= num; i++)
    {
        printf("O fatorial de %d é %f\n", i, fatorial(i));
    }
    return 0;
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
    return fatorial;
}
