#include <stdio.h>
void le_notas(float[], int);
void exibe_notas(float[], int);
float calcula_media(float *notas, int quantidade);
int main()
{
    int quantidade;
    printf("Digite a quantidade de notas: ");
    scanf(" %d", &quantidade);

    float notas[quantidade];
    le_notas(notas, quantidade);
    exibe_notas(notas, quantidade);
    float media = calcula_media(notas, quantidade);
    printf("A média foi: %g\n", media);
}

void le_notas(float array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf(" %f", &array[i]);
    }
}

void exibe_notas(float array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nota[%d]: %f \n", i + 1, array[i]);
    }
}

float calcula_media(float *notas, int quantidade)
{
    float soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        soma += notas[i];
    }
    return soma / quantidade;
}