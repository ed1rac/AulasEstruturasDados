#include <stdio.h>
#include <stdlib.h>
/*  Função : Classifica usando bubblesort (vetores)
    Autor : Edkallenn  - Data : 10/04/2012
    Obs: Esta é a versão mais simples, mas com funcoes  */
#define TAM 10  //tamanho maximo do vetor
void ordena_bolha_int(int tamanho, int *);
void preenche_vetor(int n, int []);
void exibe_vetor(int tamanho, int *);
main(){
    int vetor[TAM];
    preenche_vetor(TAM, vetor);
    printf("\nO vetor digitado eh\n");
    exibe_vetor(TAM, vetor);
    ordena_bolha_int(TAM, vetor);
    printf("\n\nO vetor ordenado eh\n");
    exibe_vetor(TAM, vetor);
    printf("\n\n");
    getchar();
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
void ordena_bolha_int(int tamanho, int a[]){
    int pass, i, aux;
    for (pass=1;pass<tamanho;pass++)  //passadas
        for(i=0;i<=tamanho-2;i++){    //uma passada
            if(a[i]>a[i+1]){    //uma comparacao
                aux=a[i];       //uma permuta
                a[i]=a[i+1];
                a[i+1]=aux;
            } printf("\n"); exibe_vetor(TAM, a); printf("\n"); //getchar();
        }
}

