#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// Função para contar os dígitos de um número
long long contar_digitos(int n)
{
    if (n == 0)
        return 1;
    int contador = 0;
    while (n != 0)
    {
        n /= 10;
        contador++;
    }
    return contador;
}

// Função para verificar se um número é um número de Armstrong
bool eh_numero_armstrong(int n)
{
    long original = n;
    long long soma = 0;
    long long num_digitos = contar_digitos(n);
    while (n != 0)
    {
        int digito = n % 10;
        soma += pow(digito, num_digitos);
        n /= 10;
    }
    return original == soma;
}

int main()
{

    int num;
    printf("Digite um número inteiro: ");
    scanf(" %d", &num);
    printf("Números de Armstrong entre 1 e %d:\n", num);
    for (int i = 1; i <= num; i++)
    {
        if (eh_numero_armstrong(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
