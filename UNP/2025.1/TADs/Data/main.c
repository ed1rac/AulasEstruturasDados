#include <stdio.h>
#include "data.h"

int main()
{
    Data d1 = criarData(15, 3, 2023);
    Data d2 = criarData(1, 1, 2024);

    printf("Data 1: ");
    imprimirData(d1);

    printf("Data 2: ");
    imprimirData(d2);

    int resultado = compararDatas(d1, d2);

    if (resultado == -1)
        printf("Data 1 é mais antiga que Data 2.\n");
    else if (resultado == 1)
        printf("Data 1 é mais recente que Data 2.\n");
    else
        printf("As datas são iguais.\n");

    return 0;
}
