#include <stdio.h>
int main(void)
{
    int vetor[] = {1867, 1947, 2007};
    int *ano;
    ano = &vetor[0];
    ano++;
    printf("Valor: %d ", *ano);
    (*ano)++;
    printf("Valor: %d\n ", *ano);
}