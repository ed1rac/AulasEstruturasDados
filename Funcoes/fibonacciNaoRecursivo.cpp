#include <stdio.h>
#include <stdlib.h>

double fibonacci(long);

main(){

	   long resultado, num;

	   printf("Entre com um inteiro: ");
	   scanf("%ld", &num);
	   for (int i = 1;i<=num;i++)
	   	   printf("Fibonacci(%3ld) - %G\n", i, fibonacci(i));
       system("pause");
}
double fibonacci(long n)	   //fibonacci nao-recursiva
{
 	 double temp;
 	 double i = 1;
 	 double soma = 0;
 	 int k;
 	 for(k=1;k<=n;k++){
 	     temp = i + soma;
 	     i = soma;
 	     soma = temp;
    }
    return soma;
}
