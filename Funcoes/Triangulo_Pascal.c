#include <stdio.h>
#include <stdlib.h>

/*** Funcao:
 ** Autor(a): alan wink ramalho
 ** Data: 27/05/2016
 ** Observacoes:
 */

void TrianguloPascal(int);
main()
{
	int n;
	printf("\nInforme o valor de N: ");
	scanf("%d", &n);
	if(n<=0) printf("Voce informou um valor menor ou igual a zero! ");
	else{
		TrianguloPascal(n);
	}


}

void TrianguloPascal(int i)
{
	int j;
	int n1 = 1;
  	printf("%d\n",n1);

  	if (i) {
		int n2 = 1;
		int colunas = 2;

		n2 = 1;
		for(j=1;j<colunas && n2 <= i;) {

	   		if(j==1) printf("1 ");
	   		n1 = n1*(n2-j+1)/j;
	   		printf("%d ", n1);
	   		j++;
	  			if (j == colunas) {
				n1 = 1;
		 		n2++;
		 		colunas = n2+1;
		 		j=1;
		 		puts(" ");
	   			}
		}
	}
}
