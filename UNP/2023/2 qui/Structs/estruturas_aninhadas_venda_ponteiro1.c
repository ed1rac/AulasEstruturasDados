#include <stdio.h>
#define QL printf("\n")

typedef struct {
  int dia, mes, ano;
}Data;

typedef struct {
    Data data_venda;    
    int qtd_pecas;
    float preco;
}Venda;

int main() {

    Venda venda1 = {04,06,2020, 1, 12.53};
    
    Venda *p_venda;   //---> ponteiro para a um registro do tipo Venda
    p_venda = &venda1;    // p_venda aponta para venda1

    printf("Exibindo a estrutura:"); QL;
    printf("====================="); QL;
    printf("Data: %02d/%02d/%d", venda1.data_venda.dia, venda1.data_venda.mes, venda1.data_venda.ano); QL;
    printf("Quantidade: %d", venda1.qtd_pecas); QL;
    printf("Preço: %.2f", venda1.preco); QL; 

    (*p_venda).qtd_pecas = 5;
     //(*p_venda).preco = 14.55;
    p_venda->preco= 14.55;
    QL;QL;
    
    printf("Quantidade: %d", venda1.qtd_pecas); QL;
    printf("Preço: %.2f", venda1.preco); QL; 
    
    return 0;
}