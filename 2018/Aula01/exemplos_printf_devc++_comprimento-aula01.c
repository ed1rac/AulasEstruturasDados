#include <stdio.h>
#include <stdlib.h>
// Função : Alguns exemplos de utilizacao da funcao printf
// Autor : Edkallenn
// Data : 06/04/2012
// Observações:
int main(){
    double item = 10.12304;

    printf("%f\n", item);
    printf("%10f\n", item);
    printf("%012f\n", item);
    printf("%-10f\n", item);
    printf("%010.2f\n\n", item);

	printf("%10.15s\n\n", "Esse e um teste simples");
    //Em strings, o especificador de precisao determina o comprimento minimo e
    //maximo do campo. Ex. %5.7s mostra uma string de pelo menos 5 e nao
    //excedendo sete caracteres.
    //Aplicado a inteiros o identificador de precisao determina o numero minimo
	//de digitos que aparecerao para cada numero. Zeros iniciais serao adiciona-
	//dos para completar o numero solicitado de digitos
	//Exemplo:
 	printf("%9.8d\n", 1000);
 	printf("%.3f\n", item);
    system("pause"); ////system("read");    --> no linux
    return 0;
}
