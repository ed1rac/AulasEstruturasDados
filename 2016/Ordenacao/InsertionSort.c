/*================================================================
Funçăo : Ordenação por inserção
Autor : Edkallenn
Data : 06/04/2012
================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insertion_sort(int *a);

int main(){
 int i, vet[MAX];

 // Lê MAX ou 10 valores
 for(i = 0; i < MAX; i++){
    printf("Digite um valor: ");
    scanf("%d", &vet[i]);
 }
// Ordena os valores
insertion_sort(vet);

// Imprime os valores ordenados
 printf("\n\nValores ordenados\n");
 for(i = 0; i < MAX; i++){
  printf("%d\t", vet[i]);
 }
 printf("\n");
 system("pause");
 return 0;
}

// Função de Ordenação por Inserção
void insertion_sort(int *a){
int i, j, tmp;
for(i = 1; i < MAX; i++){
     tmp = a[i];
     for(j = i-1; j >= 0 && tmp < a[j]; j--){
         a[j+1] = a[j];
     }
     a[j+1] = tmp;
}

}
