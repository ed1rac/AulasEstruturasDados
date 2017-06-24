#include <stdio.h>
#include <stdlib.h>
#define MAX 5
/*  Função :Array de estruturas
    Autor : Edkallenn  - Data : 09/06/2017 às 20:12 porque Edson nao acreditou
*/
typedef float real; typedef int inteiro;
typedef char caractere; typedef double duplo;

typedef struct aluno{
    inteiro nmat;
    real nota[2];
    real media;
}Aluno;

void le_alunos(Aluno *);
void exibe_alunos(Aluno []);

main(){
    //declara o vetor de alunos
    Aluno alunos[MAX];

    le_alunos(alunos);      //le os alunos via teclado
    exibe_alunos(alunos);   //exibe os alunos já com as médias 

    getchar();
    return 1;
}
void le_alunos(Aluno alunos[]){
    int i;
    for(i=0;i<MAX;i++){
        printf("\nDigite a matricula do aluno %d:", i+1);
        scanf("%d", &alunos[i].nmat);
        printf("Digite a N1 do aluno %d: ", i+1);
        scanf("%g", &alunos[i].nota[0]);
        printf("Digite a N2 do aluno %d: ", i+1);
        scanf("%g", &alunos[i].nota[1]); printf("\n");
        alunos[i].media=(alunos[i].nota[0]+alunos[i].nota[1])/2;
    }
}
void exibe_alunos(Aluno alunos[]){
    //Imprime
    int i;
    for(i=0;i<MAX;i++){
        printf("\n\nMatrícula:\t%d\n", alunos[i].nmat);
        printf("Nota da N1:\t%.2f\n", alunos[i].nota[0]);
        printf("Nota da N2:\t%.2f\n", alunos[i].nota[1]);
        printf("Média:\t\t%.3f\n", alunos[i].media);
    }
}