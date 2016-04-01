#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao dobro(x)
    Autor : Edkallenn -   Data : 06/04/2019
    Observações: Calcula o dobro de um numero
*/
int dobro (int);  //prototipo da funcao

int main(){
    int x;
    for(x = 1;x<=10;x++){
        printf("O dobro de %3d eh: %d ", x, dobro(x));
        printf("\n");
    }
    getch();
}
//definicao da funcao
int dobro(int a)
{
    return(2 * a);
}

