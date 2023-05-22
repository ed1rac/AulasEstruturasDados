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

void imprime_venda(Venda venda);

int main() {
    Venda venda1 = {04,06,2020, 1, 12.53};
    
    Venda *p_venda;   //---> ponteiro para a um registro do tipo Venda
    p_venda = &venda1;    // p_venda aponta para venda1
    
    imprime_venda(venda1);    
    //alterando o valor via ponteiros
    p_venda->qtd_pecas = 5;    
    p_venda->preco= 14.55;
    imprime_venda(venda1);    //imprimindo novamente via função
    QL;QL;
    return 0;
}

void imprime_venda(Venda venda){
    printf("Exibindo a Venda:");      QL;
    printf("=====================");  QL;
    printf("Data: %02d/%02d/%d", 
            venda.data_venda.dia, 
            venda.data_venda.mes, 
            venda.data_venda.ano
          );                           QL;
    printf("Quantidade: %d", venda.qtd_pecas); QL;
    printf("Preço: %.2f", venda.preco);        QL; 
}