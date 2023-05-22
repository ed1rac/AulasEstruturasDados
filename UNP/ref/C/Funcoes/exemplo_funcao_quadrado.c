#include <stdio.h>
#include <stdlib.h>
/*  Fun��o : Funcao quadrado(x)
    Autor : Edkallenn - Data : 06/04/2012
    Observa��es: Eleva um numero ao quadrado
*/
int quadrado (int);  //prototipo da funcao
int cubo(int);
int main(){
    int x;
    for(x = 1;x<=10;x++)
        printf("O quadrado de %3d eh: %d \n", x, quadrado(x));  //, cubo(x));
    printf("\n");
    getchar();
    return 0;
}
//definicao da funcao
int quadrado(int a)
{
    //int quad;
    //quad = a * a;
    //quad = pow(a,2);
    return(a * a);
    //return quad;
}


int cubo(int a){
    return (a * a * a);
}
