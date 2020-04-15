#include <stdio.h>
#include <stdlib.h>
/*  Função : MDC entre dois números recursivo (Euclides)
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int mdc(int, int);
int primosEntreSi(int num1, int num2);

main(){
    int i, num1, num2;
    do{
        printf("\nEntre com dois numeros inteiros positivos: ");
        scanf("%d, %d", &num1, &num2);
    }while((num1<=0) || (num2<=0));

    if(primosEntreSi(num1, num2))
        printf("\n\n%d e %d sao primos entre si.\n\n", num1, num2);
    else
        printf("\n\n%d e %d nao sao primos entre si.\n\n", num1, num2);
    printf("\n");
    system("pause");
}

int primosEntreSi(int num1, int num2){
    if(mdc(num1,num2)==1)
        return 1;
    else
        return 0;
}

int mdc(int x, int y){
    if(y==0)
        return x;
    else if (x<y)
            return mdc(y,x);
         else
            return mdc(y, x % y);
}
