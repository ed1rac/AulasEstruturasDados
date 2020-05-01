#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012
*/

main(){
    typedef float real;
    typedef int inteiro;
    typedef char caractere;
    typedef double duplo;

    struct Aluno{
        inteiro nmat;
        real nota[3];
        real media;
    };

    typedef struct Aluno Aluno;

    Aluno Mauro; //Cria variável do tipo Aluno
    Aluno Ruitemberg;
    Aluno Marlon;

    //Atribui valores a variavel Mauro
    printf("\nDigite a matricula do aluno\n");
    scanf("%d", &Mauro.nmat);
    printf("\nDigite nota do aluno\n");
    scanf("%g", &Mauro.nota[0]);
    printf("\nDigite a nota 2 do aluno\n");
    scanf("%g", &Mauro.nota[1]);
    printf("\nDigite a nota 3 do aluno\n");
    scanf("%g", &Mauro.nota[2]);
    //Imprime
    printf("\n\n%g\n", Mauro.nota[0]);
    printf("%g\n", Mauro.nota[1]);
    printf("%g\n", Mauro.nota[2]);
    //Calcula a media
    Mauro.media =
    (Mauro.nota[0] + Mauro.nota[1] + Mauro.nota[2]) / 3.0;
    //exibe a Media
    printf("\nMatricula: %d\n", Mauro.nmat);
    printf("Media: %.2f\n", Mauro.media);
    //finaliza saindo desta merda
    getchar();
}
