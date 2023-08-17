#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    float qualquercoisa;
    struct node *esquerda;
    struct node *direita;
} node;

node *cria_no(int info)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->info = info;
    new_node->esquerda = NULL;
    new_node->direita = NULL;
    return new_node;
}

node *insere_no(node *root, int info)
{
    if (root == NULL)
    {
        root = cria_no(info);
    }
    else if (info < root->info)
    {
        root->esquerda = insere_no(root->esquerda, info);
    }
    else
    {
        root->direita = insere_no(root->direita, info);
    }
    return root;
}

void print_tree(node *root)
{
    if (root != NULL)
    {
        print_tree(root->esquerda);
        printf("%d ", root->info);
        print_tree(root->direita);
    }
}

// exibe pos-ordem
void print_tree_pos(node *root)
{

    if (root != NULL)
    {
        print_tree_pos(root->esquerda);
        print_tree_pos(root->direita);
        printf("%d ", root->info);
    }
}

// exibe pré-ordem
void print_tree_pre(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        print_tree_pre(root->esquerda);
        print_tree_pre(root->direita);
    }
}

int main()
{
    node *root = NULL;
    root = insere_no(root, 50);
    insere_no(root, 30);
    insere_no(root, 20);
    insere_no(root, 10);
    insere_no(root, 40);
    insere_no(root, 70);
    insere_no(root, 60);
    insere_no(root, 80);
    printf("Exibe em ordem\n====================\n");
    print_tree(root);
    printf("\n\n");
    printf("Exibe em pre-ordem\n====================\n");
    print_tree_pre(root);
    printf("\n\n");
    printf("Exibe em pos-ordem\n====================\n");
    print_tree_pos(root);
    printf("\n\n");
    exibe_tree(root);
    return 0;
}

// função para exibir em formato de arvore
void exibirArvore(node *a)
{
    if (a != NULL)
    {
        printf("%d", a->info);
        printf("(");
        exibirArvore(a->esquerda);
        exibirArvore(a->direita);
        printf(")");
    }
}

void print_tree_helper(node *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    int i;
    // Incrementar a distância entre os níveis
    space += 4;

    // Imprimir o nó da direita primeiro
    print_tree_helper(root->direita, space);

    // Imprimir espaços antes do nó atual
    printf("\n");
    for (i = 4; i < space; i++)
    {
        printf(" ");
    }

    // Imprimir o valor do nó atual
    printf(" %d\n", root->info);

    // Imprimir o nó da esquerda
    print_tree_helper(root->esquerda, space);
}

void exibe_tree(node *root)
{
    print_tree_helper(root, 0);
}
