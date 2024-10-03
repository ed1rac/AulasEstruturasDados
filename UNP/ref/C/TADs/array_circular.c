#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 10

typedef struct {
    int array[TAMANHO_MAXIMO];
    int inicio, fim, quantidade;
} ArrayCircular;

ArrayCircular* criarArrayCircular() {
    ArrayCircular *ac = (ArrayCircular*) malloc(sizeof(ArrayCircular));
    ac->inicio = 0;
    ac->fim = TAMANHO_MAXIMO - 1;
    ac->quantidade = 0;
    return ac;
}

int estaVazia(ArrayCircular *ac) {
    return ac->quantidade == 0;
}

int estaCheio(ArrayCircular *ac) {
    return ac->quantidade >= TAMANHO_MAXIMO;
}

int tamanho(ArrayCircular *ac) {
    return ac->quantidade;
}

void inserir(ArrayCircular *ac, int p) {
    if (!estaCheio(ac)) {
        ac->array[ac->inicio] = p;
        ac->inicio = (ac->inicio + 1) % TAMANHO_MAXIMO;
        ac->quantidade++;
    }
}

void inserirCauda(ArrayCircular *ac, int p) {
    if (!estaCheio(ac)) {
        ac->array[ac->fim] = p;
        ac->fim = (ac->fim - 1 + TAMANHO_MAXIMO) % TAMANHO_MAXIMO;
        ac->quantidade++;
    }
}

int remover(ArrayCircular *ac) {
    if (estaVazia(ac))
        return -1; // Ou outro valor que indique que a remoção falhou
    ac->quantidade--;
    int valorRemovido = ac->array[ac->inicio];
    ac->inicio = (ac->inicio + 1) % TAMANHO_MAXIMO;
    return valorRemovido;
}

int removerCauda(ArrayCircular *ac) {
    if (estaVazia(ac))
        return -1; // Ou outro valor que indique que a remoção falhou
    ac->quantidade--;
    int valorRemovido = ac->array[ac->fim];
    ac->fim = (ac->fim - 1 + TAMANHO_MAXIMO) % TAMANHO_MAXIMO;
    return valorRemovido;
}

void exibirElementos(ArrayCircular *ac) {
    if (estaVazia(ac)) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos da lista: \n===========================\n");

    // Percorre todos os elementos do array circular
    int indice = ac->inicio;
    for (int i = 0; i < ac->quantidade; i++) {
        printf("Índice %d: %d\n", indice, ac->array[indice]);

        // Avança para o próximo índice circularmente
        indice = (indice + 1) % TAMANHO_MAXIMO;
    }
}

int main() {
    ArrayCircular *ac = criarArrayCircular();

    // Exemplo de uso
    inserir(ac, 1);
    inserir(ac, 2);
    inserir(ac, 3);

    exibirElementos(ac);

    free(ac);
    return 0;
}
