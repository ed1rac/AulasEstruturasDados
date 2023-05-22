#include <stdio.h>
#define TAM 100
int main()
{
    int i, n, fibonacci[TAM];
    printf("Digite até qual número de fibonacci vc deseja exibir: ");
    scanf(" %d", &n);
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (i = 2; i < n; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    // exibindo
    for (int i = 0; i < n; i++)
    {
        printf("fibonacci[%d] = %d\n", i, fibonacci[i]);
    }
    return 1;
}