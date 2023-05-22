#include <stdio.h>
#define QL printf("\n")
int main()
{
    int numeros[20];
    printf("O tamanho do vetor n£meros ‚: %d", sizeof(numeros));
    QL;
    printf("O endere‡o do primeiro elemento ‚: %d", &numeros[0]);
    QL;
    printf("O endere‡o do primeiro elemento ‚: %d", &numeros[1]);
    QL;
    printf("O endere‡o do primeiro elemento ‚: %d", &numeros[2]);
    QL;
    printf("O endere‡o do array n£meros: %d", numeros);
    return 1;
}