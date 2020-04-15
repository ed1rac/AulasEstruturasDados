#include <stdio.h>
#include <stdlib.h>

#define MAX 10  //tamanho maximo do vetor
void preenche_vetor(int, int z[MAX]);    //prototipo das funcoes (procedimentos)
void exibe_vetor(int, int []);
int remove_elemento(int k, int v[], int n);
int insere_elemento(int k, int y, int v[], int n);

int main(){
    int indice, novo_tamanho, elemento;
    int med, var, x[MAX];       //media, variancia e vetor originalcls
    preenche_vetor(MAX, x);  
    exibe_vetor(MAX, x);
    printf("Remove elemento\n");
    printf("Qual o indice do elemento que vc quer remover? ");
    scanf(" %d", &indice);
    novo_tamanho = remove_elemento(indice, x, MAX);
    printf("O novo tamanho e´: %d", novo_tamanho);
    exibe_vetor(novo_tamanho, x);
    printf("Insere elemento\n");
    printf("Qual elemento e em qual posição que vc quer inserir? ");
    scanf(" %d %d", &elemento, &indice);
    insere_elemento(indice, elemento, x, novo_tamanho);    
    getchar(); //no devC++ antes desta coloque system("pause"); ou getchar();
}
int remove_elemento(int k, int v[], int n){
/* remove o elemento de índice k do vetor v[0..n-1] e devolve
o novo valor de n. A função supõe, claro, que 0<=k<n
*/
    int j;
    for(j=k;j<n-1;j++){
        v[j]=v[j+1];
    }
    return n-1;
}
int insere_elemento(int k, int y, int v[], int n){
/*  insere o elemento y entre as posições k-1 e k do vetor
    e devolve o novo valor de n. Supõe que 0 <= k <= n
*/
    int j;
    for(j=n;j>k;j--){
        v[j]=v[j-1];
    }
    v[k] = y;
    return n + 1;
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