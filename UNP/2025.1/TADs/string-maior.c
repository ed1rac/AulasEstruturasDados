#include <stdio.h>
#include <string.h>

typedef struct
{
    char texto[100];
} Palavra;

int tamanho(Palavra *p)
{
    return strlen(p->texto);
}

void inverter(Palavra *p)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(p->texto) - 1; i < j; i++, j--)
    {
        temp = p->texto[i];
        p->texto[i] = p->texto[j];
        p->texto[j] = temp;
    }
}

int contar_vogais(Palavra *p)
{
    int count = 0;
    for (int i = 0; p->texto[i] != '\0'; i++)
    {
        char c = tolower(p->texto[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }
    return count;
}

void maiuscula(Palavra *p)
{
    for (int i = 0; p->texto[i] != '\0'; i++)
    {
        p->texto[i] = toupper(p->texto[i]);
    }
}

int palindromo(Palavra *p)
{
    int i, j;
    for (i = 0, j = strlen(p->texto) - 1; i < j; i++, j--)
    {
        if (tolower(p->texto[i]) != tolower(p->texto[j]))
            return 0;
    }
    return 1;
}

int main()
{
    Palavra p;
    printf("Digite uma palavra: ");
    fgets(p.texto, 100, stdin);
    p.texto[strcspn(p.texto, "\n")] = '\0'; // remove o \n do fgets

    printf("Tamanho: %d\n", tamanho(&p));
    printf("Vogais: %d\n", contar_vogais(&p));

    if (palindromo(&p))
        printf("É um palíndromo!\n");
    else
        printf("Não é palíndromo.\n");

    printf("Maiúscula: ");
    maiuscula(&p);
    printf("%s\n", p.texto);

    inverter(&p);
    printf("Invertida: %s\n", p.texto);

    return 0;
}
