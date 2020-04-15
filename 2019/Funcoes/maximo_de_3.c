#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao maiordetres(x, y, z)
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: Devolve o maior de 3 inteiros
*/
int maiordetres(int, int, int);  //prototipo da funcao

int main()
{
    int a,b,c;

    printf("Entre com 3 inteiros ( separados por virgulas - a, b, c): ");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("O maior eh: %d\n", maiordetres(a,b,c) );
    getchar();
    return 0;
}
//definicao da funcao
int maiordetres(int x, int y, int z)
{
    int max = x;
    if (y>max)
        max = y;

    if(z>max)
        max = z;

    return max;
}
