#include <stdio.h>
#include <stdlib.h>
/*  Função : Quicksort - ordenação quick
    Autor : Edkallenn  - Data : 06/04/2012
    Observações: p26.c - Senne c/ funções do professor
*/
#define MAX 10  //50

void preenche_vetor_random(int,int, int[]);   //prototipo das funcoes (procedimentos)
void exibe_vetor();       //prototipo alternativo (demonstra uso ponteiros)
void quicksort(int v[], int primeiro, int ultimo);
int random(int n);

main(){
    int x[MAX], maior;                     //vetor original
    srand((unsigned)time(NULL));    //inicializa gerador de nos. aleatorios
    preenche_vetor_random(MAX,200, x);
    exibe_vetor(x);
    //Classifica o vetor
    printf("\n\no primeiro elemento = %d - e o ultimo = %d\n\n", x[0],x[MAX-1]);
    quicksort(x,0,MAX-1);
    printf("\n\nVetor Classificado:\n\n");
    exibe_vetor(x);
    getchar();
}

void exibe_vetor(int x[]){     //Exibe
    int t;
    printf("\nO vetor gerado eh\n");
    for (t=0;t<MAX;t++)
        printf("%-3d ", x[t]);
}
void preenche_vetor_random(int tamanho, int maior, int vet[]){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<tamanho;++i){
        valor = (1 + random(maior-1)); 	//gera ate 100
        vet[i]=valor;
    }
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
        }
    }while(i<=j);
    if(primeiro<j)
        quicksort(v,primeiro,j);
    if(ultimo>i)
        quicksort(v,i,ultimo);

}
int random(int n){
    return rand()%n;
}
