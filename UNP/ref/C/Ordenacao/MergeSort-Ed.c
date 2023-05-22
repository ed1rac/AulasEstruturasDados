/*================================================================
** Funçăo : Ordenação Quicksort
** Autor : Edkallenn
** Data : 22/06/2015
**================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 10
#define QL printf("\n")

void gera_vetor_aleatorio(int vet[], int n);
void exibeVetorInt(int v[], int n);
int aleatorio(int n);
void merge(int *V, int inicio, int meio, int fim);
void mergeSort(int *V, int inicio, int fim);
void mostraElementos( int array[], int tamanho );
void exibeSubVetor( int array[], int primeiro, int ultimo );

int main(){
 srand(time(NULL));
 int i, vetor[MAX];
 gera_vetor_aleatorio(vetor,100);
 printf("\nO vetor gerado pelo computador eh:\n\n");
 exibeVetorInt(vetor,MAX); printf("\nIteracoes\n");QL;
 mostraElementos(vetor,MAX);
 mergeSort(vetor,0,MAX);
 printf("\nVetor Ordenado:\n");
 exibeVetorInt(vetor,MAX);
 getchar();

}
void gera_vetor_aleatorio(int vet[], int n){  // Preenche com valores aleatorioicos
    int i, valor;
    for (i=0;i<MAX;++i){
        valor = (1 + aleatorio(n-1)); 	//gera ate n
        vet[i]=valor;
    }
}
void exibeVetorInt(int v[], int n){      //Exibe o vetor
    int t;                                 //n é o tamanho
   // printf("\nO vetor gerado pelo computador eh:\n\n");
    for (t=0;t<n;t++)
        printf("%-3d ", v[t]);
    printf("\n");
}
int aleatorio(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
void mostraElementos( int array[], int tamanho )
{
   exibeSubVetor( array, 0, tamanho - 1 );
}
void exibeSubVetor( int array[], int primeiro, int ultimo )
{
   int i;
   for ( i = 0; i < primeiro; i++ )
      printf( "   " ); //3 espaços
   for ( i = primeiro; i <ultimo; i++ )
      printf( " %d", array[ i ] );
    printf("\n");
}
void merge(int *V, int inicio, int meio, int fim){
    // Cria novo vetor temporario (*temp) para guardar os elementos
    // inseridos na ordem correta. Entao inicia um laco (linha 79) que
    // compara os elementos, inserindo-os em temp[i]. fim1 e fim2 e'booleano
    // e marcam o fim dos subvetores menores. Ao final copia o novo para V (vetor original)
    // p1 e p2 sao as posicoes dos 'subvetores'
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1; //n1
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{ //para inserir os que 'sobraram'
                if(!fim1)
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++) //copia de volta para V
            V[k]=temp[j];
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V,inicio,meio); exibeSubVetor(V,inicio,meio);
        mergeSort(V,meio+1,fim);  exibeSubVetor(V,meio+1,fim-1);
        merge(V,inicio,meio,fim); exibeSubVetor(V,inicio,fim-1);
    }
}
