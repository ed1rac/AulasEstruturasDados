/*================================================================
** Função : Ordenação MergeSort
** Autor : Edkallenn
** Data : 22/06/2015
**================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#define MAX 10
#define QL printf("\n")
//protótipos
void geraVetorRandom(int vet[], int tamanho, int n);
void exibeVetorInt(int v[], int n);
void merge(int *V, int inicio, int meio, int fim);
void mergeSort(int *V, int inicio, int fim);
void exibeSubVetor( int array[], int primeiro, int ultimo );
int random(int n);

int main(){
 srand((unsigned)time(NULL));
 int i, vetor[MAX];
 geraVetorRandom(vetor,MAX,100);
 printf("\nO vetor gerado pelo computador eh:\n\n");
 exibeVetorInt(vetor,MAX); printf("\nIteracoes\n");QL;
 mergeSort(vetor,0,MAX-1);  //chamada para mergesort
 printf("\nVetor Ordenado:\n");
 exibeVetorInt(vetor,MAX);  //exibe vetor ordenado
 getchar();
}
void geraVetorRandom(int vet[], int tamanho, int n){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<tamanho;++i){
        valor = (1 + random(n-1)); 	//gera ate n
        vet[i]=valor;
    }
}
void exibeVetorInt(int v[], int n){      //Exibe o vetor
    int t;                                 //n Ã© o tamanho
    for (t=0;t<n;t++)
        printf("%-3d ", v[t]);
    printf("\n");
}
int random(int n){      //funcao para gerar aleatorios
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
void merge(int *V, int inicio, int meio, int fim){
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;

    int tamanhoArray=tamanho;
    int temp[tamanhoArray];

    printf("Combina:   ");exibeSubVetor(V,p1, meio);
    printf("           ");exibeSubVetor(V,p2, fim-1);

    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k]=temp[j];
    }
    printf("           ");exibeSubVetor(V,inicio, fim-1); printf("\n");

    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);

        printf("Divide:    ");exibeSubVetor(V,inicio, fim);
        printf("           ");exibeSubVetor(V,inicio, meio);
        printf("           ");exibeSubVetor(V,meio+1, fim);

        mergeSort(V,inicio,meio);
        mergeSort(V,meio+1,fim);
        merge(V,inicio,meio,fim);
    }
}
