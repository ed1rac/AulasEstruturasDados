#include <stdio.h>
float fatorial(int num);
int main()
{
    int i;
    printf("Fatorial Recursivo\n===============\n");
    for (i = 0; i < 20; i++)
    {
        // i = 6;
        printf("O fatorial de %d = %f\n\n", i, fatorial(i));
    }

    return 1;
}

float fatorial(int num)
{
    //  printf("Calculando o fatorial de num = %d\n", num);
    // condição de parada
    if (num == 0)
    {
        // printf("Chegou no caso-base\n");
        return 1;
    }
    else
    {
        // printf("#num = %d\t#(num - 1) = %d\n", num, num - 1);
        return num * fatorial(num - 1);
    }
}