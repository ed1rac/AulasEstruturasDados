#include <stdio.h>
/** Funçăo : conta o numero de ocorrencias de um caractere em string
* Autor : Edkallenn
* Data : 22/06/2015
* Obs:
*/
int contachar (const char *string, char letra);
main(){
    char frase[80], caractere;
    int quantidade;

    printf("\nDigite uma frase: ");
    gets(frase);
    printf("\nQual caractere procurar? ");
    caractere = getchar();
    quantidade = contachar(frase,caractere);

    printf("\n\nO numero de ocorrencias de %c em \"%s\"", caractere,frase);
    printf(" = %d\n\n", quantidade);
    getchar();
}
int contachar (const char string[], char letra){
    int i, quant = 0;
    for(i=0;string[i]!='\0';i++)
        if (string[i] == letra)
            quant++;
    return quant;
}
