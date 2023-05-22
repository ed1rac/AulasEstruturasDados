#include <stdio.h>
#include <stdlib.h>
/*  Fun��o : MDC entre dois n�meros recursivo (Euclides)
    Autor : Edkallenn  -  Data : 06/04/2012
    Observa��es:
*/
int mdc(int, int);

int main(){
    int num1, num2;
    do{
        printf("\nEntre com dois numeros inteiro positivos: ");
        scanf("%d, %d", &num1, &num2);
    }while((num1<=0) || (num2<=0));

    printf("O MDC entre %d e %d eh %d\n",num1, num2, mdc(num1, num2));
    getchar();
}

int mdc(int x, int y){
    if(y==0)
        return x;
    else if (x<y)
            return mdc(y,x);
         else
            return mdc(y, x % y);
}
