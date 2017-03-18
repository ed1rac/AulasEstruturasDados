#include <stdio.h>
#include <stdlib.h>
/*  Função : Strings
    Autor : Edkallenn  - Data : 07/05/2013
    Obs: testa strings  */
#define QL printf("\n")

int comprimento(char *s);
void imprime_inverso(char *);
void imprime(char *);
void exibe(char []);
void copia (char* dest, char* orig);

void imprime(char *s){
    int i;
    for (i=0;s[i]!='\0';i++)
        printf("%c", s[i]);
    printf("\n");
}
void imprime_inverso(char *s){
    int i;
    for ((i=comprimento(s));i>=0;i--)
        printf("%c", s[i]);
    printf("\n");
}

void exibe(char* s){
    printf("%s\n", s);
}
void copia(char* dest, char* orig)
{
    int i;
    for (i=0; orig[i] != '\0'; i++)
        dest[i] = orig[i];
    /* fecha a cadeia copiada */
    dest[i] = '\0';
}

main(){

    char texto[81], texto2[81];
    printf ("Digite um texto: ");
    scanf(" %80[^\n]s", texto); QL;
    printf("O tamanho da cadeia: %s eh %d", texto, comprimento(texto));
    QL; QL;
    imprime_inverso(texto);QL;QL;   // exibe(texto);
    copia(texto2, texto); QL;QL;
    imprime(texto2);QL; imprime(texto);
    system("pause");
}

int comprimento(char *s){
    int i, n;
    n = 0; /* contador */
    for (i=0; s[i]!='\0'; i++)
        n++;
    return n;
}


