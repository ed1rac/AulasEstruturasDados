

#define MAX 1000
int vet[MAX];

//lista sem cabeca
Lista c, *ini;
   c.prox = NULL;
   ini = &c;
//ou
   Lista *ini;
   ini = malloc( sizeof (celula));
   ini->prox = NULL;



int main (void)
{
    Lista* l;               /* declara uma lista não inicializada */
    l = lst_cria();         /* cria e inicializa lista como vazia */
    l = lst_insere(l, 23);  /* insere na lista o elemento 23 */
    l = lst_insere(l, 45);  /* insere na lista o elemento 45 */
    ...
    return 0;
}


static Lista* aloca (float b, float h)
{
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    Lista* p = (Lista*) malloc(sizeof(Lista));
    r->b = b;
    r->h = h;
    p->info = r;
    p->prox = NULL;
    return p;
}


typedef struct pilha Pilha;

//prototipos
Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);
