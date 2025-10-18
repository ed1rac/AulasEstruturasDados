#include <stdio.h>
#include "data.h"

Data criarData(int dia, int mes, int ano)
{
    Data d;
    d.dia = dia;
    d.mes = mes;
    d.ano = ano;
    return d;
}

void imprimirData(Data d)
{
    printf("%02d/%02d/%04d\n", d.dia, d.mes, d.ano);
}

int compararDatas(Data d1, Data d2)
{
    if (d1.ano < d2.ano)
        return -1;
    if (d1.ano > d2.ano)
        return 1;

    if (d1.mes < d2.mes)
        return -1;
    if (d1.mes > d2.mes)
        return 1;

    if (d1.dia < d2.dia)
        return -1;
    if (d1.dia > d2.dia)
        return 1;

    return 0;
}
