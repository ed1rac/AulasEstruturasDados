#include <stdio.h>
#include <stdlib.h>
// definição do tipo
typedef struct
{
    float a;
    float b;
} Complexo;
// Funcionalidades
Complexo *cria_complexo();
Complexo adiciona_complexo(Complexo n1, Complexo n2);
Complexo subtrair_complexo(Complexo n1, Complexo n2);
Complexo multiplica_complexo(Complexo n1, Complexo n2);
Complexo divide_complexo(Complexo n1, Complexo n2);
void exibe_complexo(Complexo n1);
Complexo conjugado(Complexo n1);

Complexo *cria_complexo()
{
    Complexo *temp = (Complexo *)malloc(sizeof(Complexo));
    return temp;
}

int main()
{
    Complexo n1;
    exibe_complexo(n1);
}