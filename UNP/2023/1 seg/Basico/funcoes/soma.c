#include <stdio.h>
int soma(int, int);
int main()
{
    int x, y;
    x = 13;
    y = 22;
    printf("A soma dos dois é: %d\n", soma(x, y));
    return 1;
}

int soma(int x, int y)
{
    int sum;
    sum = x + y;
    return sum;
    // return x + y;
}