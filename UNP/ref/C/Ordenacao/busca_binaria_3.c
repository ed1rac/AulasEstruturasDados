#include <stdio.h>
#define QL printf("\n")

void bubble_sort(int vetor[], int tamanho);
void troca(int array[], int i, int j);
void exibe_vetor(int vetor[], int tamanho);
int busca_binaria(int vetor[], int chave, int menor, int maior);

int main(){

  int resultado, chave_busca, vetor[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
  bubble_sort(vetor, 20);
  printf("Exibe vetor ordenado: \n");  
  exibe_vetor(vetor, 20);
  printf("\nEntre com o valor a procurar: ");
  scanf(" %d", &chave_busca);
  resultado = busca_binaria(vetor, chave_busca, 0, 19);
  if(resultado!=-1)
    printf("\nElemento %d ecnontrado no vetor na posição %d", chave_busca, resultado);
  else
    printf("\nElemento não encontrado");

  getchar();

}
void bubble_sort(int vetor[], int tamanho){
  //considerando que a última posição sempre estará ordenada a cada passo
  int i,j, ultimo;
  ultimo =tamanho-1;

  for(i = ultimo; i > 0; i--){
    //exibiria na tela
    for(j = 0;j<i;j++){
      //exibiria alguma coisa 
      if(vetor[j]> vetor[j+1]){
        troca(vetor, j, j+1);
      }
    }
  }
}

void troca(int array[], int i, int j){
  int aux;
  aux = array[i];
  array[i]= array[j];
  array[j] = aux;
}

void exibe_vetor(int vetor[], int tamanho){
  int i;
  for(i=0;i<tamanho;i++){
    printf("%-3d ", vetor[i]);
  }
}

int busca_binaria(int vetor[], int chave, int menor, int maior){
  int meio;
  while(menor<=maior){
    meio = (int)(menor+maior)/2;
      if(chave==vetor[meio]){
          return meio;
      } else if (chave<vetor[meio]){
          maior = meio - 1;
      } else {
          menor = meio + 1 ;
      }
  }
  return -1;
}



