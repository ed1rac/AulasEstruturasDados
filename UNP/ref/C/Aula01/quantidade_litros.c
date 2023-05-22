#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declarar as variaveis
    int a, b, aux;
    //entrada de dados
    printf("Digite o valor da variavel A");
    scanf("%d", &a);
    printf("Digite o valor da variavel B");
    scanf("%d", &b);
    printf("O valor de A = %d", a);
    printf("O valor de B = %d", b);
    //processamento
    aux = a;
    a = b;
    b = aux;
    //saida de dados
    printf("O valor de A = %d", a);
    printf("O valor de B = %d", b);

    system("pause");
}
