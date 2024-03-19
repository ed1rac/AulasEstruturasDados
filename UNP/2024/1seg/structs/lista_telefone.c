#include <stdio.h>
#include <string.h>

int main(void) {
  char *names[] = {"Vanessa", "Ana Ester"};
  char *numbers[] = {"+55-083-9495-1000", "+55-083-9468-2750"};

  for (int i = 0; i < 2; i++) {
    if (strcmp(names[i], "Ana Ester") == 0) {
      printf("Encontrado %s\n", numbers[i]);
      return 0;
    }
  }
  printf("Não encontrado\n");
  return 1;
}
