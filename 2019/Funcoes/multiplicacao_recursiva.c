#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao mult recursiva - Autor : Edkallenn
    Data : 27/03/2018 -  Observações: */
double mult(int n, int m);
main(){
	int num1, num2, res;
	printf("\nDigite um numero inteiro positivo:");
	scanf(" %d", &num1);
    printf("\nDigite um numero inteiro positivo:");
	scanf(" %d", &num2);
    res = mult(num1,num2);
    printf("%d * %d = %d\n", num1, num2, res);
	getchar();
}
double mult(int n, int m){
	if (m==1)
		return n;
	else{
        //printf("n = %d e m = %d\n", n,m);
		return n + mult(n, m-1);
    }
}