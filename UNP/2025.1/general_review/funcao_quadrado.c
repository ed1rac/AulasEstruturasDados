#include <stdio.h>

int quadrado(int);

int main()
{
    int num = 5;
    printf("Quadrado de %d é %d\n", num, quadrado(num));
    return 0;
}

int quadrado(int x)
{
    return x * x;
}
