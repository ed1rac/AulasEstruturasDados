/*
Funçăo : Ordenação por selecao
Autor : Edkallenn
Data : 06/04/2012
Observaçőes: A ordenação por selecao consiste em procurar o menor elemento no vetor e permutar esse
            elemento com o primeiro elemento do vetor. Repete-se esse processo para o subvetor que se
            inicia no segundo elemento e, assim, sucessivamente. O processo termina quando o subvetor
            contiver apenas um elemento.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INFINITO 999999
#define TAM_MAX 20

void troca(int v[], int i, int j);
void ordena_por_selecao(int x[], int n);
void mostra_vetor(int a[], int n);

void troca(int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i]=v[j];
    v[j]=aux;
}

void ordena_por_selecao(int x[], int n){
    int menor, pos;
    int i,k;
    k=0;

    while(k<n){
        menor=INFINITO;
        for(i=k;i<n;i++)
            if(x[i]<menor)
            {
                menor = x[i];
                pos = i;
            }
            troca(x,k,pos);
            printf("Passo %d\n", k+1);
            mostra_vetor(x,n); printf("\n");
            k++;
    }
}

int main(){
    int i,n,a[TAM_MAX];

    //inicializa o gerador de numeros aleatorios
    srand((unsigned)time(NULL));

    //Vetor gerado aleatoriamente
    n = (rand() % TAM_MAX)+1;
    printf("Vetor Original: \n");
    for(i = 0; i<n;i++)
    {
        a[i] = (rand()%100);
        printf("%d ", a[i]);
    }
    printf("\n\n");

    //Classificar vetor
    ordena_por_selecao(a,n);
    printf("Vetor Ordenado\n");
    mostra_vetor(a,n);
    printf("\n\n");
    system("pause");
    return 0;
}

void mostra_vetor(int a[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
}
