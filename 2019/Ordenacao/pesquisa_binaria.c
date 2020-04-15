#include <stdio.h>
#include <stdlib.h>
/*  Funçãoo : Pesquisa usando busca binaria (vetores)
    Autor : Edkallenn  - Data : 10/04/2012
    Obs: Esta é a versão mais simples, mas com funcoes */
#define TAM 20  //tamanho maximo do vetor
int busca_binaria(int [], int, int, int);
void imprime_cabecalho(void);
void imprime_linha(int b[], int menor, int med, int maior);
void preenche_vetor(int n, int []);
void exibe_vetor(int tamanho, int *);
void ordena_bolha_asc_int(int tamanho, int *);
int main(){
    int vetor[TAM], chave_busca, resultado;   //declara o vetor
    preenche_vetor(TAM, vetor); //preenche vetor - mesma funcao anterior
    printf("\n\nO vetor digitado eh\n");
    exibe_vetor(TAM, vetor);    //exibe o vetor
    ordena_bolha_asc_int(TAM, vetor);
    //entra com a chave de pesquisa
    printf("\n\nEntre com o inteiro para a chave de pesquisa: \n");
    scanf("%d", &chave_busca);
    imprime_cabecalho();
    resultado = busca_binaria(vetor, chave_busca, 0, TAM-1);
    if(resultado!=-1)
        printf("\n%d Encontrado no elemento do vetor: %d\n", chave_busca, resultado);
    else
        printf("%d nao encontrado ", chave_busca);
    getchar();
    return 0;
}

int busca_binaria(int b[], int chave_busca, int menor, int maior){
    int meio;
    while(menor<=maior){
        meio=(menor+maior)/2;

        imprime_linha(b, menor, meio, maior);

        if(chave_busca==b[meio])
            return meio;
        else if(chave_busca<b[meio])
            maior = meio-1;
        else
            menor = meio +1;
    }
    return -1;
}

void imprime_cabecalho(void){
    int i;
    printf("\nIndices\n");
    for (i=0; i<TAM; i++)
        printf("%3d ", i);
    printf("\n");
    for (i=0; i<4*TAM; i++)
        printf("-");
    printf("\n");
}
void imprime_linha(int b[], int menor, int med, int maior){
    int i;
    for(i=0; i<TAM;i++)
        if((i<menor)||(i>maior))
            printf(" ");
        else if (i==med)
            printf("%3d*", b[i]); //marca o valor do meio
        else
            printf("%3d ", b[i]);
    printf("\n");
}
void ordena_bolha_asc_int(int tamanho, int a[]){
    int pass, i, aux;
    for (pass=1;pass<tamanho;pass++) //passadas
        for(i=0;i<=tamanho-2;i++) //uma passada
            if(a[i]>a[i+1]){   //uma comparacao
                aux=a[i];     //uma permuta
                a[i]=a[i+1];
                a[i+1]=aux;
            }
}
void preenche_vetor(int tamanho, int vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<tamanho;++i){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}
void exibe_vetor(int tamanho, int v[]){     //Exibe
    int t;
    for (t=0;t<tamanho;t++)
        printf("%-4d ", v[t]);
}
