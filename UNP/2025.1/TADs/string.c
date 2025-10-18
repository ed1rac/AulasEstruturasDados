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

int main()
{
    Palavra p;
    printf("Digite uma palavra: ");
    fgets(p.texto, 100, stdin);
    p.texto[strcspn(p.texto, "\n")] = '\0'; // remove o \n do fgets

    printf("Tamanho: %d\n", tamanho(&p));
    inverter(&p);
    printf("Invertida: %s\n", p.texto);
    return 0;
}
