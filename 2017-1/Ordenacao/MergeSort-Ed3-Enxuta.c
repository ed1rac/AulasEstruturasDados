/*================================================================
** Função : Ordenação MergeSort
** Autor : Edkallenn
** Data : 22/06/2015
**================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define QL printf("\n")

void geraVetorAleatorio(int vet[], int tamanho, int n);
void exibeVetorInt(int v[], int n);
void merge(int p, int q, int r, int v[]);
void mergeSort(int *v, int p, int r);
void exibeSubVetor( int array[], int primeiro, int ultimo );
int Aleatorio(int n);

int main(){
 srand((unsigned)time(NULL));
 int i, vetor[MAX];
 geraVetorAleatorio(vetor,MAX,100);
 printf("\nO vetor gerado pelo computador eh:\n\n");
 exibeVetorInt(vetor,MAX); printf("\nIteracoes\n");QL;
 mergeSort(vetor,0,MAX);
 printf("\nVetor Ordenado:\n");
 exibeVetorInt(vetor,MAX);
 getchar();
}
void geraVetorAleatorio(int vet[], int tamanho, int n){  // Preenche com valores Aleatorioicos
    int i, valor;
    for (i=0;i<tamanho;++i){
        valor = (1 + Aleatorio(n-1)); 	//gera ate n
        vet[i]=valor;
    }
}
void exibeVetorInt(int v[], int n){      //Exibe o vetor
    int t;                                 //n é o tamanho
    for (t=0;t<n;t++)
        printf("%-3d ", v[t]);
    printf("\n");
}
int Aleatorio(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
void exibeSubVetor( int array[], int primeiro, int ultimo )
{
   int i;
   for ( i = 0; i < primeiro; i++ )
      printf( "   " );
   for (i = primeiro; i <=ultimo; i++ )
      printf( " %d", array[ i ] );
    printf("\n");
}
void merge(int p, int q, int r, int v[]){
    /*  A fun��o merge consiste essencialmente em movimentar
        elementos do vetor v de um lugar para outro
        (primeiro de v para w e depois de w para v)
    */
   int i, j, k;// *w;
  // w = (int*) malloc((r-p)*sizeof(int));
   int w[(r-p)];
   i = p; j = q;
   k = 0;

   while (i < q && j < r) {
      if (v[i] <= v[j])  w[k++] = v[i++];
      else  w[k++] = v[j++];
   }
   while (i < q)
    w[k++] = v[i++];
   while (j < r)
    w[k++] = v[j++];
   for (i = p; i < r; ++i)
        v[i] = w[i-p];
 //  free (w);
}

void mergeSort(int *v, int p, int r){
    if (p < r-1) {
        int q = (p + r)/2;
        mergeSort (v,p, q);
        mergeSort (v, q, r);
        merge (p, q, r, v);
    }
}

