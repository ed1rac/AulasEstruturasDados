#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // tamanho máximo da fila

typedef struct
{
    char nome[50];
} elemento;

typedef struct
{
    elemento vetor[MAX]; // vetor que armazena a fila
    int inicio;          // posição do primeiro elemento
    int fim;             // posição do último elemento
    int quantidade;      // número de elementos na fila
} fila_sequencial;

/**
 * Cria uma nova fila, aloca a sua regiao de memoria,
 * inicializa o inicio, fim e a quantidade de elementos.
 * Por fim, retorna a fila criada.
 * Função para criar uma nova fila
 *
 * @return Fila inicializada
 */

fila_sequencial criar()
{
    fila_sequencial fila;
    fila.inicio = 0;
    fila.fim = -1;
    fila.quantidade = 0;
    return fila;
}

/**
 * Verifica se a fila esta vazia ou nao.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a fila estiver vazia, ou falso (0) caso contrario.
 */

int is_vazia(fila_sequencial *fila)
{
    return fila->quantidade == 0;
}

/**
 * Verifica se a fila esta cheia ou nao.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 *
 * @return Verdadeiro (1) se a fila estiver cheia, ou falso (0) caso contrario.
 */

int is_cheia(fila_sequencial *fila)
{
    return fila->quantidade == MAX;
}

/**
 * Insere um elemento (valor) no final da fila.
 *
 * @param fila ponteiro para a fila, a fila ja deve ter sido inicializada
 * @param valor elemento a ser inserido na fila
 *
 * @return Falso(0) se a fila estiver cheia, caso contrario, retorna Verdadeiro(1)
 */

int inserir(fila_sequencial *fila, elemento valor)
{
    if (is_cheia(fila))
        return 0;

    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;
    fila->quantidade++;
    return 1;
}

// Função para remover um elemento do início da fila
elemento remover(fila_sequencial *fila)
{
    elemento valor = {""};
    if (is_vazia(fila))
        return valor; // Erro: fila vazia

    valor = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->quantidade--;
    return valor;
}

// Função para exibir todos os elementos da fila
void exibir(fila_sequencial *fila)
{
    if (is_vazia(fila))
    {
        printf("Fila vazia\n");
        return;
    }

    printf("\nExibindo fila:\n");
    int i = fila->inicio;
    for (int count = 0; count < fila->quantidade; count++)
    {
        printf("%d: %s\n", i, fila->vetor[i].nome);
        i = (i + 1) % MAX;
    }
}

// Função para exibir os elementos da fila em formato tabular
void mostraFila(fila_sequencial *fila)
{
    if (is_vazia(fila))
    {
        printf("Fila vazia\n");
        return;
    }

    printf("\nFila: ");
    int i = fila->inicio;
    printf("[ ");
    for (int count = 0; count < fila->quantidade; count++)
    {
        printf("%s, ", fila->vetor[i].nome);
        i = (i + 1) % MAX;
    }
    printf("\b\b ]\n");
}

int main()
{
    fila_sequencial minhaFila = criar();

    // Testando inserção
    elemento elem1 = {"Elemento 1"};
    elemento elem2 = {"Elemento 2"};
    elemento elem3 = {"Elemento 3"};
    elemento elem4 = {"Elemento 4"};
    elemento elem5 = {"Elemento 5"};
    elemento elem6 = {"Elemento 6"}; // Para testar a fila cheia

    inserir(&minhaFila, elem1);
    inserir(&minhaFila, elem2);
    inserir(&minhaFila, elem3);
    inserir(&minhaFila, elem4);
    inserir(&minhaFila, elem5);

    // Tentar inserir na fila cheia
    if (!inserir(&minhaFila, elem6))
    {
        printf("A fila está cheia. Nao e possivel inserir '%s'.\n", elem6.nome);
    }

    // Exibir a fila após inserções
    exibir(&minhaFila);
    mostraFila(&minhaFila);

    // Testando remoção
    elemento removido1 = remover(&minhaFila);
    printf("\nRemovido: %s\n", removido1.nome);

    elemento removido2 = remover(&minhaFila);
    printf("Removido: %s\n", removido2.nome);

    // Exibir a fila após remoções
    exibir(&minhaFila);
    mostraFila(&minhaFila);

    // Inserir novamente após remoção para verificar a circularidade
    inserir(&minhaFila, elem6);
    exibir(&minhaFila);
    mostraFila(&minhaFila);

    return 0;
}
