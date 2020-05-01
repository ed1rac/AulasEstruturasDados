#include <stdio.h>
/** Funçăo : exibe string Invertida recursivamente
* Autor : Edkallenn
* Data : 22/06/2014
* Obs: Usa a função putchar --> exibe um único caractere
*/
void exibeInvertido (char *string);

main(){
    char frase[80];
    printf("\nDigite uma frase: ");
    gets(frase);
    printf("\nA frase invertida e':\n ");
    exibeInvertido(frase);
    getchar();
}

void exibeInvertido (char *string){
    if (*string){
        exibeInvertido (string +1);
        putchar(*string);
    }
}
