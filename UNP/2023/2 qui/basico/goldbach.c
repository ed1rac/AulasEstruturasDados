#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int eh_primo(int num)
{
    int i = 0;
    if (num < 2)
    {
        return false;
    }

    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void encontrar_primos(int num)
{

    int i = 0;
    for (i = 2; i <= num / 2; i++)
    {
        if (eh_primo(i) && eh_primo(num - i))
        {
            printf("%d = %d + %d\n", num, i, num - i);
            break;
        }
    }
}
int main()
{
    int n = 0;
    int num = 0;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    printf("Verificando a Conjectura de Goldbach para os numeros pares entre 2 e %d:\n", n);
    for (num = 2; num <= n; num += 2)
    {
        encontrar_primos(num);
    }
    return 0;
}