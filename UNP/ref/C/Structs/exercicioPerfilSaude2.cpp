/*  Função :Primeiro exemplo de estrutura
    Autor : Edkallenn  - Data : 06/04/2012
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//definicoes de estruturas
typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char NomeCompleto[80];
	char sexo;
	Data dataNasc;
	float Altura;
	float Peso;
}PerfilSaude;

//prototipos
void lerPerfil (PerfilSaude *pont);
void exibePerfil(PerfilSaude *pont);
int lerAnoAtual();
void calcExibeIMC(PerfilSaude *novo);
void calcExibeFreqCardMax(PerfilSaude *novo, int anoAtual);
void calcExibeFreqCardIdeal(PerfilSaude *novo, int anoAtual);

main(){
	int anoAtual;
	char cont;
	PerfilSaude *novo;
    while(1){
        novo =  (PerfilSaude*) malloc(sizeof(PerfilSaude));
        lerPerfil(novo);
        exibePerfil(novo);
        anoAtual = lerAnoAtual();
        printf("OK! Entao estamos no ano de %d! Otimo\n",anoAtual);
        printf("Deixe-me fazer alguns calculos...\nPressione Enter quando pronto...!");
        getchar();
        calcExibeIMC(novo);
        calcExibeFreqCardMax(novo, anoAtual);
        calcExibeFreqCardIdeal(novo, anoAtual);
        printf("\n\nPressione Enter");
        free(novo);
        getchar();
        printf("\nContinuar?(S/N)");
        cont=getche();
        switch(cont){
        case 'N': case 'n':
            exit(0);
        }
        system("cls");
    }
}

void lerPerfil (PerfilSaude *pont){
    printf("\n\nDigite o seu nome completo: "); scanf(" %80[^\n]s",&pont->NomeCompleto);
    printf("Digite o seu sexo (M/F): "); scanf(" %c",&pont->sexo);
    printf("Digite a data do seu nascimento (dd,mm,aaaa) separada por virgulas: ");
    scanf(" %d, %d, %d", &pont->dataNasc.dia, &pont->dataNasc.mes, &pont->dataNasc.ano);
    printf("Digite a sua altura: "); scanf(" %f", &pont->Altura);
    printf("Digite o seu peso: "); scanf(" %f", &pont->Peso);
}
void exibePerfil(PerfilSaude *pont){
    printf("\nNome      : %s", pont->NomeCompleto);
	printf("\nSexo      : %c", pont->sexo);
	printf("\nNascimento: %02d/%02d/%d",pont->dataNasc.dia, pont->dataNasc.mes, pont->dataNasc.ano);
	printf("\nAltura    : %.2f",pont->Altura);
	printf("\nPeso      : %.2f\n\n",pont->Peso);
}
int lerAnoAtual(){
    int ano;
    printf("Em que ano estamos? (aaaa): ");
    scanf(" %d", &ano);
    return ano;
}
void calcExibeIMC(PerfilSaude *novo){
    float imc,imc2;
    printf("\nO indice de massa corporal (IMC) e uma medida internacional\n");
    printf("usada para calcular se uma pessoa esta no peso ideal.\n");
    printf(" IMC 	Classificacao\n");
    printf("===================================\n");
    printf("< 16	        Magreza grave\n");
    printf("16 a < 17	Magreza moderada\n");
    printf("17 a < 18,5	Magreza leve\n");
    printf("18,5 a < 25	Saudavel\n");
    printf("25 a < 30	Sobrepeso\n");
    printf("30 a < 35	Obesidade Grau I\n");
    printf("35 a < 40	Obesidade Grau II (severa)\n");
    printf("    >= 40       Obesidade Grau III (morbida\n");
    imc = novo->Peso/(novo->Altura*novo->Altura);   //calculo do IMC
    imc2= (1.3 * novo->Peso)/(pow(novo->Altura,2.5));
    if(imc<16)
        printf("\n\nSua classificacao, %s,com %.2f eh magreza grave", novo->NomeCompleto, imc);
    if(imc>=16 && imc<17)
        printf("\n\nSua classificacao, %s, com %.2f eh magreza moderada", novo->NomeCompleto, imc);
    if(imc>=17 && imc<18.5)
        printf("\n\nSua classificacao, %s, com %.2f eh Magreza leve", novo->NomeCompleto, imc);
    if(imc>=18.5 && imc<25)
        printf("\n\nSua classificacao, %s, com %.2f eh Saudavel", novo->NomeCompleto, imc);
    if(imc>=25 && imc<30)
        printf("\n\nSua classificacao, %s, com %.2f eh Sobrepeso", novo->NomeCompleto, imc);
    if(imc>=30 && imc<35)
        printf("\n\nSua classificacao, %s, com %.2f eh Obesidade I", novo->NomeCompleto, imc);
    if(imc>=35 && imc<40)
        printf("\n\nSua classificacao, %s, com %.2f eh Obesidade II", novo->NomeCompleto, imc);
    if(imc>=40)
        printf("\n\nSua classificacao, %s, com %.2f eh Obesidade Morbida", novo->NomeCompleto, imc);
    printf("\nNo calculo aprimorado do IMC vc tem %f",imc2);
}
void calcExibeFreqCardMax(PerfilSaude *novo, int anoAtual){
    int feqMax;
    feqMax=220-(anoAtual-novo->dataNasc.ano);
    printf("\nSua frequencia cardiaca maxima eh: %i", feqMax);
}
void calcExibeFreqCardIdeal(PerfilSaude *novo, int anoAtual){
    int feqMax;
    float feqNormal;
    feqMax=220-(anoAtual-novo->dataNasc.ano);
    feqNormal = feqMax*0.75;
    printf("\nSua frequencia cardiaca Ideal = %.2f\n", feqNormal);

}
