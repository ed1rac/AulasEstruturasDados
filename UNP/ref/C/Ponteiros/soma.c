#include <stdio.h>

void soma(int *, int, int);

int main()
{
    int n1, n2, *num;
    printf("Digite dois n£meros: ");
    scanf(" %d, %d", &n1, &n2);
    soma(&num, n1, n2);
    printf("A soma ‚: %d", num);

    return 0;
}

void soma(int *sum, int num1, int num2)
{
    *sum = num1 + num2;
}