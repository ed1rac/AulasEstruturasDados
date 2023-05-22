#include <stdio.h>
#include <stdlib.h>

float fibonacci(int);

int main(){
	   int numero, i;
	   printf("Entre com um inteiro: ");    //entrada de um numero
	   scanf("%d", &numero);
	   for(i = 0;i<=numero;i++){    //mostra fibonacci(n) de 1 até n
	   		   printf("Fibonacci(%3d) - %3g\n", i, fibonacci(i));
	   }
	   system("pause");
	   return 0;
}

float fibonacci(int n){	   //fibonacci recursiva
 	 if(n==0 || n==1)
 	 	return n;
	 else
	 	return fibonacci(n-1) + fibonacci(n-2);
}
