#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao fatorial recursiva - Autor : Edkallenn
    Data : 27/03/2018 -  Observações: */
double fatorial(int n);
main(){
	int num;
	do{
		printf("\nDigite um numero inteiro positivo:");
		scanf(" %d", &num);
	}while(num<0);
	int i;
	for(i=0;i<=num;i++){
		printf("O fatorial de %d = %f\n", i, fatorial(i));
	}
	getchar();
}
double fatorial(int n){
	if (n==0)
		return 1;
	else
		return n * fatorial(n-1);
}