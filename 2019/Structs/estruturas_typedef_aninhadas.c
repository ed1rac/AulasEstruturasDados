#include <stdio.h>
#include <stdlib.h>

typedef int inteiro;
typedef float real;

typedef struct {
    int dia; 
    char mes[10];
    int ano; 
}Data;

typedef struct {
        char nome[80];
        inteiro nmat;       // 4 bytes
        real nota[3];  // 12 bytes 
        real media;    // 4 bytes
        Data data_nascimento;
}Aluno;  //escopo global     // Total = 20 bytes
int main(){ 
    Data aniversario = {03, "Dezembro", 2000};  
    Aluno aluno; 
    //lendo os valores do teclado
    printf("Digite o nome do aluno: "); scanf(" %80[^\n]", aluno.nome);
    printf("Digite o número de matrícula: "); scanf(" %d", &aluno.nmat);
    
    printf("Digite o dia do nascimento ('dd'):");
    scanf(" %d", &aluno.data_nascimento.dia); 
    printf("Digite o mês do nascimento ('extenso'):");
    scanf(" %10[^\n]", aluno.data_nascimento.mes); 
    printf("Digite o ano do nascimento ('aaaa'):");
    scanf(" %d", &aluno.data_nascimento.ano); 

    printf("Digite a primeira nota: "); scanf(" %f", &aluno.nota[0]); 
    printf("Digite a segunda nota: "); scanf(" %f", &aluno.nota[1]); 
    printf("Digite a terceira nota: "); scanf(" %f", &aluno.nota[2]); 
    
    printf("Tamanho do registro = %ld bytes\n", sizeof(Aluno));
    printf("\n=====================\nNome: %s\n", aluno.nome);
    printf("Data Nascimento: %d de %s de %d\n", aluno.data_nascimento.dia, aluno.data_nascimento.mes, aluno.data_nascimento.ano);

    printf("Notas de %s\n", aluno.nome);
    printf("%g\n", aluno.nota[0]);
    printf("%g\n", aluno.nota[1]);
    printf("%g\n", aluno.nota[2]);    
    aluno.media =(aluno.nota[0] + aluno.nota[1]+aluno.nota[2]) / 3.0;  
    //exibe
    printf("Media de aluno\n");
    printf("Matricula: %d\n", aluno.nmat);
    printf("Media: %.2f\n", aluno.media); 
    printf("Aniversário: %d de %s de %d ", aniversario.dia, aniversario.mes, aniversario.ano);   
    getchar();
}
