#include <stdio.h>
#include <stdlib.h>

float fibonacci(int);

int main(){
	   int numero, i;

	   printf("Entre com um inteiro: ");
	   scanf("%d", &numero);
	   for(i = 1;i<=numero;i++)
	   		   printf("Fibonacci(%3d) - %3g\n", i, fibonacci(i));

	   system("read a");
	   return 0;

}

float fibonacci(int n)	   //fibonacci recursiva
{
 	 if(n==0 || n==1)
 	 	return n;
	 else
	 	return fibonacci(n-1) + fibonacci(n-2);
}
