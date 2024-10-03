#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento *proximo;
} Elemento;

typedef struct lista
{
    Elemento *inicio;
    int tamanho;
} Lista;

// protótipos
Lista *cria_lista();
void adiciona(Lista *l1, int num);
int vazia(Lista *l1);
int get(Lista *l, int posicao);
void adiciona_pos(Lista *l, int num, int posicao);
void set(Lista *l, int num, int posicao);
int tamanho(Lista *l);
int delete(Lista *l, int posicao);
void aguarda();
void lista_imprime(Lista *l1);

void lista_imprime(Lista *l1)
{
    if (!vazia(l1))
    {
        printf("lista = [ ");

        Lista *temp = l1;
        Elemento *e_temp;

        for (e_temp = temp->inicio; e_temp != NULL; e_temp = e_temp->proximo)
        {
            printf("%d, ", e_temp->valor);
        }
        printf("\b\b ]\n");
        aguarda();
    }
    else
    {
        printf("A lista está vazia\n");
        aguarda();
    }
}

void aguarda()
{
    // system("pause");
    system("read -p 'Pressione Enter para continuar...' var");
}

Lista *cria_lista()
{
    Lista *l1 = malloc(sizeof(Lista));
    l1->inicio = NULL;
    l1->tamanho = 0;

    return l1;
}

void adiciona(Lista *l1, int num)
{
    if (vazia(l1))
    {
        Elemento *e1 = malloc(sizeof(Elemento));
        e1->valor = num;
        e1->proximo = NULL;

        l1->inicio = e1;
    }
    else
    {
        Elemento *e1 = malloc(sizeof(Elemento));
        e1->valor = num;

        Elemento *antigo_inicio = l1->inicio;
        l1->inicio = e1;
        e1->proximo = antigo_inicio;
    }
    l1->tamanho = l1->tamanho + 1;
}
int vazia(Lista *l1)
{
    return l1->tamanho == 0;
    // ou return l1->inicio == NULL;
}

void adiciona_pos(Lista *l, int num, int posicao)
{
    /* Verificar se a lista está vazia. Se sim, não temos como
        adicionar em nenhuma posição; */
    if (vazia(l))
    {
        printf("Lista vazia. Adiciona posicional não permitido!\n");
        return;
    }
    if (posicao > l->tamanho || posicao <= 0)
    { /*Se não estiver vazia, é necessário validar a posição;*/
        printf("Posição inválida!\n");
        return;
    }
    if (posicao == 1)
    {
        /* Caso a posição seja válida e seja, então o adiciona_pos pode se comportar como o adiciona  e tal função é executada; */
        adiciona(l, num);
        return;
    }
    /*
    Caso a posição não seja 1, então temos que detectar o local onde a inserção será realizada Para isso, inicialmente criamos um ponteiro auxiliar para começar a navegar na lista a partir de seu início (Elemento *e_atual = l->inicio;) e também criamos um ponteiro que auxiliará no momento da inserção (Elemento *e_anterior; ), para manter a lista íntegra;
    */
    Elemento *e_atual = l->inicio;
    Elemento *e_anterior;
    Elemento *e = malloc(sizeof(Elemento)); /*O novo Elemento é criado (Elemento *e = malloc(sizeof(Elemento)); ) para armazenar um novo valor ( e->valor = num; ) que será inserido na lista;*/
    e->valor = num;
    int i; /* Neste ponto, é feita a procura pela posição de inserção. Para isso, navegamos até acharmos a posição desejada ( for (i = 1; i < posicao ; i++)). Enquanto essa navegação é realizada, ficamos movimentando os ponteiros auxiliares e_anterior e
    e_atual para que eles se posicionem antes (e_anterior ) e depois (e_atual) da posição de inserção;*/
    for (i = 1; i < posicao; i++)
    {
        e_anterior = e_atual;
        e_atual = e_atual->proximo;
    }
    e_anterior->proximo = e; /*Quando a posição é atingida, então o próximo do anterior recebe o novo elemento (e_anterior->proximo = e; ) e o próximo do novo elemento recebe o atual (e->proximo = e_atual;). */
    e->proximo = e_atual;
    l->tamanho = l->tamanho + 1; /*Incrementa o tamanho*/
}

int get(Lista *l, int posicao)
{
    if (vazia(l))
    { /*I*/
        printf("Lista vazia.\n");
        return -1;
    }
    if (posicao > l->tamanho || posicao <= 0)
    { /*II*/
        printf("Posição inválida!\n");
        return -1;
    }
    int i = 1; /*III*/
    Elemento *e = l->inicio;
    while (e->proximo != NULL)
    {
        if (i == posicao)
        {
            return e->valor;
        }
        else
        {
            e = e->proximo;
            i++;
        }
    }
    return -1; /*IV*/
}
/*
O código anterior é responsável por:
I. Verificar se a lista é vazia. Se for, não temos como obter elementos de nenhuma posição;
II. Se não for vazia, precisamos saber se é uma posição válida;
III. Se tudo estiver certo, então a procura pela posição e, consequentemente, do elemento é iniciada.  Para isso, vamos para o início da lista (Elemento *e = l->inicio; ) e navegamos por ela enquanto ela não acabar (while(e->proximo != NULL) ). Se atingirmos a posição desejada (if (i == posicao)), o valor do elemento que corresponde à posição é retornado (return e->valor ); se não, passamos para o próximo elemento e incrementamos a posição (e = e->proximo; e i++; );
IV. Se este ponto do código for atingido, é sinal de que algo "deu errado" e a posição não foi encontrada. Assim, -1 é retornado.
*/

void set(Lista *l, int num, int posicao)
{
    if (vazia(l))
    { /*I*/
        printf("Lista vazia.	Set	não	permitido!\n");
        return;
    }
    if (posicao > l->tamanho || posicao <= 0)
    { /*II*/
        printf("Posição	inválida!\n");
        return;
    }
    int i = 1; /*III*/
    Elemento *e = l->inicio;
    while (e->proximo != NULL)
    {
        if (i == posicao)
        {
            e->valor = num;
            return;
        }
        else
        {
            e = e->proximo;
            i++;
        }
    }
}
/*
O	código	anterior é responsável por:
I. Verificar se a lista é vazia. Se for, não temos como modificar elementos de nenhuma posição;
II. Se não for vazia, precisamos saber se é uma posição válida;
III. Se tudo estiver certo, então a procura pela posição e o elemento a ser atualizado é iniciada. Para isso, vamos para o início
da lista ( Elemento *e = l->inicio; ) e navegamos por ela
enquanto ela não acabar ( while (e->proximo != NULL) ). Se
atingirmos a posição desejada ( if (i == posicao) ), o valor do
elemento que corresponde à posição é alterado ( e->valor =
nume; ). Se não, passamos para o próximo elemento e
incrementamos a posição ( e = e->proximo;  e  i++; ).
É válido ressaltar que, como validações de vazio e posição são
feitas de forma prévia, se o ponto III é atingido, com certeza um
elemento terá seu valor alterado.
*/

int delete(Lista *l, int posicao)
{
    if (vazia(l))
    { /*I*/
        printf("Lista	vazia.	Delete	não	permitido!\n");
        return '\0';
    }
    if (posicao > l->tamanho || posicao <= 0)
    { /*II*/
        printf("Posição	inválida!\n");
        return '\0';
    }
    if (posicao == 1)
    { /*III*/
        Elemento *e = l->inicio;
        int num = e->valor;
        l->inicio = l->inicio->proximo;
        free(e);
        l->tamanho = l->tamanho - 1;
        return num;
    }
    else
    {
        Elemento *e_atual = l->inicio; /*IV*/
        Elemento *e_anterior;
        int i; /*V*/
        for (i = 1; i < posicao; i++)
        {
            e_anterior = e_atual;
            e_atual = e_atual->proximo;
        }
        e_anterior->proximo = e_atual->proximo; /*VI*/
        int num = e_atual->valor;
        free(e_atual);
        l->tamanho = l->tamanho - 1;
        return num;
    }
}
/*
O código anterior é responsável por:
I. Verificar se a lista é vazia. Se for, não temos como excluir
elementos de nenhuma posição;
II. Se não for vazia, precisamos saber se é uma posição válida;
III. Se a posição for 1 , então estamos excluindo o primeiro
elemento da lista. Assim, criamos um elemento para armazenar o
início a ser excluído ( Elemento *e = l->inicio; ), obtemos o
seu valor ( int num = e->valor; ) e, por fim, passamos o
início da lista para o  proximo  do início excluído ( l->elemento
= l->inicio->proximo ). Antes de retornar o valor excluído
( return num; ), eliminamos o elemento da memória
( free(e); ) e decrementamos a quantidade de elementos da lista
( l->tamanho = l->tamanho - 1; );
IV. Entretanto, se não for a posição  1 , temos que encontrar a
posição a ser excluída. Para isso, inicialmente criamos um ponteiro
auxiliar para começar a navegar na lista a partir de seu início
( Elemento *e_atual = l->elemento; ) e também criamos um
ponteiro que auxiliará no momento da exclusão ( Elemento
*e_anterior; ), para manter a lista íntegra;
V. Neste ponto, é feita a procura pela posição de exclusão. Para
isso, navegamos até acharmos a posição desejada ( for (i = 1; i
< posicao ; i++) ). Enquanto essa navegação é realizada,
ficamos movimentando os ponteiros auxiliares e_anterior e
 e_atual para que eles se posicionem antes ( e_anterior ) e
depois ( e_atual ) da posição a ser excluída;
VI. Quando a posição é atingida, os auxiliares  e_anterior  e
 e_atual  ficaram configurados para que o  próximo  do anterior
receba o  proximo  do atual ( e_anterior->proximo = e_atual-
>proximo; ). Isso é necessário para a lista permanecer íntegra.
Após isso, o valor excluído deve ser guardado para ser retornado
( int num = e_atual->valor; ). O elemento a ser
excluído é liberado da memória ( free(e_atual); ) e, por fim, a quantidade de elementos é decrementada em 1 ( l->tamanho =
l->tamanho - 1; ) e o valor excluído é retornado ( return
num; )

*/

int tamanho(Lista *l)
{
    return l->tamanho; /*I*/
}

int main()
{
    Lista *minha_lista = cria_lista();

    // Adicionando elementos à lista
    adiciona(minha_lista, 10);
    adiciona(minha_lista, 20);
    adiciona(minha_lista, 30);

    // Imprimindo a lista
    printf("Lista após adicionar elementos:\n");
    lista_imprime(minha_lista);

    // Adicionando elemento em uma posição específica
    adiciona_pos(minha_lista, 15, 2);

    // Imprimindo a lista após adicionar um elemento na posição 2
    printf("\nLista após adicionar 15 na posição 2:\n");
    lista_imprime(minha_lista);

    // Obtendo o valor de um elemento em uma posição específica
    int valor = get(minha_lista, 3);
    printf("\nValor na posição 3: %d\n", valor);

    // Modificando o valor de um elemento em uma posição específica
    set(minha_lista, 25, 3);

    // Imprimindo a lista após modificar o valor na posição 3
    printf("\nLista após modificar o valor na posição 3:\n");
    lista_imprime(minha_lista);

    // Excluindo um elemento em uma posição específica
    int valor_excluido = delete (minha_lista, 2);
    printf("\nValor excluído da posição 2: %d\n", valor_excluido);

    // Imprimindo a lista após excluir o elemento na posição 2
    printf("\nLista após excluir o elemento na posição 2:\n");
    lista_imprime(minha_lista);

    // Imprimindo o tamanho da lista
    printf("\nTamanho da lista: %d\n", tamanho(minha_lista));

    // Liberando a memória alocada
    free(minha_lista);

    return 0;
}
