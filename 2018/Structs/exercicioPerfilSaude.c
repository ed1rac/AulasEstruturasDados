#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define pula printf("\n")

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
PerfilSaude lerEstrutura ();
void exibePerfil(PerfilSaude pont);
int lerAnoAtual();
void calcExibeIMC(PerfilSaude novo);
void calcExibeFreqCardMax(PerfilSaude novo, int anoAtual);
void calcExibeFreqCardIdeal(PerfilSaude novo, int anoAtual);

main(){
	PerfilSaude novoPerfil;
	int anoAtual;
	char cont;
    while(1){
    	novoPerfil = lerEstrutura(); pula;
    	exibePerfil(novoPerfil);
    	anoAtual = lerAnoAtual();
    	printf("OK! Entao estamos no ano de %d! Otimo\n",anoAtual);
    	printf("Deixe-me fazer alguns calculos...!\n");
        system("pause");
    	calcExibeIMC(novoPerfil);
    	calcExibeFreqCardMax(novoPerfil, anoAtual);
    	calcExibeFreqCardIdeal(novoPerfil, anoAtual);
    	printf("\n\nPressione Enter"); getche();
    	printf("\nContinuar?(S/N)");
        cont=getche();
        switch(cont){
        case 'N': case 'n':
            exit(0);
        }
        system("cls");
    }

}

PerfilSaude lerEstrutura (){
    PerfilSaude p;
	printf("\n\nDigite o seu nome completo: "); scanf(" %80[^\n]s",&p.NomeCompleto);
    printf("Digite o seu sexo (M/F): "); scanf(" %c",&p.sexo);
    printf("Digite a data do seu nascimento (dd,mm,aaaa) separada por virgulas: ");
    scanf(" %d, %d, %d", &p.dataNasc.dia, &p.dataNasc.mes, &p.dataNasc.ano);
    printf("Digite a sua altura: "); scanf(" %f", &p.Altura);
    printf("Digite o seu peso: "); scanf(" %f", &p.Peso);
    return p;
}
void exibePerfil(PerfilSaude p){
    printf("\nNome      : %s", p.NomeCompleto);
	printf("\nSexo      : %c", p.sexo);
	printf("\nNascimento: %02d/%02d/%d",p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano);
	printf("\nAltura    : %.2f",p.Altura);
	printf("\nPeso      : %.2f\n\n",p.Peso);
}
int lerAnoAtual(){
    int ano;
    printf("\nEm que ano estamos? (aaaa): ");
    scanf(" %d", &ano);
    return ano;
}
void calcExibeIMC(PerfilSaude p){
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
    imc = p.Peso/(p.Altura*p.Altura);   //calculo do IMC
    imc2= (1.3 * p.Peso)/(pow(p.Altura,2.5));
    if(imc<16)
        printf("\n\nSua classificacao, %s,com %.2f eh magreza grave", p.NomeCompleto, imc);
    if(imc>=16 && imc<17)
        printf("\n\nSua classificacao, %s, com %.2f eh magreza moderada", p.NomeCompleto, imc);
    if(imc>=17 && imc<18.5)
        printf("\n\nSua classificacao, %s, com %.2f eh Magreza leve", p.NomeCompleto, imc);
    if(imc>=18.5 && imc<25)
        printf("\n\nSua classificacao, %s, com %.2f eh Saudavel", p.NomeCompleto, imc);
    if(imc>=25 && imc<30)
        printf("\n\nSua classificacao, %s, com %.2f eh Sobrepeso", p.NomeCompleto, imc);
    if(imc>=30 && imc<35)
        printf("\n\nSua classificacao, %s, com %.2f eh Obesidade I", p.NomeCompleto, imc);
    if(imc>=35 && imc<40)
        printf("\n\nSua classificacao, %s, com %.2f eh Obesidade II", p.NomeCompleto, imc);
    if(imc>=40)
        printf("\n\nSua classificacao, %s, com %.2f eh Obesidade Morbida", p.NomeCompleto, imc);
    printf("\nNo calculo aprimorado do IMC vc tem %f",imc2);
}
void calcExibeFreqCardMax(PerfilSaude p, int anoAtual){
    int feqMax;
    feqMax=220-(anoAtual-p.dataNasc.ano);
    printf("\nSua frequencia cardiaca maxima eh: %i", feqMax);
}
void calcExibeFreqCardIdeal(PerfilSaude p, int anoAtual){
    int feqMax;
    float feqNormal;
    feqMax=220-(anoAtual-p.dataNasc.ano);
    feqNormal = feqMax*0.75;
    printf("\nSua frequencia cardiaca Ideal = %.2f\n", feqNormal);

}
