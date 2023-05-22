#include <stdio.h>
#include <stdlib.h> //para random
#include <time.h> //para tempo
#define MAX 100  //tamanho maximo do vetor
/*  Fun��o : Preenche vetor com numeros aleatorios (vetores)
    Autor : Edkallenn  - Data : 06/04/2012
    Observa��es: Usa a fun��o rand() e srand para gerar numeros aleat�rios
*/
void preenche_vetor_random(int []);   //prototipa��o das funcoes
void exibe_vetor_int(int []);
int random(int n);
int maximo_r( int tamanho, int v[]);

void exibe_vetor_int(int v[]){      //Exibe o vetor
    int t;
    printf("\nO vetor gerado pelo computador eh:\n\n");
    for (t=0;t<MAX;t++)
        printf("%-3d ", v[t]);
}
void preenche_vetor_random(int vet[]){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<MAX;++i){
        valor = (1 + random(200-1)); 	//gera ate 100
        vet[i]=valor;
    }
}
int random(int n){      //funcao para gerar aleatorios
    return rand() % n;
}

main(){
    int x[MAX], maior;                     //vetor original
    srand((unsigned)time(NULL));    //inicializa gerador de nos. aleatorios
    preenche_vetor_random(x);
    exibe_vetor_int(x);
    maior = maximo_r(MAX, x);
    printf("\n\nO maior elemento do vetor eh: %d\n\n", maior);
    getchar();
	return 0;
}

int maximo_r( int tamanho, int v[]){
   if (tamanho == 1)
      return v[0];
   else{
      int x;
      x = maximo_r(tamanho-1, v);  /* m�ximo de v[0..n-2] */
      if (x > v[tamanho-1])
         return x;
      else
         return v[tamanho-1];
   }
}
