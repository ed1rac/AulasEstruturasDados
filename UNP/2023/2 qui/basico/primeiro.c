// ler um numero e exibir o quadrado desse numero

// tipos de dados b√°sicos da ling. C
//  int, float, double, char
#include <stdio.h>

int main()
{
    // declaraá?o de variaveis
    int numero, quadrado;
    // entrada
    printf("Digite um n£mero: ");
    scanf("%d", &numero);
    // processamento
    quadrado = numero * numero;
    // sa°da
    printf("O quadrado do n£mero Ç: %d", quadrado);
    return 0;
}