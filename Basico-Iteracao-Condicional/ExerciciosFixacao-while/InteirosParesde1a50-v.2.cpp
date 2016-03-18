#include <stdio.h>
#include <stdlib.h>
/*  Função : Exibir inteiros de 100 a 1
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: Segunda versão usando if
*/

main(){
    int cont;
    cont = 1; 	//variável contadora
    while(cont<=100){
        if(cont%2==0){	// teste - condicional
			printf("%d\t", cont);
		}
        cont++;
    }
    printf("\n");
    system("pause");
}
