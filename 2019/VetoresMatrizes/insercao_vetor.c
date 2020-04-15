#include <stdio.h>
#include <stdlib.h>

#define MAX 10  //tamanho maximo do vetor
void preenche_vetor(int, int z[MAX]);    //prototipo das funcoes (procedimentos)
void exibe_vetor(int, int []);
int remove_elemento(int k, int v[], int n);
int insere_elemento(int k, int y, int v[], int n);

int main(){
    int indice, novo_tamanho, elemento, x[MAX];
    preenche_vetor(MAX, x);  
    exibe_vetor(MAX, x); printf("\n");
    printf("Remove elemento\n");
    printf("Qual o indice do elemento que vc quer remover? ");
    scanf(" %d", &indice);
    novo_tamanho = remove_elemento(indice, x, MAX);
    printf("O novo tamanho e´: %d\n", novo_tamanho);
    exibe_vetor(novo_tamanho, x); printf("\n");
    printf("Insere elemento\n");
    printf("Qual elemento e em qual posicao que vc quer inserir? ");
    scanf(" %d %d", &elemento, &indice);
    insere_elemento(indice, elemento, x, novo_tamanho);  
    exibe_vetor(MAX, x);  
    getchar(); //no devC++ antes desta coloque system("pause"); ou getchar();
}
int remove_elemento(int indice, int v[], int n){
/* remove o elemento de índice indice do vetor v[0..n-1] e devolve
o novo valor de n. A função supõe, claro, que 0<=indice<n
*/
    int j;
    for(j=indice;j<n-1;j++){
        v[j]=v[j+1];
    }
    return n-1;
}
int insere_elemento(int indice, int elemento, int v[], int n){
/*  insere o elemento elemento entre as posições indice-1 e indice do vetor
    e devolve o novo valor de n. Supõe que 0 <= indice <= n
*/
    int j;
    for(j=n;j>indice;j--){
        v[j]=v[j-1];
    }
    v[indice] = elemento;
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