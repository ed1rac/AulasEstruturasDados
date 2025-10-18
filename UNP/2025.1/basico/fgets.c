#include <stdio.h>

int main()
{
    char buffer[50];

    printf("Digite um texto: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        printf("Você digitou: %s", buffer);
    }
    else
    {
        printf("Erro lendo a entrada!");
    }

    return 0;
}