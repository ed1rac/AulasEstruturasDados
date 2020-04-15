#include <stdio.h>
#include <stdlib.h>

int main(){
	int num, cont, i;
	int fatorial;
	printf("Digite um numero: ");
	scanf(" %d", &num);

	fatorial = 1;
	i=1;

	while(i<=num){
		cont =i;		
		while(cont>=1){
			fatorial=fatorial*cont;
			cont--;
		}
		printf("O fatorial de %d = %d\n", i, fatorial);
		
		i++;	
		fatorial=1; 
	}
	getchar();
	return 1;
}