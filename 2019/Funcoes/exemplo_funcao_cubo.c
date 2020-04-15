#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao quadrado(x)
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: Eleva um numero ao quadrado
*/
int quadrado (int);  //prototipo da funcao
int cubo(int);

int main()
{
    int x;

    for(x = 1;x<=10;x++)
        printf("O quadrado de %3d eh: %d e o cubo eh: %d\n", x, quadrado(x), cubo(x));
    printf("\n");
    getch();
  /*  for(x = 1;x<=10;x++)
        printf("O cubo de %3d eh: %d\n", x, cubo(x));
    return 0;
    getch();*/

}
//definicao da funcao
int quadrado(int a)
{
    return(a * a);
}
int cubo(int a)
{
    return(a * a * a);
}
