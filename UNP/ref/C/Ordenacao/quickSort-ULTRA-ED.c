/*================================================================
** Funçăo : Ordenação Quicksort
** Autor : Edkallenn
** Data : 22/06/2015
**================================================================*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define QL printf("\n")

void geraVetorRandom(int vet[], int n);
void exibeVetorInt(int v[], int n);
int random(int n);
void quicksort(int v[], int primeiro, int ultimo);
void mostraElementos( int array[], int tamanho );
void exibeSubVetor( int array[], int primeiro, int ultimo );

int main(){
 srand((unsigned)time(NULL));
 int i, vetor[MAX];
 geraVetorRandom(vetor,100);
 printf("\nO vetor gerado pelo computador eh:\n\n");
 exibeVetorInt(vetor,MAX); printf("\nIteracoes\n");QL;
 //mostraElementos(vetor,MAX);
 quicksort(vetor, 0, MAX-1);
 printf("\nVetor Ordenado:\n");
 exibeVetorInt(vetor,MAX);
 getch();

}
void geraVetorRandom(int vet[], int n){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<MAX;++i){
        valor = (1 + random(n-1)); 	//gera ate n
        vet[i]=valor;
    }
}
void exibeVetorInt(int v[], int n){      //Exibe o vetor
    int t;                                 //n é o tamanho
   // printf("\nO vetor gerado pelo computador eh:\n\n");
    for (t=0;t<n;t++)
        printf("%-3d ", v[t]);
}
int random(int n){      //funcao para gerar aleatorios
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
      printf( "   " );
   for ( i = primeiro; i <= ultimo; i++ )
      printf( " %d", array[ i ] );
    printf("\n");
}
void quicksort(int v[], int primeiro, int ultimo){
    int i,j;
    int m,meio, aux;

    i = primeiro;
    j = ultimo;
    meio = (int)(i+j)/2;
    m = v[meio];

    do{
        while(v[i]<m)   i++;
        while(v[j]>m)   j--;
        if(i<=j){
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        } mostraElementos(v,MAX);
    }while(i<=j);
    mostraElementos(v,MAX);
    if(primeiro<j)
        quicksort(v,primeiro,j);
    if(ultimo>i)
        quicksort(v,i,ultimo);



}
