/* Função : Exemplo de matriz de estrutruas
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observações: Mostra uma matriz de estruturas
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //para getche()
#define TRUE 1

typedef struct{
    int dia;
    char mes[10];
    int ano;
}Data;

typedef struct {
    Data diavenda;
    int pecas;
    float preco;
}Venda;

//vendas[n].preco
//prototipos das funcoes
void listavenda(void);
void novavenda(void);

Venda vendas[50];   //cria matriz de estruturas
Venda Total = {{0,"",0}, 0, 0.0}; //cria variavel do tipo venda

int n = 0;
main(){
    char ch;
    while(TRUE){
        system("cls");
        printf("Digite I para Inserir uma venda\n");
        printf("       L para Listar as vendas\n");
        printf("       T para Terminar\n");

        ch = getche();  //troca por getchar para usar entrada com Enter
        printf("\n") ;
        switch(ch){
            case 'I': case 'i':
                    novavenda();
                    break;
            case 'L': case 'l':
                    listavenda();
                    getchar();
                    break;
            case 'T': case 't':
                    exit(0);
            default:
                    printf("Opcao Invalida!!\n\n");
        }
    }
    getchar();
    return(0);
}
void novavenda(){
    printf("Dia: "); scanf("%d", &vendas[n].diavenda.dia);
    printf("Mes: "); scanf("%s", vendas[n].diavenda.mes);
    printf("Ano: "); scanf("%d", &vendas[n].diavenda.ano);
    printf("\n");
    printf("Pecas: "); scanf("%d", &vendas[n].pecas);
    printf("Preco: "); scanf("%f", &vendas[n].preco);
    Total.pecas += vendas[n].pecas;
    Total.preco += vendas[n++].preco;
}
void listavenda(){
    int i;
    if(!n){
        puts("Lista Vazia");
        return;
    }
    printf("\n\nRelatorio\n");
    for(i=0; i<n; i++){
        printf("%2d de %10s de %4d", vendas[i].diavenda.dia,
               vendas[i].diavenda.mes, vendas[i].diavenda.ano);
        printf("\nPecas: %10d\t", vendas[i].pecas);
        printf("Preco: %20.2f\n", vendas[i].preco);
    }
    printf("\nTotal");
    printf("%29d", Total.pecas);
    printf("%20.2f\n\n", Total.preco);
}
