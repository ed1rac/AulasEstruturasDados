#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012 */
struct Aluno{
        int nmat;
        float nota[3];
        float media;
};
main(){
    struct Aluno Rodrigo; //Cria variável do tipo Aluno
    //Atribui valores a variavel 1
    Rodrigo.nmat=456;
    Rodrigo.nota[0]=7.5;
    Rodrigo.nota[1]=5.2;
    Rodrigo.nota[2]=8.4;

    //Imprime
    printf("Notas de Rodrigo\n");
    printf("%g\n", Rodrigo.nota[0]);
    printf("%g\n", Rodrigo.nota[1]);
    printf("%g\n", Rodrigo.nota[2]);

    //Calcula a media
    Rodrigo.media =(Rodrigo.nota[0] + Rodrigo.nota[1]+Rodrigo.nota[2]) / 3.0;

    printf("Media de Rodrigo\n");
    printf("Matricula: %d\n", Rodrigo.nmat);
    printf("Media: %.2f\n", Rodrigo.media);
    //finaliza saindo deste programa
    getchar();
}
