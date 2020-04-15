#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*  Função :
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/
double quadrado (int);  //prototipo da funcao
double cubo(int);

main()
{
    int x;
    printf("\nDigite o valor de x: ");
    scanf("%d", &x);
    printf("\nO valor de %d ao quadrado = %f", x, quadrado(x));
    printf("\nO valor de %d ao cubo = %f", x, cubo(x));
    getch();

}
double quadrado(int a){
    return pow(a,2);
}
double cubo(int merda){
   return pow(merda,3);
}


