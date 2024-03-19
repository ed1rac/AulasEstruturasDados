#include <stdio.h>
#include <stdlib.h>
char *decimalParaBinario(int numero);
int main()
{
    int i;
    printf("TABELA ASCII\n===========================\n");
    printf("simbolo\tDEC\tHEX\tOCTAL\tBIN\n");
    for (i = 0; i < 256; i++)
    {
        if (i == 10)
            printf("\n");
        printf("%c\t%d\t%x\t%o\t%s\n", i, i, i, i, decimalParaBinario(i));
    }
}

char *decimalParaBinario(int numero)
{
    int tamanho = 0;
    int temp = numero;

    // Calcula o tamanho necessário para a string binária
    while (temp > 0)
    {
        tamanho++;
        temp /= 2;
    }

    // Trata o caso do número negativo
    if (numero < 0)
    {
        printf("Erro: Esta função não aceita números negativos.\n");
        return NULL;
    }

    // Aloca memória para a string binária
    char *binario = (char *) malloc((tamanho + 1) * sizeof(char));
    if (binario == NULL)
    {
        printf("Erro: Falha ao alocar memória.\n");
        return NULL;
    }

    // Converte o número decimal para binário
    for (int i = tamanho - 1; i >= 0; i--)
    {
        binario[i] = (numero % 2) + '0'; // Converte o dígito binário para caractere
        numero /= 2;
    }
    binario[tamanho] = '\0'; // Adiciona o caractere nulo ao final da string

    return binario;
}
