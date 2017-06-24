#include <stdio.h>
#include <stdlib.h>
#define NMAX 50

void inserir(int v[], int* n, int x, int p){
  //insere o valor x na posicao p do vetor v
  // O vetor v tem *n elementos
  (*n)++;
  if(p==*n)
    v[p] = x;
  else{
    translacao(v, *n, p, -1);
    v[p] = x;
  }
}

void remover(int v[], int* n, int p){
  //remove o valor da posicao p do vetor v
  //o vetor v tem *n elementos
  translacao(v,*n,p,1);
  v[*n] = 0;
  (*n)--;
}

void permuta(int v[], int n, int k){
  //gera as permutacoes de n inteiros a partir de k
  //a permutacao e' guardada no vetor v que ja' esta'
  //preenchido nas primeiras k-1 posicoes
  int i,m,nmax = NMAX-1;
  for(i=0;i<=k-1;i++){
    inserir(v, &nmax, k, i);
    if(k==n)
      qualquercoisa(v,n);
    else
      permuta(v,n,k+1);
    remover(v,&nmax,i);
  }
}

void escreve(int v[], int ini, int fim){
  int i;
  for(i=ini;i<=fim;i++)
    printf("%d,",v[i]); 
  printf("\n");
}

void qualquercoisa(int v[], int n){
  escreve(v,0,n-1);
}

void translacao(float v[], int n, int p, int k){
  //translacao dos elementos de v, k posicoes
  //para a esquerda (k>0) ou para a direita (k<0)
  //a partir da posicao p
  int i;
  if(k>0)
    for(i=p;i<n-k;i++) v[i] = v[i+k];
  else
    if(k<0)
      for(i=n-1;i>=p-k;i--) v[i]=v[i+k];
}

int main(){
  int i, n, v[NMAX]={0};

  printf("Valor de n? "); scanf(" %d", &n);
  permuta(v,n,1);
}

