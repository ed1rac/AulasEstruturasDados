#include <stdio.h>
#include <stdlib.h>

// Função : Troca Valor de duas variaveis - sem usar ponteiros
// Autor : Edkallenn
// Data : 06/04/2012
// Observações: O endereco h mostrado apenas  como prova de que realmente as variaveis foram trocadas e nao somente exibidas em ordem contraria.

main()
{
    int var_a, var_b, temp;

    printf("Programa que le, exibe, troca e depois exibe de novo o valor\n");
    printf("de duas variaveis\n");
    printf("\nDigite o valor das variaveis A e B (separados por virgulas):");
    scanf("%d, %d", &var_a, &var_b);

    printf("\nAs variaveis sao: \n");
    printf("A: %d - E o endereco de A eh: %p\n", var_a, &var_a);
    printf("B: %d - E o endereco de B eh: %p\n\n", var_b, &var_b);

    temp = var_a;
    var_a = var_b;
    var_b = temp;

    printf("\nAgora as variaveis sao: \n");
    printf("A: %d - E o endereco de A eh: %p\n", var_a, &var_a);
    printf("B: %d - E o endereco de B eh: %p\n\n", var_b, &var_b);

	system("pause");


}
