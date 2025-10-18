#include <stdio.h>

typedef struct
{
    int valor;
} Contador;

void incrementar(Contador *c)
{
    c->valor++;
}

void resetar(Contador *c)
{
    c->valor = 0;
}

int main()
{
    Contador c = {0};
    incrementar(&c);
    incrementar(&c);
    printf("Valor do contador: %d\n", c.valor);
    resetar(&c);
    printf("Valor após reset: %d\n", c.valor);
    return 0;
}
