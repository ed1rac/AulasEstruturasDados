#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012
*/
main(){

    struct{
        int nmat;
        float nota[3];
        float media;
    } Manoel, Jose, Ana, Joao;

    typedef struct
    {
        int dia;
        char mes[10];
        int ano;
    }Data;

    typedef struct
    {
        int pecas;
        float preco;
        Data diavenda;
    }Venda;

    static Venda A = {20, 110.23, {7, "Novembro", 2012}};

    printf("Pecas: %d\n", A.pecas);
    printf("Preco: %g\n", A.preco);
    printf("Data: %d de %s de %d\n", A.diavenda.dia,
            A.diavenda.mes, A.diavenda.ano);




    Manoel.nmat=456;
    Manoel.nota[0]=7.5;
    Manoel.nota[1]=5.2;
    Manoel.nota[2]=8.4;

    printf("%g\n", Manoel.nota[0]);
    printf("%g\n", Manoel.nota[1]);
    printf("%g\n", Manoel.nota[2]);

    Manoel.media =
    (Manoel.nota[0] + Manoel.nota[1] + Manoel.nota[2]) / 3.0;

    printf("Matricula: %d\n", Manoel.nmat);
    printf("Media: %.2f\n", Manoel.media);

    //printf("Natal: %d, %s, %d\n", natal.dia, natal.mes, natal.ano);

    getchar();
}
