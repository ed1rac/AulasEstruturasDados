#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*  Função : Termo geral da PA
    Autor : Edkallenn
    Data : 06/04/2012
    Observações:
*/
int termogeral(int a1, int n, int r);

main()
{
    int a1, n, r, i;
    printf("\nDigite o valor de a1: ");
    scanf("%d", &a1);
    printf("\nDigite o valor de r: ");
    scanf("%d", &r);
    printf("\nDigite o valor de n: "); scanf("%d", &n);
    printf("O termo geral do valor n digitado eh: %d", termogeral(a1,n,r));

   /* for(i=1;i<=20;i++){
        printf("\n%d\t", termogeral(a1,i,r));
    }*/


    getch();
    return 0;

}

int termogeral(int a1, int n, int r){
    return a1+(n-1)*r;
}
