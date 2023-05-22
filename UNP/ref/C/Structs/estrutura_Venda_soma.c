#include <stdio.h>
#define QL printf("\n")
typedef struct {    
    int qtd_pecas;
    float preco;
}Venda;

int main() {

    Venda venda1 = {1, 12.53};
    Venda venda2 = {2, 13.17};
    Venda total;    
    total.qtd_pecas = venda1.qtd_pecas + venda2.qtd_pecas;
    total.preco = (venda1.qtd_pecas*venda1.preco) + (venda2.qtd_pecas*venda2.preco);
    printf("Exibindo peças: "); QL;
    printf("================"); QL ;
    printf("Venda 1: "); QL ;
    printf("Quant. de peças.......: %d", venda1.qtd_pecas); QL;
    printf("Preço de cada peça....: %f", venda1.preco); QL;
    printf("================"); QL ;
    printf("Venda 2: "); QL ;
    printf("Quant. de peças.......: %d", venda2.qtd_pecas); QL;
    printf("Preço de cada peça....: %f", venda2.preco); QL;   
    printf("================"); QL ;
    printf("Valor total: Peças --> ");
    printf("Total peças: %d -----> Valor Total: %f", total.qtd_pecas, total.preco);
    return 0;
}