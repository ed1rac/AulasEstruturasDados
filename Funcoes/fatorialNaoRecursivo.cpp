#include <stdio.h>
#include <stdlib.h>
/*  Função : Funcao combinacao(n,p) - C(n,p) = n!/p!(n-p)!
    Autor : Edkallenn - Data : 06/04/2015
    Observações: Eleva um numero ao quadrado
*/

double fat(int num);
double combinacao(int n, int p);

main(){	
	int n,p;
	printf("\nPrograma que calcula a combinacao ou o binomial\n");
	printf("\nDigite os valores de n e p"); scanf("%d,%d",&n,&p);
	printf("\ncombinacao(%d,%d)=%g\n",n,p,combinacao(n,p));
	getchar();	
}
double fat(int num){
	double fatorial;
	int i;
	fatorial = 1;
	for(i=1;i<=num;i++){
		fatorial=fatorial*i;
	}
	return fatorial;
}
double combinacao(int n, int p){
	double resposta;
	resposta = fat(n)/(fat(p)*fat(n-p));
	return resposta;
	//return fat(n)/(fat(p)*fat(n-p));
}










