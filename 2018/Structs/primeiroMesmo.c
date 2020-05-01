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
    struct Aluno Matheus; //Cria variável do tipo Aluno
    //Atribui valores a variavel 1
    Matheus.nmat=456;
    Matheus.nota[0]=7.5;
    Matheus.nota[1]=5.2;
    Matheus.nota[2]=8.4;

    //Imprime
    printf("Notas de Matheus\n");
    printf("%g\n", Matheus.nota[0]);
    printf("%g\n", Matheus.nota[1]);
    printf("%g\n", Matheus.nota[2]);

    //Calcula a media
    Matheus.media =(Matheus.nota[0] + Matheus.nota[1]+Matheus.nota[2]) / 3.0;

    printf("Media de Matheus\n");
    printf("Matricula: %d\n", Matheus.nmat);
    printf("Media: %.2f\n", Matheus.media);
    //finaliza saindo deste programa
    getchar();
}
