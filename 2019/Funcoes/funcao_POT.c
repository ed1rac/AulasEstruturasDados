#include <stdio.h>
#include <stdlib.h>
/* Fun?o pot(m,n) - Autor: Edkallenn - Data: 06/04/2012 */
long pot(int, int);	//prot?ipo da fun?o

int main(){
	int n,p, resultado;
	char c,cm;	
	do{
		printf("Digite um numero inteiro: ");
		scanf("%d",&n);
		printf("Digite a potencia para elevar %d: ", n);
		scanf("%d",&p);
		resultado = pot(n,p);
		printf("O numero %d elevado a %d eh: %d", n,p,resultado);
		printf("\n\nContinua: (S/N)?");
		//c = toupper(getche(c));
		scanf(" %c", &c);
		//cm = toupper(c);
		printf("\n\n");		
	}while((c=='S')||(c=='s'));
}
/*int pot (int x, int n){
	int p;	
	for(p=1;n>0;--n){
		p=p*x;
	}
	return p;
} 
*/
int pot(int x, int n){
	int p,i;
	p=1;
	for(i=1;i<=n;i++){
		p=p*x;
	//	printf("i= %d - p = %d - n = %d\n",i,p,n);
	}
	return p;
}

double pot2(int x, int n){
	double p;
	p = pow(x,n);
	return p;
}










