#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012
*/
typedef int inteiro;
typedef float real;
typedef char caractere;
typedef struct Aluno aluno;

   struct Aluno{
        inteiro nmat;
        real nota[2];
        real media;
    };

main(){
    aluno Mauro, Weuda, Francisca, Brenda; //Cria variável do tipo Aluno
    //Atribui valores a variavel Mauro
    Mauro.nmat=456;
    Mauro.nota[0]=7.5;
    Mauro.nota[1]=5.2;

    Weuda.nmat=654;
    Weuda.nota[0]=7.3;
    Weuda.nota[1]=7.2;

    Francisca.nmat=666;
    Francisca.nota[0]=6.8;
    Francisca.nota[1]=7.9;

    Brenda.nmat=123;
    Brenda.nota[0]=9.5;
    Brenda.nota[1]=7.8;

    //Imprime
    printf("Notas de Mauro\n");
    printf("%g\n", Mauro.nota[0]);
    printf("%g\n", Mauro.nota[1]);
    printf("Notas de Weuda\n");
    printf("%g\n", Weuda.nota[0]);
    printf("%g\n", Weuda.nota[1]);
    printf("Notas de Francisca\n");
    printf("%g\n", Francisca.nota[0]);
    printf("%g\n", Francisca.nota[1]);
    printf("Notas de Brenda\n");
    printf("%g\n", Brenda.nota[0]);
    printf("%g\n", Brenda.nota[1]);

    //Calcula a media
    Mauro.media =(Mauro.nota[0] + Mauro.nota[1]) / 2.0;
    Weuda.media =(Weuda.nota[0] + Weuda.nota[1]) / 2.0;
    Francisca.media =(Francisca.nota[0] + Francisca.nota[1]) / 2.0;
    Brenda.media =(Brenda.nota[0] + Brenda.nota[1]) / 2.0;
    //exibe a Media
    printf("Media de Mauro\n");
    printf("Matricula: %d\n", Mauro.nmat);
    printf("Media: %.2f\n", Mauro.media);
    printf("Media de Weuda\n");
    printf("Matricula: %d\n", Weuda.nmat);
    printf("Media: %.2f\n", Weuda.media);
    printf("Media de Francisca\n");
    printf("Matricula: %d\n", Francisca.nmat);
    printf("Media: %.2f\n", Francisca.media);
    printf("Media de Brenda\n");
    printf("Matricula: %d\n", Brenda.nmat);
    printf("Media: %.2f\n", Brenda.media);
    //finaliza saindo desta merda
    getchar();
}
