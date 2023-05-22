#include <stdio.h>
#include <stdlib.h>
#define MAX 200
void preenche_array(int *array);
void exibe_array(int array[]);
int main()
{
    int valores[MAX];
    preenche_array(valores);
    exibe_array(valores);
    return 1;
}
void exibe_array(int array[]){
    int i;
    printf("Exibindo o Array!\n===================\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d\t", array[i]);
        if ((i % 10 == 0) && (i != 0))
            printf("\n");
    }
    printf("\n");
}
void preenche_array(int *array){
    printf("Preenchendo o Array!\n");
    int i;
    for (i = 0; i < MAX; i++)    {
        array[i] = i + 1;
    }
}