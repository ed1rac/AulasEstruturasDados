#include <stdio.h>
#define TAM 10
#define QL printf("\n")
int main()
{
    int i;
    float notas[TAM], media, soma;
    soma = 0;
    // lendo os dados
    for (i = 0; i < TAM; i++)
    {
        printf("Digite a nota do %d§ aluno: ", i + 1);
        scanf(" %f", &notas[i]);
        soma += notas[i]; // soma = soma + notas[i]
    }
    media = soma / TAM;
    printf("\n============================\n");
    // exibindo
    for (i = 0; i < TAM; i++)
    {
        printf("nota[%d] = %.2f", i + 1, notas[i]);
        QL;
    }
    QL;
    printf("A m‚dia das notas ‚: %.2f", media);
    QL;
    return 1;
}