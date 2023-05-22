#include <stdlib.h>
#include <stdio.h>
/**
	Nome: Crysdian janke farias
	Data: 29/05/2015
*/
typedef struct {
	int dia;
	char mes[10];
	int ano;
} Data;

typedef struct {
	char nomeCompleto[81];
	char sexo;
	Data nascimento;
	float altura, peso;	
} PerfilSaude;

PerfilSaude * criaEstrutura();
void recebeDados(PerfilSaude *);
int idadeAtual(int);
int frequenciaCardiacaMaxima(int);
float frequenciaCardiacaIdeal(int);
float imc(float, float);
void imprime(PerfilSaude *);
main(void)
{
	PerfilSaude *perfilSaude;
	
	perfilSaude = criaEstrutura();
	recebeDados(perfilSaude);
	imprime(perfilSaude);
	
	printf("\nA sua idade atual: %d", idadeAtual(perfilSaude->nascimento.ano));
	printf("\nA sua frequencia cardiaca maxima: %d", frequenciaCardiacaMaxima(idadeAtual(perfilSaude->nascimento.ano)));
	printf("\nA sua frequencia cardiaca ideal: %.2f", frequenciaCardiacaIdeal(frequenciaCardiacaMaxima(idadeAtual(perfilSaude->nascimento.ano))));
	printf("\nO seu imc: %.2f", imc(perfilSaude->peso, perfilSaude->altura));
	
	printf("\nAbaixo de 17 = abaixo do peso\n");
	printf("Entre 17 e 18,49 = Abaixo do peso\n");
	printf("Entre 18,5 e 24,99 = Peso normal\n");
	printf("Entre 25 e 29,99 = Acima do peso\n");
	printf("Entre 30 e 34,99 = Obesidade I\n");
	printf("Entre 35 e 39,99 = Obesidade II (severa)\n");
	printf("Acima de 40	= Obesidade III (morbida)\n\n");
	
	system("pause");
}
void imprime(PerfilSaude *ps) {
	printf("\nO nome da pessoa: %s", ps->nomeCompleto);
	printf("\nO seu sexo: %c", ps->sexo);
	printf("\nA sua data de nascimento: (%d de %s de %d): ",ps->nascimento.dia, ps->nascimento.mes, ps->nascimento.ano);
	printf("\nA sua altura: %.2f",ps->altura);
	printf("\nO seu peso: %.2f\n\n",ps->peso);
}
float imc(float massa, float altura) {
	return (float) massa / (altura * altura);
}
float frequenciaCardiacaIdeal(int fcm) {
	return (float) (fcm * 0.65 + fcm * 0.85) / 2.0;
}
int frequenciaCardiacaMaxima(int idadeAtual) {
	return 220 - idadeAtual;
}
int idadeAtual(int anoNascimento) {
	return 2015 - anoNascimento;	
}
void recebeDados(PerfilSaude *ps) {
	printf("\nDigite o seu nome completo: ");
	scanf(" %80[^\n]s", &ps->nomeCompleto);
	printf("Digite o seu sexo (m ou f): ");
	scanf(" %c", &ps->sexo);
	printf("Digite o dia do seu nascimento: ");
	scanf("%d", &ps->nascimento.dia);
	printf("Digite o mes do seu nascimento: ");
	scanf(" %9[^\n]s", &ps->nascimento.mes);
	printf("digite o ano de seu nascimento: ");
	scanf("%d", &ps->nascimento.ano);
	printf("Digite a altura: ");
	scanf("%f", &ps->altura);
	printf("Digite o peso: ");
	scanf("%f", &ps->peso);
}
PerfilSaude * criaEstrutura() {
	PerfilSaude *novoPerfil = (PerfilSaude *) malloc (sizeof(PerfilSaude));
	return novoPerfil;
}
