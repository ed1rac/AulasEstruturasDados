#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100  //tamanho maximo do vetor
/*  Função : Preenche vetor com numeros aleatorios (vetores)
    Autor : Edkallenn  - Data : 06/04/2012
    Observções: Usa a função rand() e srand para gerar numeros aleatarios
*/
void preenche_vetor_random(int []);   //prototipação das funcoes
void exibe_vetor_int(int []);
int aleatorio(int n);

void exibe_vetor_int(int* v){      //Exibe o vetor
    int t;
    printf("\nO vetor gerado pelo computador eh:\n\n");
    for (t=0;t<MAX;t++)
        printf("%-3d\t", v[t]);
}
void preenche_vetor_random(int vet[]){  // Preenche com valores randomicos
    int i, valor;
    for (i=0;i<MAX;++i){
        valor = (aleatorio(200)); 	//gera ate 200
        vet[i]=valor;
    }
}
int aleatorio(int n){      //funcao para gerar aleatorios
    return rand() % n + 1;
}

int main(){
    int x[MAX];            //vetor original
    srand(time(NULL));    //inicializa gerador de nos. aleatorios
    preenche_vetor_random(x);
    exibe_vetor_int(x);
    getchar();
	return 0;
}
