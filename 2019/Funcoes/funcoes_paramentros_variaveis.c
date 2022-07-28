#include <stdio.h>
#include <stdarg.h> //necessário para parâmetros variáveis

int soma(int, ...);

int main() {
  int s;
  s = soma(3, 1,2,3);
  printf("A soma de 1 + 2 + 3 = %d\n", s);
  s = soma(4, 1,2,3,4);
  printf("A soma de 1 + 2 + 3 + 4 = %d\n", s);
    return 0;
}

int soma(int n, ...){
  va_list lista;
  int i, resultado=0;
  va_start(lista, n);

  for(i=1;i<=n;i++)
    resultado = resultado + va_arg(lista, int);

  va_end(lista);

  return resultado;
  
}
/*
- stdarg.h tem macros para uso com parâmetros variáveis.
- va_list recupera os parâmetros adicionais da função
- va_start inicializa uma variável lista, do tipo va_list com as informações necessárias para recuperar os parâmetros adicionais
- va_arg(lista, tipo_dado) --> retorna o parametro atual contido na variável lista do tipo vca_list. Exemplo:
  x = va_arg(lista, float) retorna a variável x o valor do parametro atual em lista formatado para o tipo float
- va_end --> destroi a lista


*/