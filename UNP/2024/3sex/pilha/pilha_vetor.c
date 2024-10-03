#include <stdio.h>
#include <stdlib.h>

#define TAM 50

typedef struct pilha Stack;

struct pilha
{
    int n; // primeira posição livre do array. n é o tamanho da pilha
    int array[TAM];
};
// elemento array[n-1] é o TOPO da pilha
// n é a primeira/próxima posição livre no vetor (array) - array[n]
// array[0]  a array[TAM-1] são as posições ocupáveis da pilha

Stack *create_stack()
{
    Stack *s = malloc(sizeof(Stack));
    s->n = 0;
    return s;
}
void push(Stack *s, int value)
{
    if (s->n == TAM)
    {
        printf("Stack overflow - estouro de pilha!\n");
        exit(1);
    }
    // insere o elemento na próxima posição livre
    s->array[s->n] = value;
    s->n++;
}
int empty_stack(Stack *s)
{
    // retorna se vazia
    return (s->n == 0);
}
int pop(Stack *s)
{
    int valor;
    if (empty_stack(s))
    {
        printf("Pilha vazia!\n");
        exit(1);
    }
    valor = s->array[s->n - 1];
    s->n--;
    return valor;
}

void peek(Stack *s)
{
    if (empty_stack(s))
    {
        printf("Pilha vazia!\n");
        exit(1);
    }
    printf("Topo da pilha: %d\n", s->array[s->n - 1]);
}

void erase_stack(Stack *s)
{
    // libera a memória alocada para a pilha
    free(s);
}

void print_stack(Stack *s)
{
    int i;
    printf("Impressao da pilha:\n[ ");
    for (i = s->n - 1; i >= 0; i--)
    {
        printf("%d, ", s->array[i]);
    }
    printf("\b\b ]\n");
}

void limpa_tela()
{
    // system("clear");   //no replit ou linux ou mac
    system("pause");
    system("cls");
}

int main()
{
    // menu para manipular a pilha
    int opcao, valor;
    Stack *s = create_stack();
    do
    {
        printf("1 - Empilhar elemento\n");
        printf("2 - Desempilhar elemento\n");
        printf("3 - Verificar elemento do topo\n");
        printf("4 - Imprimir a pilha inteira\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf(" %d", &valor);
            push(s, valor);
            limpa_tela();
            break;
        case 2:
            print_stack(s);
            valor = pop(s);
            printf("Valor desempilhado: %d\n", valor);
            getchar();
            limpa_tela();
            break;

        case 3:
            peek(s);
            getchar();
            limpa_tela();
            break;

        case 4:
            print_stack(s);
            getchar();
            limpa_tela();
            break;

        case 5:
            printf("Saindo . . .\n");
            break;

        default:
            printf("Opcao invalida!");
            getchar();
            limpa_tela();
            break;
        }
    } while (opcao != 5);
    erase_stack(s);
    return 0;
}
