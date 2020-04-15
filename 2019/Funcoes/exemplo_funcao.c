#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao quadrado(x)
    Autor : Edkallenn - Data : 06/04/2012
    Observações: Eleva um numero ao quadrado
*/
int quadrado (int);  //prototipo da funcao

int main(){
    int x;
    for(x = 1;x<=10;x++)
        printf("O quadrado de %3d eh: %d\n", x, quadrado(x));
    printf("\n");
    getch();
    return 0;

}
//definicao da funcao
int quadrado(int a)
{
    return(a * a);
}
