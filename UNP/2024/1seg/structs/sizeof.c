#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[40];
    char number[20];
} pessoa;

int main()
{
    int num;
    float real;
    double duplo;
    char caractere;

    printf("o tamanho de num é: %ld bytes \n", sizeof(int));
    printf("o tamanho de real é: %ld bytes\n", sizeof(float));
    printf("o tamanho de duplo é: %ld bytes\n", sizeof(double));
    printf("o tamanho de caractere é: %ld bytes\n", sizeof(char));
    printf("o tamanho de pessoa é: %ld bytes\n", sizeof(pessoa));

    return 1;
}
