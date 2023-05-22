#include "stdio.h"

/*

    Função : Funcao que executa o operador lógico XOR que nao existe nativamente em C
    Autor : Edkallenn
    Data : 06/04/2012
    Observações: O resultado de uma operacao XOR é verdadeiro, se, e somente se, um operando
    mas nao os dois for verdadeiro. A funcao xor() devolve o resultado de uma operacao
    XOR ou OU EXCLUSIVO realizada em dois argumentos

*/

int xor(int a, int b);

main()
{
    printf("TABELA VERDADE DO OPERADOR XOR - OU EXCLUSIVO\n\n");
    printf("%d xor %d = %d\n", 1, 0, xor(1,0));
    printf("%d xor %d = %d\n", 1, 1, xor(1,1));
    printf("%d xor %d = %d\n", 0, 1, xor(0,1));
    printf("%d xor %d = %d\n", 0, 0, xor(0,0));
}

int xor(int a, int b)
{
    return (a||b) && !(a && b);

}
