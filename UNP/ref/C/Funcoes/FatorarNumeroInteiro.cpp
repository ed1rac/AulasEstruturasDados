#include <stdio.h>
#include <stdlib.h>
#include <math.h> //para sqrt

int e_primo(int);
int findProxPrimo(int x, int limite);

int main()
{
    int num, num2, limite, proxPrimo;
    do
    {
        printf("\nEntre com um numero inteiro positivo maior que zero: ");
        scanf("%d", &num);
    } while (num < 0);

    printf("\nDecompondo %d em fatores primos:\n\n", num);

    if (e_primo(num))
    {
        printf("\nO numero eh primo!\n");
    }
    else
    {
        limite = num; //(int) sqrt(num);
        proxPrimo = findProxPrimo(1, limite);
        // printf("\nLimite: %d\nproxPrimo=%d\n\n", limite, proxPrimo);
        printf("%d\t|", num);
        while (num != 1)
        {
            while ((num % proxPrimo) == 0)
            {
                printf("\t%d\n", proxPrimo);
                num = (int)(num / proxPrimo);
                printf("%d\t|", num);
            }
            proxPrimo = findProxPrimo(proxPrimo + 1, limite);
        }
    }
    printf("\n\n");
    system("pause");
}

int findProxPrimo(int x, int limite)
{
    if (x <= limite)
        if (e_primo(x))
            return x;
        else
            findProxPrimo(x + 1, limite);
}

int e_primo(int x)
{
    int cont_primo = 0;
    int i;
    for (i = 1; i <= x; i++)
    {
        if ((x % i) == 0)
            cont_primo += 1;
    }
    if (cont_primo == 2)
        return 1; // � primo
    else
        return 0; // nao eh primo
}
