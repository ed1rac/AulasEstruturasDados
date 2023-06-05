/* nó da lista para armazenar valores reais */
struct lista
{
    float info;
    struct lista *prox;
};

typedef struct lista Lista;

/* estrutura da pilha */

struct pilha
{
    Lista *prim; /* aponta para o topo da pilha */
};

typedef struct pilha Pilha;

// prototipos
Pilha *pilha_cria(void);
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);