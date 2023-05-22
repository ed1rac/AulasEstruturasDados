#include <stdio.h>
int maior3(int, int, int);
int main()
{
    int a, b, c;
    printf("Entre com 3 números: ");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("Maior: %d\n", maior3(a, b, c));
}

int maior3(int x, int y, int z)
{
    int maior;
    maior = x;
    if (y > maior)
        maior = y;
    if (z > maior)
        maior = z;
    return maior;
}