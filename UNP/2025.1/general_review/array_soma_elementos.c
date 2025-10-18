#include <stdio.h>

int soma(int v[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s;
}

int main()
{
    int vetor[] = {1, 2, 3, 4, 5};
    printf("Soma = %d\n", soma(vetor, 5));
    return 0;
}
