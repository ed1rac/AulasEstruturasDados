#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10  //tamanho maximo do vetor
void insertionSort_Int(int tamanho, int *);
void exibeVetor(int tamanho, int *);
void preencheVetorRandom_int(int tamanho, int maior, int vet[]);
int random(int);
/*
** A funcao InsertionSort rearranja o vetor v[0..n-1]
** em ordem crescente
** Autor: Ed em 10/04/2012
*/
void insertionSort_Int(int tamanho, int vetor[]){
	int i, j, eleito;
	for(i=1;i<tamanho;i++){
		eleito = vetor[i];
		j=i-1;
		while((j>=0) && (eleito < vetor[j])){
			vetor[j+1]=vetor[j];
			j--;
		}
		vetor[j+1]=eleito;
		exibeVetor(tamanho, vetor); printf("\n"); getchar();
	}
}

main(){
    srand((unsigned)time(NULL));
    int vetor[TAM]; //declara o vetor
    preencheVetorRandom_int(TAM, 200, vetor);
    printf("\nO vetor digitado eh\n");
    exibeVetor(TAM, vetor);
    getchar();
    insertionSort_Int(TAM, vetor);
    printf("\n\nO vetor ordenado em ordem crescente eh\n");
    exibeVetor(TAM, vetor); getchar();
    /*ordena_bolha_desc_int(TAM, vetor);
    printf("\n\nO vetor ordenado em ordem decrescente eh\n");
    exibe_vetor(TAM, vetor);getchar();*/
    printf("\n\n");
    getchar();
}
void preencheVetor(int tamanho, int vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<tamanho;++i){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}
void exibeVetor(int tamanho, int v[]){     //Exibe
    int t;
    for (t=0;t<tamanho;t++)
        printf("%-4d ", v[t]);
}
void preencheVetorRandom_int(int tamanho, int maior, int vet[]){
    int i, valor; // Preenche com valores randomicos melhor
    for (i=0;i<tamanho;++i){
        valor = (1 + random(maior-1)); 	//gera ate maior
        vet[i]=valor;
    }
}
int random(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
