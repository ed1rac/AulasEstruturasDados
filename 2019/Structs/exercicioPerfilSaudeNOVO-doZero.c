#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pula printf("\n")

typedef struct{
    int dia, mes, ano;
}Data;
typedef struct{
    char nomeCompleto[80];
    char sexo;
    Data dataNasc;
    float altura;
    float peso;
}PerfilSaude;


PerfilSaude lerPerfil();
void exibePerfil(PerfilSaude p);
float calcFreqCardIdeal(float freqCardMax);
int calcFreqCardMax(PerfilSaude p, int anoAtual);
float calculaIMC(float peso, float altura);
int calculaIdade (int anoNasc, int anoAtual);
int lerAnoAtual();

main(){
    /*PerfilSaude a = {"Edkallenn Lima", 'M', {7,7,1980},1.76,92};
    exibePerfil(a);*/
    PerfilSaude perfil;
    int ano, idade, fqMax;
    float imc, fqIdeal;
    perfil = lerPerfil();
    exibePerfil(perfil);
    ano = lerAnoAtual();
    idade = calculaIdade(perfil.dataNasc.ano, ano);
    printf("\nSua idade e': %d", idade);
    printf("\nSeu IMC e': %f", calculaIMC(perfil.peso, perfil.altura));
    fqMax = calcFreqCardMax(perfil, ano);
    printf("\nSua freq. cardiaca Maxima e': %d", fqMax);
    printf("\nSua freq. cardiaca Ideal e': %f", calcFreqCardIdeal(fqMax));
    getchar();
}
void exibePerfil(PerfilSaude p){
    printf("\nNome      : %s", p.nomeCompleto);
	printf("\nSexo      : %c", p.sexo);
	printf("\nNascimento: %02d/%02d/%d",p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano);
	printf("\nAltura    : %.2f",p.altura);
	printf("\nPeso      : %.2f\n\n",p.peso);
}
PerfilSaude lerPerfil(){
    PerfilSaude p;
	printf("\n\nDigite o seu nome completo: "); scanf(" %80[^\n]s",&p.nomeCompleto);
    printf("Digite o seu sexo (M/F): "); scanf(" %c",&p.sexo);
    printf("Digite a data do seu nascimento (dd,mm,aaaa) separada por virgulas: ");
    scanf(" %d, %d, %d", &p.dataNasc.dia, &p.dataNasc.mes, &p.dataNasc.ano);
    printf("Digite a sua altura: "); scanf(" %f", &p.altura);
    printf("Digite o seu peso: "); scanf(" %f", &p.peso);
    return p;
}
int lerAnoAtual(){
    int ano;
    printf("\nEm que ano estamos? (aaaa): ");
    scanf(" %d", &ano);
    return ano;
}
int calculaIdade (int anoNasc, int anoAtual){
    return anoAtual - anoNasc;
}
float calculaIMC(float peso, float altura){
    float imc;
    imc = peso/(altura*altura);
    return imc;
}
int calcFreqCardMax(PerfilSaude p, int anoAtual){
    int freqMax;
    freqMax=220-(anoAtual-p.dataNasc.ano);
    return freqMax;
}
float calcFreqCardIdeal(float freqCardMax){
    float freqIdeal;
    freqIdeal=freqCardMax * 0.75;
    return freqIdeal;
}
