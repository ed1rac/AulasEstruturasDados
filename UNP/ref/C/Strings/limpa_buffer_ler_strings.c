#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in();

int main() {   
  char nome[80];
  char nome1[80];

  printf("Digite o primeiro nome: ");
  scanf(" %80[^\n]", nome); flush_in();

  printf("Digite o segundo nome: ");
  fgets(nome1, 80, stdin); 

  printf("Os nomes digitados foram: \n%s\n%s", nome, nome1);

  getchar();
  return 0;
}

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}