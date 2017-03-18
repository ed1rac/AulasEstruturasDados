
typedef struct lista Lista;

Lista* lst_cria(void);
Lista* lst_insere(Lista* l, int i);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
Lista* lst_busca(Lista* l, int v);
Lista* lst_retira(Lista* l, int v);
void lst_libera (Lista* l);
