#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

//Alocação dinâmica de estruturas

typedef struct aluno{
        int nmat;
        char nome[81];
        char end[121];
        char tel[20];        
}Aluno;




void inicializa(int n, Aluno** tab);
void preenche(int n, Aluno** tab, int i);
void imprime(int n, Aluno** tab, int i);
void imprime_tudo(int n, Aluno** tab);







int main(){
    Aluno* tab[MAX];
    inicializa(MAX,tab);
    preenche(MAX,tab,0);
    preenche(MAX,tab,1);
    preenche(MAX,tab,2);
    imprime_tudo(MAX, tab);
    retira(MAX,tab,0);
    retira(MAX,tab,1);
    imprime_tudo(MAX, tab);  
    //finaliza saindo deste programa
    getchar();
    return 0;
}







void inicializa(int n, Aluno** tab){
  int i;
  for(i=0;i<n;i++){
    tab[i]=NULL;
  }
}

void preenche(int n, Aluno** tab, int i){
  if(i<0||i>=n){
    printf("Índice fora do índice do vetor - preenche\n");
    exit(1);
  }
  if(tab[i] == NULL) {
    tab[i] = (Aluno*)malloc(sizeof(Aluno));
    printf("Entre com a matrícula: ");scanf(" %d", &tab[i]->nmat);
    printf("Entre com o nome: ");     scanf(" %80[^\n]", tab[i]->nome);
    printf("Entre com o sobrenome: ");scanf(" %120[^\n]", tab[i]->end);
    printf("Entre com o telefone: "); scanf(" %20[^\n]", tab[i]->tel);
  }
}





void retira(int n, Aluno** tab, int i){
  if(i<0||i>=n){
    printf("Índice fora do índice do vetor - preenche\n");
    exit(1);
  }
  if(tab[i] != NULL) {
    free(tab[i]);
    tab[i]=NULL;
  }
}

void imprime(int n, Aluno** tab, int i){
  if(i<0||i>=n){
    printf("Índice fora do índice do vetor\n");
    exit(1);
  }
  if(tab[i] != NULL){
    printf("Matrícula: %d\n", tab[i]->nmat);
    printf("Nome: %s\n", tab[i]->nome);
    printf("Sobrenome: %s\n", tab[i]->end);
    printf("Telefone: %s\n", tab[i]->tel);
  }
}



void imprime_tudo(int n, Aluno** tab){
  int i;
  for(i=0;i<n;i++){
    imprime(n,tab,i);
  }

}