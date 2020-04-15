#include <stdio.h>
/** Funçăo : caminhar String
* Autor : Edkallenn
* Data : 22/06/2015
* Obs: Usa a função putchar --> exibe um único caractere
*/

main(){
    char frase[80];
    int i;

    printf("\nDigite uma frase: ");
    gets(frase);
    //outra forma de "caminhar" na string, usando NULL
    for(i=0; frase[i] != NULL; i++){  //outra forma de "caminhar" na
        putchar(frase[i]);         //string
    }
    printf("\n\nO numero de caracteres de %s = %d", frase,i);

    getchar();
}
