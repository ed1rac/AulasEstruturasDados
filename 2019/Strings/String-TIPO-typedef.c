#include <stdio.h>
#include <stdlib.h>

typedef char *String;

int main(){
    
    String nome = "Edkallenn Silva de Lima";
    String texto;
    printf("Nome: %s\n\n", nome);
    printf("Digite um texto: ");
    scanf(" %80[^\n]", texto);
    printf("Texto digitado: %s", texto);

    getchar();
}