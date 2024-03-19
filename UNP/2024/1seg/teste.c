#include <cs50.h>
#include <stdio.h>

void mostra_tabuada(int numero);
int le_numero(char *mensagem);
void pergunta_nome();

int main(void)
{
  pergunta_nome();
  int N;
  N = le_numero("Digite um número: ");
  mostra_tabuada(N);
}

void mostra_tabuada(int numero)
{
  int count;
  printf("TABUADA DE %d\n================\n", numero);
  for (count = 1; count <= 12; count++)
  {
    printf("%d x %-d = %-d \n", numero, count, numero * count);
  }
}
int le_numero(char *mensagem)
{
  int num;
  printf("%s\n", mensagem);
  scanf(" %d", &num);
  return num;
}

void pergunta_nome()
{
  string nome = get_string("Qual o seu nome?");
  printf("Olá, %s\n", nome);
}
