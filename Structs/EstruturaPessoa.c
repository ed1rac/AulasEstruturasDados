#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    char rua[80];
    int num;
    char bairro[50];
    char cep[9];
}Endereco;

typedef struct{
    int n_id;
    char nome[80];
    char telefone[11];
    Endereco ender;
    Data dnasc;
}Pessoa;

main(){
    Pessoa Pericles, Aline;

    puts("Programa para testar o teste testador testado pelo tester");
    puts("");
    puts("Digite o codigo da criatura");
    scanf("%d", &Pericles.n_id);
    puts("Digite o nome da criatura: ");
    scanf(" %s", Pericles.nome);
    puts("Digite o tel da criatura: ");
    scanf(" %s",Pericles.telefone);
    puts("Digite a rua da criatura: ");
    scanf(" %s",Pericles.ender.rua);
    puts("Digite o numero da rua da criatura: ");
    scanf("%d", &Pericles.ender.num);
    puts("Digite o bairro da criatura: ");
    scanf(" %s", Pericles.ender.bairro);
    puts("Digite o cep da criatura: ");
    scanf(" %s",Pericles.ender.cep);
    puts("Digite o dia da data de nascimento da criatura: ");
    scanf("%d", &Pericles.dnasc.dia);
    puts("Digite o mes da data de nascimento da criatura: ");
    scanf("%d", &Pericles.dnasc.mes);
    puts("Digite o ano da data de nascimento da criatura: ");
    scanf("%d", &Pericles.dnasc.ano);
/*
        puts("Programa para testar o teste testador testado pelo tester");
    puts("");
    puts("Digite o codigo da criatura");
    scanf("%d", &Aline.n_id);
    puts("Digite o nome da criatura: ");
    gets(Aline.nome);
    puts("Digite o tel da criatura: ");
    gets(Aline.telefone);
    puts("Digite a rua da criatura: ");
    gets(Aline.ender.rua);
    puts("Digite o numero da rua da criatura: ");
    scanf("%d", &Aline.ender.num);
    puts("Digite o bairro da criatura: ");
    gets(Aline.ender.bairro);
    puts("Digite o cep da criatura: ");
    gets(Aline.ender.cep);
    puts("Digite o dia da data de nascimento da criatura: ");
    scanf("%d", &Aline.dnasc.dia);
    puts("Digite o mes da data de nascimento da criatura: ");
    scanf("%d", &Aline.dnasc.mes);
    puts("Digite o ano da data de nascimento da criatura: ");
    scanf("%d", &Aline.dnasc.ano);
*/
    puts("");puts("");

    printf("\nID:\t %d", Pericles.n_id);
    printf("\nNome:\t %s", Pericles.nome);
    printf("\nTelefone:\t %s", Pericles.telefone);
    printf("\nRua:\t %s", Pericles.ender.rua);
    printf("\nNumero:\t %d", Pericles.ender.num);
    printf("\nBairro:\t %s", Pericles.ender.bairro);
    printf("\ncep:\t %s", Pericles.ender.cep);
    printf("\nDia: %d\tMes: %d\tAno: %d",Pericles.dnasc.dia, Pericles.dnasc.mes, Pericles.dnasc.ano);

    puts("");puts("");
    getchar();
}
