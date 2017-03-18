#include <stdio.h>
#include <stdlib.h>
/*  Função : MDC entre dois números recursivo (Euclides)
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int mdc(int, int);

main(){
    int num1, num2;
    do{
        printf("\nEntre com dois numeros inteiro positivos: ");
        scanf("%d, %d", &num1, &num2);
    }while((num1<=0) || (num2<=0));

    printf("O MDC entre %d e %d eh %d",num1, num2, mdc(num1, num2));
    getchar();
}

int mdc(int x, int y){
    if(y==0)                    /caso b�sico
        return x;
    else if (x<y)
            return mdc(y,x);    //passo de recurs�o
         else
            return mdc(y, x % y);
}
