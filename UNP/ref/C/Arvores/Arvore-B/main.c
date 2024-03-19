/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Árvore B
*   Referência 1: http://www2.dcc.ufmg.br/livros/algoritmos/cap6/slides/c/completo1/cap6.pdf
*   Referência 2: http://www2.dcc.ufmg.br/livros/algoritmos-edicao2/cap6/codigo/c/6.3a6.9-arvore-b.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "TAB.h"
#include "TAB.c"

int main(){
  TAB *main = NULL;	//	inicializa
  int ordem = 2;
  int num = 12;

  insercao(&main, 3, ordem);
  insercao(&main, 2, ordem);
  insercao(&main, 4, ordem);
  insercao(&main, 5, ordem);
  insercao(&main, 6, ordem);
  insercao(&main, 6, ordem);
  insercao(&main, 7, ordem);
  insercao(&main, 8, ordem);
  insercao(&main, 9, ordem);

  printf("\nImpressao\n");
  imprimir(main, 0);

  remocao(&main, 8, ordem);

  printf("\nImpressao\n");
    imprimir(main, 0);

  remocao(&main, 3, ordem);

  printf("\nImpressao\n");
    imprimir(main, 0);

    if(busca(main, num))
        printf("Numero %i esta na arvore", num);
    else
        printf("Numero %i nao esta na arvore", num);

  return 0;
}