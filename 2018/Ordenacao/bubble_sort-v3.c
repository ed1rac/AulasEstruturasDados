#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10  //tamanho maximo do vetor
void bubble_sort_int(int tamanho, int *);
void exibe_vetor(int tamanho, int *);
void preenche_vetor_random_int(int tamanho, int maior, int vet[]);
int aleatorio(int);
void troca(int array[], int i, int j);
//void preenche_vetor(int tamanho, int vet[])
/*
** A funcao BubbleSort rearranja o vetor v[0..n-1]
** em ordem crescente
** Autor: Ed em 10/04/2013 - alterado em 02/03/2019
*/
/*void bubble_sort_int(int tamanho, int vetor[]){
	int i, houvetroca, temp, fim = tamanho;
	do{
        houvetroca = 0;
        for(i=0; i<fim-1;i++){
            if(vetor[i]>vetor[i+1]){
                temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                houvetroca = 1;
            } exibe_vetor(tamanho, vetor); printf("\n"); getchar();
        }
	}while(houvetroca!=0);

}*/
void bubble_sort_int(int tamanho, int vetor[]){
    int i, j;
    for (i=1; i < tamanho;i++){
        printf("\n[%d] ", i);
        
        for(j=0;j<tamanho-i; j++){
            printf("%d, ", j);

            if(vetor[j]>vetor[j+1]){
                printf("troca %d com %d\n", vetor[j], vetor[j+1]);
                troca(vetor, j, j+1);
            }
        }
    }
}

void troca(int array[], int i, int j){
    int aux;
    aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

int main(){
    srand(time(NULL));
    int vetor[TAM]; //declara o vetor
    preenche_vetor_random_int(TAM, 100, vetor);
    printf("\nO vetor digitado e'\n");
    exibe_vetor(TAM, vetor);
    getchar();
    bubble_sort_int(TAM, vetor);
    printf("\n\nO vetor ordenado em ordem crescente e'\n");
    exibe_vetor(TAM, vetor); getchar();
    /*ordena_bolha_desc_int(TAM, vetor);
    printf("\n\nO vetor ordenado em ordem decrescente eh\n");
    exibe_vetor(TAM, vetor);getchar();*/
    printf("\n\n");
    getchar();
    return 0;
}
void preenche_vetor(int tamanho, int vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<tamanho;++i){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}
void exibe_vetor(int tamanho, int v[]){     //Exibe
    int t;
    for (t=0;t<tamanho;t++)
        printf("%-4d ", v[t]);
}
void preenche_vetor_random_int(int tamanho, int maior, int vet[]){
    /*  A funcao preenche_vetor_random_int preenche o vetor com valores aleatorios
        os parametros sao <tamanho> que e' o tamanho do vetor, <maior> o maior valor gerado
        e <vet> que e' o proprio vetor.
    */
    int i, valor; // Preenche com valores randomicos melhor
    for (i=0;i<tamanho;++i){
        valor = (1 + aleatorio(maior-1)); 	//gera ate maior
        vet[i]=valor;
    }
}
int aleatorio(int n){      //funcao para gerar aleatorios inteiros
    return rand() % n;
}
