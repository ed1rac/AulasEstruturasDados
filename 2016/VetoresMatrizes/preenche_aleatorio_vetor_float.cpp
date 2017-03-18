#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100  //tamanho maximo do vetor
/*  Função :Gera numeros aleatorios do tipo float
    Autor : Edkallenn  - Data : 06/04/2012
    Observções: Usa a função rand() e srand para gerar numeros aleatórios
*/
void preenche_vetor_random(float []);   //prototipo das funcoes
void exibe_vetor_float(float *);
int random(int n);

main(){
    float x[MAX];                     //vetor original
    srand((unsigned)time(NULL));    //inicializa gerador de nos. aleatorios
    preenche_vetor_random(x);
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
void preenche_vetor_random(float vet[]){  // Preenche com valores randomicos
    int i;                                // Do tipo FLOAT
    float valor, num;
    for (i=0;i<MAX;++i){
        num = 1 + random(200);  //gera divisor para gerar float
        valor = (1 + (10/num)) + random(200-1); //gera ate 100
        vet[i]=valor;
    }
}
int random(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
