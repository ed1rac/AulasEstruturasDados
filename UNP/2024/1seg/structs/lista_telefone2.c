#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[40];
  char number[20];
} pessoa;

int main(void)
{
  pessoa p[10];
  pessoa *pessoas;
  pessoas = malloc(2 * sizeof(pessoa));
  if (pessoas == NULL)
  {
    printf("Erro de alocação");
    exit(1);
  }

  strcpy(pessoas[0].name, "Vanessa");
  strcpy(pessoas[0].number, "+55-083-9495-1000");

  strcpy(pessoas[1].name, "Ana Ester");
  strcpy(pessoas[1].number, "+55-083-9468-2750");

  for (int i = 0; i < 2; i++)
  {
    if (strcmp(pessoas[i].name, "Ana Ester") == 0)
    {
      printf("Encontrado %s\n", pessoas[i].number);
      return 0;
    }
  }
  printf("Não encontrado\n");
  return 1;
}
