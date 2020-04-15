/*
** Função: Tripla Pitagorica
** Autor(a): Edkallenn
** Data:  08/12/2015
** Observações: Exemplo de força bruta  
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	
   int lado1, lado2, hipotenusa, num; 
   printf("Digite o número máximo até onde procurar triplas: ");
   scanf("%d", &num);
   printf("a\tb\tc\n=========================\n");
   for (lado1=1; lado1 <= num; lado1++) 
      for (lado2=1; lado2<=num; lado2++) 
         for (hipotenusa=1; hipotenusa<=num; hipotenusa++) 
            if ((hipotenusa * hipotenusa) == (lado1 * lado1 + lado2 * lado2)) 
		          printf("%d\t%d\t%d\n", lado1, lado2, hipotenusa);
	

}
