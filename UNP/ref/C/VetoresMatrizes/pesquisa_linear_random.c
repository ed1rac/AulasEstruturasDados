#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*  Função : Pesquisa usando busca linear (vetores)
    Autor : Edkallenn  - Data : 10/04/2012
    Obs: Esta é a versão mais simples, mas com funcoes */
#define TAM 100  //tamanho maximo do vetor
int busca_linear(int [], int, int);
void preenche_vetor(int n, int []);
void exibe_vetor(int tamanho, int *);
void preenche_vetor_random(int n, int tamanho, int vet[]);
main(){
    srand((unsigned)time(NULL));
    int vetor[TAM], x, chave_busca, elemento;   //declara o vetor
    //preenche_vetor(TAM, vetor); //preenche vetor - mesma funcao anterior
    preenche_vetor_random(100, TAM, vetor);
    printf("\n\nO vetor digitado eh\n");
    exibe_vetor(TAM, vetor);    //exibe o vetor
    //entra com a chave de pesquisa
    printf("\n\nEntre com o inteiro para a chave de pesquisa: \n");
    scanf("%d", &chave_busca);
    elemento = busca_linear(vetor, chave_busca, TAM);
    //exibe em qual índice está o elemento,  se for encontrado.
    if(elemento!=-1)
        printf("\nValor encontrado na posicao %d\n", elemento);
    else
        printf("Valor nao encontrado ");
    printf("\n\n");
    getchar();
}
int busca_linear(int array[], int chave, int tamanho){
    int n;
    for(n=0;n<tamanho;n++)
        if(array[n]==chave)
            return n;
    return -1;

}
void preenche_vetor(int tamanho, int vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<tamanho;++i){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}
void preenche_vetor_random(int n, int tamanho, int vet[]){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<tamanho;++i){
        valor = (1 + random(n-1)); 	//gera ate 100
        vet[i]=valor;
    }
}
void exibe_vetor(int tamanho, int v[]){     //Exibe
    int t;
    for (t=0;t<tamanho;t++)
        printf("%-4d ", v[t]);
}
int random(int n){
    return rand()%n;
}
