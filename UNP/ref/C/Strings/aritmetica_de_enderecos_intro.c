#include <stdio.h>
#define QL printf("\n")

int main(void) {
  char string[] = "Olá mundo!";
  int i;
  printf("%s \n", string);      // string       = string[0]
                                // string + 1   = string[1]
                                // string + 2   = string[2]
                                // string + 3   = string[3]
                                //  ....
  int numeros[4] = {1,2,3,4};
  printf("Exibições:\n============== "); QL;
  printf("Tamanho do int: %d", (int) sizeof(int)); QL;
  printf("O endereço de numeros: %d", &numeros); QL;
  printf("O endereço de numeros[0]: %d", &numeros[0]);  QL;
  for(i = 1 ; i < 4; i++){
    printf("O endereço de numeros[%d]: %d", i, &numeros[i]); QL;
  }
  QL;QL;
  printf("Tamanho do char: %d", (int) sizeof(char)); QL;
  for (i = 0;i!='\n';i++){
    printf("O endereço de string[%d]: %d", i, &string[i]); QL;
  }


  QL;
  getchar();
  return 0;
}

