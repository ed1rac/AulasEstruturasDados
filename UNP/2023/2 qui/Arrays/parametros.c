#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main()
{
    int valores[MAX], i;
    printf("O endereco do 1o. elemento: %d\n", valores);
    printf("O endereco do 1o. elemento: %d\n", &valores[0]);
    for (i = 0; i < MAX; i++)
    {
        printf("Endereco do %do. elemento: %d\n", i + 1, &valores[i]);
    }

    return 1;
}