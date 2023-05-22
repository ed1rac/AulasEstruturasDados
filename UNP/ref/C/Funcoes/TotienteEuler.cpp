#include <stdio.h>
#include <stdlib.h>
/*  Função : MDC entre dois números recursivo (Euclides)
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int mdc(int, int);
int totiente(int);

main(){
    int i, num1, num2, tot;
    do{
        printf("\nEntre com um numero inteiro positivo: ");
        scanf("%d", &num1);
    }while(num1<=0);

    for(i=1;i<=num1;i++){
        printf("\nA funcao FI(%d) = %d", i, totiente(i));
    }
    printf("\n");
    system("pause");

}

int totiente(int num){
    int soma, i;
    soma = 0;
    for(i=1;i<=num;i++)
        if(mdc(num,i)==1){
            soma+=1;
           // printf("\n%d\n");
        }
    return soma;

}

int mdc(int x, int y){
    if(y==0)
        return x;
    else if (x<y)
            return mdc(y,x);
         else
            return mdc(y, x % y);
}
