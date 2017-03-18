#include <stdio.h>
#include <stdlib.h>
/*
    Função : Mais exemplos do operador sizeof
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: sizeof é um operador em tempo de compilação unário que retorna
 				o tamanho, em bytes, da variável ou especificador de tipo,
				em parenteses que ele precede.
*/
main()
{
 	  float f;

 	  printf("%d\n", sizeof f);
 	  printf("%d\n\n", sizeof (int));

	  system("pause");

}
