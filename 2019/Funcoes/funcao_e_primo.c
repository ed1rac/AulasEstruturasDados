#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao e_primo e uso da funcao.
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int e_primo(int);   //prototipo da funcao

main(){
    int num;
    do{
        printf("\nEntre com um numero inteiro positivo: ");
        scanf("%d", &num);
    }while(num<=0);

    int primo = e_primo(num);
    if (primo==1)
        printf("\nO numero %d eh primo\n", num);
    else
        printf("\nO numero %d nao eh primo\n", num);
    getch();
}

e_primo(int x){
    int cont_primo = 0;
    int i;
    for (i = 1;i<=x;i++){
        if ((x%i)==0)
           cont_primo+=1;
    }
    if(cont_primo==2)
        return 1;   //é primo
    else
        return 0;   //nao eh primo
}
