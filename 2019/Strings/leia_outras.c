#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Fun��o : Mostra exemplo de aritm�tica de ponteiros com
             strings
    Autor : Edkallenn  - Data : 10/04/2012
    Obs:
*/
#define TAM 80  //tamanho maximo do vetor

void printa_espaco(int n); 
void imprime_inverso(char *s);
void prints(char *string);
void leia(char palavra[], int tamanho);
void flush_in();
void ler(char *string);

int main(){
    char saudacao[] = "Saudacoes, ";
    char nome[TAM], nome1[TAM], nome2[TAM];
    int i;
    printf("Digite seu nome: ");
    scanf(" %80[^\n]", nome);
    printf("%s", saudacao); flush_in();
    printf("%s\n", nome);   
    for (i=0;i<=strlen(nome);i++){
  //for (i=strlen(nome);i>=0;i--)
        printa_espaco(i);
        printf("%s\n", nome + i);
    }
    printf("\n");
    imprime_inverso(nome);    
    printf("%s\n",nome);
    
    printf("Digite alguma coisa: ");
    leia(nome1, 40);
    printf("%s\n",nome1);
    
    //printf("%s\n",nome2);
    prints("Digite outra coisa: ");
    ler(nome2);
    prints(nome2);
    getchar();
}

void printa_espaco(int n){
  int i;
  for(i=n;i>=0;i--){
    printf(" ");
  }
}

void imprime_inverso(char *s){
    int i;
    for ((i=strlen(s));i>=0;i--)
        printf("%c", s[i]);
    printf("\n");
}

void prints(char *string){
  int i;
  for(int i = 0; string[i] != '\0'; i++){
    putchar(string[i]);
  }
  printf("\n");
}

void leia(char palavra[], int tamanho){
  char c;
  char digitada[tamanho+1];
  int i;
  for( i=0; i < tamanho -1; i++){
    c = getchar();
    if (c == '\n') 
      break;
    digitada[i] = c;
  }
  putchar ('\n');
  digitada[i] ='\0';
  strcpy(palavra, digitada);
}

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void ler(char palavra[]){
  char c;
  int i = 0;
  do{
    c = getchar();
    if (c == '\n') 
      break;
    palavra[i] = c;
    i++;
  }while(c!='\n');
  palavra[i] ='\0';
  
}
