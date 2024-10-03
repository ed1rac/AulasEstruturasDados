/*
 *	Exemplo de implementação de Fila em C
 *	Kelvin S. do Prado com alterações de Prof. Ed em 15/02/2019
 */

#include <stdio.h>

#define MAX 10
#define ERRO -1

typedef int TIPOCHAVE;

typedef struct
{
	TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
	REGISTRO A[MAX + 1];
	int nroRegistros;
} FILA;

void inicializa(FILA *F)
{
	int i = 0;
	for (i = 0; i < MAX - 2; i++)
	{
		F->A[i].chave = i * 2;
	}
	F->nroRegistros = i;
}

void mostraFila(FILA *F)
{
	int i = 0;
	printf("FILA:\n");
	for (i = 0; i < F->nroRegistros; i++)
	{
		printf("[ %d ] ", F->A[i].chave);
	}
	printf("\n\n");
}

int insereFila(TIPOCHAVE ch, FILA *F)
{
	if (F->nroRegistros >= MAX)
		return 0;
	F->A[F->nroRegistros].chave = ch;
	F->nroRegistros++;
	return 1;
}

int removeFila(FILA *F)
{
	if (F->nroRegistros <= 0)
		return 0;
	int i = 1;
	for (i = 1; i < F->nroRegistros; i++)
	{
		F->A[i - 1].chave = F->A[i].chave;
	}
	F->nroRegistros--;
	return 1;
}

int buscaFila(TIPOCHAVE ch, FILA *F)
{
	F->A[F->nroRegistros].chave = ch; // Coloca a ch na ultima posição para fazer busca Sentinela
	int i = 0;
	while (F->A[i].chave != ch)
		i++;
	if (i >= F->nroRegistros)
		return ERRO;
	return i;
}

int main()
{
	FILA fi;
	inicializa(&fi);
	mostraFila(&fi);

	insereFila(15, &fi);
	mostraFila(&fi);

	removeFila(&fi);
	mostraFila(&fi);

	printf("A chave buscada se encontra na posicao %d da fila\n\n", buscaFila(8, &fi));
	return 0;
}