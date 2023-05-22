#include <stdio.h>
#include <stdlib.h>
/*  Função : MDC entre dois números recursivo (Euclides)
    Autor : Edkallenn  -  Data : 06/04/2012
    Observações:
*/
int e_primo(int);
int findProxPrimo(int x);

main(){
    int num, num2, result, prox_primo, limite;
    do{
        printf("\nEntre com um numero inteiro positivo maior que zero: ");
        scanf("%d", &num);
    }while(num<0);
    printf("Numeros Primos ate %d\n\n", num);


	prox_primo=findProxPrimo(2);
 /*   for(int i=2;i<=num;i++)
        if(e_primo(i))
           printf("\t%d\t", i);

    prox_primo=findProxPrimo(2);
    printf("\n%d\n", prox_primo);
    prox_primo=findProxPrimo(prox_primo+1);
    printf("\n%d\n", prox_primo);
    prox_primo=findProxPrimo(prox_primo+1);
    printf("\n%d\n", prox_primo);
    prox_primo=findProxPrimo(prox_primo+1);
    printf("\n%d\n", prox_primo);
    prox_primo=findProxPrimo(prox_primo+1);
    printf("\n%d\n", prox_primo);
 */   
    limite=num;
    while(prox_primo<=limite){
        printf("\t%d\n", prox_primo);
        prox_primo=findProxPrimo(prox_primo+1);
    }

    printf("\n\n\n");
    system("pause");
}


int findProxPrimo(int x){
    if(e_primo(x))
		  return x;
    else
		  return findProxPrimo(x+1);
}

int e_primo(int x){
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
