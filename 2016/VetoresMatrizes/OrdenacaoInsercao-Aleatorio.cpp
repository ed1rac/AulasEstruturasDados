#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20  //tamanho maximo do vetor
/*  Função : Preenche vetor com numeros aleatorios (vetores)
    Autor : Edkallenn  - Data : 06/04/2012
    Observações: Usa a função rand() e srand para gerar numeros aleatórios
*/
void preenche_vetor_random(int [], int);   //prototipação das funcoes
void exibe_vetor_int(int []);
void insertionSortInt(int n, int vetor[]);
int random(int n);
int verificaOrdenado (int x[], int num);

main(){
    int x[MAX];                     //vetor original
    srand((unsigned)time(NULL));    //inicializa gerador de nos. aleatorios
    preenche_vetor_random(x, 200);
    exibe_vetor_int(x);
    if(verificaOrdenado(x, MAX)) printf("\nEsta ordenado\n"); else  printf("\nNao esta ordenado\n");
    printf("\n\nVetor Ordenado: \n");
    insertionSortInt(MAX, x);
    exibe_vetor_int(x);
    if(verificaOrdenado(x, MAX)) printf("\nEsta ordenado\n"); else  printf("\nNao esta ordenado\n");
    getchar();
	return 0;
}
void insertionSortInt(int n, int vetor[]){
	int i, j, eleito;
	for(j=1;j<n;j++){
		eleito = vetor[j];
		for(i=j-1;i>=0 && vetor[i] > eleito;i--)
			vetor[i+1]=vetor[i];
		vetor[i+1]=eleito;
		//exibeVetor(TAM, vetor); printf("\n");
	}
}
void exibe_vetor_int(int v[]){      //Exibe o vetor
    int t;
    printf("\nO vetor gerado pelo computador eh:\n\n");
    for (t=0;t<MAX;t++)
        printf("%-3d ", v[t]);
}
void preenche_vetor_random(int vet[], int n){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<MAX;++i){
        valor = (1 + random(n-1)); 	//gera ate 100
        vet[i]=valor;
    }
}
int random(int n){      //funcao para gerar aleatorios
    return rand() % n;
}

int verificaOrdenado (int x[], int num){
    int i;
    for(int i=1;i<num;i++){
        if(x[i]<x[i-1]){
            return 0;
            //break;
        }
    }
    return 1;
}
