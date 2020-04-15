#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Alocação dinâmica de estruturas
typedef struct aluno{
        int nmat;
        char nome[50];
        char sobrenome[50];
        float nota[3];
        float media;
}Aluno;
int main(){
    printf("Aluno tem %d bytes", sizeof(Aluno));
    Aluno* pt_aluno;
    Aluno* alunos;
    pt_aluno = (Aluno*) malloc(sizeof(Aluno));
    alunos = (Aluno*) malloc(10*sizeof(Aluno));
    
    alunos[0].nmat = 321;
    

    pt_aluno->nmat = 123;
    strcpy(pt_aluno->nome,"Matheus");
    strcpy(pt_aluno->sobrenome, "Campos");
    pt_aluno->nota[0]=8.0;
    pt_aluno->nota[1]=9.6;
    pt_aluno->nota[2]=9.0;
    pt_aluno->media=(pt_aluno->nota[0]+pt_aluno->nota[1]+pt_aluno->nota[2])/3;
    //exibindo
    printf("\n\nExibindo a estrutura");
    printf("\n====================");
    printf("\nMat........:\t%d", pt_aluno->nmat);
    printf("\nNome.......:\t%s", pt_aluno->nome);
    printf("\nSobrenome..:\t%s", pt_aluno->sobrenome);
    printf("\nNota N1.....:\t%.2f", pt_aluno->nota[0]);
    printf("\nNota N2.....:\t%.2f", pt_aluno->nota[1]);
    printf("\nNota N3.....:\t%.2f", pt_aluno->nota[2]);
    printf("\nMédia.......:\t%.2f", pt_aluno->media);
    printf("\n====================");
    
    //finaliza saindo deste programa
    getchar();
}