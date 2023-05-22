#include <stdio.h>
#include <stdlib.h>

#ifdef __WIN32
#define limpar_tela system("cls");
#else
#define limpar_tela system("clear");
#endif

#define MAX 5


typedef struct
{
  char *nome[MAX][50];
  int *idade[MAX][3];
  float *nota[MAX][4];

}ALUNO;

void iniciar_estrutura(ALUNO *aluno);
void sub_menu_inserir();
int inserir_valores_nome(ALUNO *aluno);

int main(void)
{
  ALUNO aluno;
  iniciar_estrutura(&aluno);
  sub_menu_inserir();

  return 0;
}

void iniciar_estrutura(ALUNO *aluno)
{
  for(int i = 0; i < MAX; i++) 
  {
    for(int j = 0; j < 50; j++) aluno ->nome[i][j] = "\0" ;
  }

  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < 3; j++) aluno ->idade[i][j] = 0;
  }

  for(int i = 0; i < MAX; i++)
  {
    for(int j = 0; j < 4; j++) aluno ->nota[i][j] = 0;
  }
}
void sub_menu_inserir()
{
  ALUNO aluno;
  char alternativa;
  printf("\nA - I N S E R I R    N O M E\n");
  printf("\n(indisponivel)B - I N S E R I R    I D A D E\n");
  printf("\n(indisponivel)C - I N S E R I R    N O T A\n");
  printf("\nalternativa: ");
  scanf(" %c", &alternativa);
  switch(alternativa)
  {
    case 'A': inserir_valores_nome(&aluno); break;
    default: sub_menu_inserir(); break;
  }

}
int inserir_valores_nome(ALUNO *aluno)
{
  
  int posicao;
  printf("Escolha a posicao[0 - %d]: ",MAX-1);
  scanf(" %d", &posicao);
  if((posicao < 0) ||(posicao > MAX) || (posicao == MAX)) return -1;
  else
  {
    for(int i = posicao; i == posicao ; i++)
    {
      for(int j = 0; j < 1; j++)
      {
        printf("NOME: ");
        scanf(" %s%*c", &aluno->nome[i][j]);
        printf("%p",aluno->nome[i][j]);
      }
    }  
  }
  sub_menu_inserir();
}


