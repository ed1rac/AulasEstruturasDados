#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100  //tamanho maximo do vetor
/*  Função :Gera numeros aleatorios do tipo float
    Autor : Edkallenn  - Data : 06/04/2012
    Observões: Usa a função rand() e srand para gerar numeros aleatários
*/
void preenche_vetor_aleatorio(float []);   //prototipo das funcoes
void exibe_vetor_float(float *);
int aleatorio(int n);

main(){
    float x[MAX];                     //vetor original
    srand(time(NULL));    //inicializa gerador de nos. aleatorios
    preenche_vetor_aleatorio(x);
    exibe_vetor_float(x);
    getchar();
    return 0;
}
void exibe_vetor_float(float v[]){      //Exibe o vetor
    int t;
    printf("\nO vetor digitado eh\n");
    for (t=0;t<MAX;t++)
        printf("\t%4.2f ", v[t]);
}
void preenche_vetor_aleatorio(float vet[]){  // Preenche com valores aleatorioicos
    int i;                                // Do tipo FLOAT
    float valor, num;
    for (i=0;i<MAX;++i){
        num = 1 + aleatorio(200);  //gera divisor para gerar float
        valor = (1 + (10/num)) + aleatorio(200-1); //gera ate 100
        vet[i]=valor;
    }
}
int aleatorio(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
