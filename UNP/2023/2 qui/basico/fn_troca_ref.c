#include <stdio.h>
void troca(int *, int *);
void exibe(int num1, int num2);

double potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else {
        return base * potencia(base, exponente - 1);
    }
}


int main()
{
    int num1, num2, aux;
    printf("Digite um número: ");
    scanf(" %d", &num1);
    printf("Digite outro número: ");
    scanf(" %d", &num2);
    printf("ANTES da troca!\n");
    exibe(num1, num2);
    troca(&num1, &num2); // chamada
    printf("\nDEPOIS da troca!\n");
    exibe(num1, num2);

    return 1;
}

void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void exibe(int num1, int num2)
{
    printf("num1 = %d e num2 = %d\n", num1, num2);
}
