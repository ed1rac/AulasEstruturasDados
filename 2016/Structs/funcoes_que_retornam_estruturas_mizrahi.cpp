/* Função : Exemplo de funcoes que retornam estruturas
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações: Mostra passagem de estruturas para funcoes
/ por valor e mostra uma funcao que retorna uma estrutura
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Venda{
    int pecas;
    float preco;
}Venda;
Venda TotalVendas( Venda C, Venda D); //prototipo
main(){
    Venda A, B, Total;

    printf("Venda A\n=======\n");   //07 iguais
    printf("Insira o numero de pecas: ");
    scanf("%d", &A.pecas);
    printf("Insira o preco: ");
    scanf("%f", &A.preco);

    printf("Venda B\n=======\n");
    printf("Insira o numero de pecas: ");
    scanf("%d", &B.pecas);
    printf("Insira o preco: ");
    scanf("%f", &B.preco);
    Total = TotalVendas(A,B); //esttruturas como argumento
                              //e retorno
    printf("\n\nVenda Total\n==========="); //11 iguais
    printf("\nTotal de pecas: %d", Total.pecas);
    printf("\nPreco Total   : %.2f\n", Total.preco);

    getchar();
    return(0);
}
Venda TotalVendas(Venda C, Venda D){
    Venda T;
    T.pecas = C.pecas + D.pecas;
    T.preco = C.preco + D.preco;
    return T;
}
