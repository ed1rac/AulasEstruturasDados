#include <stdio.h>
#include <stdlib.h>

#define MAX 10  //tamanho maximo do vetor
void preenche_vetor(int, int z[MAX]);    //prototipo das funcoes (procedimentos)
void exibe_vetor(int, int []);
int remove_elemento(int k, int v[], int n);

main(){
    int indice, novo_tamanho;
    int med, var, x[MAX];       //media, variancia e vetor original
    preenche_vetor(MAX, x);  
    exibe_vetor(MAX, x);
    printf("Remove elemento\n");
    printf("Qual o indice do elemento que vc quer remover? ");
    scanf(" %d", &indice);
    novo_tamanho = remove_elemento(indice, x, MAX);
    printf("O novo tamanho e´: %d", novo_tamanho);
    exibe_vetor(novo_tamanho, x);    
    getchar(); //no devC++ antes desta coloque system("pause"); ou getchar();
}
int remove_elemento(int k, int v[], int n){
    int j;
    for(j=k;j<n-1;j++){
        v[j]=v[j+1];
    }
    return n-1;
}
void exibe_vetor(int tamanho, int v[]){     //Exibe o vetor do tipo int
    int t;
    printf("\nO vetor digitado eh\n\n");
    for (t=0;t<tamanho;t++)
        printf("%-3d ", v[t]);
}
void preenche_vetor(int tamanho, int vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<tamanho;++i){ //quaisquer alteracoes aqui afetam x[MAX] (referencia)
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
        }
}