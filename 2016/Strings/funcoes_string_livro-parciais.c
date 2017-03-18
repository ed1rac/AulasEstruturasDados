#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Strings
    Autor : Edkallenn  - Data : 07/05/2013
    Obs: testa strings  */
#define QL printf("\n")

int comprimento (char *s);
void imprime(char *);
void exibe(char []);
void copia (char* dest, char* orig);
void concatena (char* dest, char* orig);

void imprime(char *s){
    int i;
    for (i=0;s[i]!='\0';i++)
        printf("%c", s[i]);
    printf("\n");
}

void exibe(char* s){
    printf("%s\n", s);
}

void copia(char* dest, char* orig){
    int i;
    for (i=0; orig[i] != '\0'; i++)
        dest[i] = orig[i];
    /* fecha a cadeia copiada */
    dest[i] = '\0';
}

void concatena (char* dest, char* orig){
    int i = 0; /* índice usado na cadeia destino, inicializado com zero */
    int j; /* índice usado na cadeia origem */
    /* acha o final da cadeia destino */
    i = 0;
    while (dest[i] != '\0')
        i++;
        /* copia elementos da origem para o final do destino */
        for (j=0; orig[j] != '\0'; j++){
            dest[i] = orig[j]; i++;
        }
        /* fecha cadeia destino */
    dest[i] = '\0';
}
int compara (char* s1, char* s2){
    int i;
    /* compara caractere por caractere */
    for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++) {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }
    /* compara se cadeias têm o mesmo comprimento */
    if (s1[i]==s2[i])
        return 0; /* cadeias iguais */
    else if (s2[i]!= '\0')
        return -1; /* s1 é menor, pois tem menos caracteres */
    else
        return 1; /* s2 é menor, pois tem menos caracteres */
}

main(){

    char texto[81], texto2[81];
    printf ("Digite uma string: ");
    scanf(" %80[^\n]s", texto); QL;
    imprime(texto);
    printf ("Digite uma string: ");
    scanf(" %80[^\n]s", texto2); QL;
    exibe(texto2);
    printf("\nO tamanho da cadeia: %s eh %d", texto, comprimento(texto));
    printf("\nO tamanho da cadeia: %s eh %d", texto2, comprimento(texto2));
    QL; QL;

}



 /*   imprime(texto);QL;QL;   // exibe(texto);
    copia(texto2, texto); QL;QL;
    imprime(texto2);QL; imprime(texto);QL;QL;
    printf ("Digite uma string: ");
    scanf(" %80[^\n]s", texto2); QL;
    concatena(texto, texto2);
    imprime(texto);  */
    getchar();
//}

int comprimento(char* s){
    int i, n;
    n = 0; /* contador */
    for (i=0; s[i]!='\0'; i++)
        n++;
    return n;
}


