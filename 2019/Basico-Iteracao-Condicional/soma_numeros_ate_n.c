#include <stdio.h>
#include <stdlib.h>

int main(){
	int contador; //variável contadora do laço
	int soma; //variável acumuladora
	int numero;
	soma = 0;
	contador = 1;
	printf("Digite um número: ");
	scanf(" %d", &numero);
	while(contador<=numero){
		soma = soma + contador;
		//printf("%d\t%d\n", contador, soma);
		contador++;
	}
	printf("O somatório de 1 até %d é %d\n", numero, soma);
    getchar();
    //system("pause");
    return 1;
}
