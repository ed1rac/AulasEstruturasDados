// Data.h
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

// Cria uma nova data
Data criarData(int dia, int mes, int ano);

// Imprime a data no formato dd/mm/aaaa
void imprimirData(Data d);

// Compara duas datas
// Retorna:
// -1 se d1 < d2 (mais antiga)
//  0 se d1 == d2
//  1 se d1 > d2 (mais recente)
int compararDatas(Data d1, Data d2);