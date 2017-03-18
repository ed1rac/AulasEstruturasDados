#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012
*/
main(){

    struct Aluno{
        int nmat;
        float nota[2];
        float media;
    };

    Aluno Thiago; //Cria variável do tipo Aluno

    //Atribui valores a variavel 1
    Thiago.nmat=456;
    Thiago.nota[0]=7.5;
    Thiago.nota[1]=7.2;

    //Imprime
    printf("Notas de Thiago\n");
    printf("%g\n", Thiago.nota[0]);
    printf("%g\n", Thiago.nota[1]);

    //Calcula a media
    Thiago.media =(Thiago.nota[0] + Thiago.nota[1]) / 2.0;

    printf("Media de Thiago\n");
    printf("Matricula: %d\n", Thiago.nmat);
    printf("Media: %.2f\n", Thiago.media);
    //finaliza saindo desta merda
    getchar();
}
