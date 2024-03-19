#include <stdio.h>

int main(int argc, char *argv[]) {
  // espera o usuário executar com o nome do usuário. Assim:
  // ./cumprimente Edkallenn. A saída será:
  // Olá Edkallenn, seja bem vindo!
  if (argc != 2) {
    printf("Faltando argumento de linha de comando!\n");
    return 1;
    // neste caso faltaram argumentos (ou foram demais.)
    // ele só aceita dois. Um é o nome do programa `./cumprimente`
    // e o outro é o nome do usuário.
  }
  printf("Olá %s, seja bem vindo!\n", argv[1]);

  // para verificar o retorno do aplicativo (se retornou 0 ou 1 bsta fazer: 
  // echo $? 
  // no prompt do terminal)
  return 0;
}