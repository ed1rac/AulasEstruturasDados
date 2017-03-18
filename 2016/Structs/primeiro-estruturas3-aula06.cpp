#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012
*/

main(){

    typedef struct{
        int nmat;
        float nota[2];
        float media;
    }Aluno;

    Aluno Mauro; //Cria variável do tipo Aluno
    Aluno Brenda;

    //Atribui valores a variavel Mauro
    Mauro.nmat=456;
    Mauro.nota[0]=7.5;
    Mauro.nota[1]=7.2;
    //Atribui valores a variavel Mauro
    Brenda.nmat=658;
    Brenda.nota[0]=9.5;
    Brenda.nota[1]=7.9;

    //Imprime
    printf("Notas de Mauro\n");
    printf("%g\n", Mauro.nota[0]);
    printf("%g\n", Mauro.nota[1]);
    printf("Notas de Brenda\n");
    printf("%g\n", Brenda.nota[0]);
    printf("%g\n", Brenda.nota[1]);

    //Calcula a media
    Mauro.media =(Mauro.nota[0] + Mauro.nota[1]) / 2.0;

    printf("Media de Mauro\n");
    printf("Matricula: %d\n", Mauro.nmat);
    printf("Media: %.2f\n", Mauro.media);
    //finaliza saindo desta merda
    getchar();
}
