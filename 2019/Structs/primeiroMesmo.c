#include <stdio.h>
#include <stdlib.h>
/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012 */
struct Aluno{
        int nmat;
        float nota[3];
        float media;
};  //escopo global
int main(){
    struct Aluno Felipe; //Cria variável do tipo Aluno
    struct Aluno alunos[10];
    //Atribui valores a variavel 
    Felipe.nmat=456;
    Felipe.nota[0]=7.5;
    Felipe.nota[1]=5.2;
    Felipe.nota[2]=8.4;

    //Imprime
    printf("Notas de Felipe\n");
    printf("%g\n", Felipe.nota[0]);
    printf("%g\n", Felipe.nota[1]);
    printf("%g\n", Felipe.nota[2]);

    //Calcula a media
    Felipe.media =(Felipe.nota[0] + Felipe.nota[1]+Felipe.nota[2]) / 3.0;
    
    //exibe
    printf("Media de Felipe\n");
    printf("Matricula: %d\n", Felipe.nmat);
    printf("Media: %.2f\n", Felipe.media);
    //finaliza saindo deste programa
    getchar();
}
