/*  Função : Exemplo do uso de Arvores Binarias
    Autor : Edkallenn
    Data : 10/06/2015
    Observações: Implementacoes recursivas. Info ´e um char.
*/
#include <stdio.h>
#include <stdlib.h>

struct arv {
    char info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;     //definicao do tipo

//prototipos
void pula(int n);
Arv* criaArvVazia(void);
Arv* criaArvore(char c, Arv* esq, Arv* dir);
int arvoreVazia(Arv* a);
void imprimeArv(Arv* a);
void imprimeArvNotacao(Arv* a);
Arv* liberaArvore(Arv* a);
int buscaArvore(Arv* a, char c);
void imprimeArvPosOrdem(Arv* a);
void imprimeArvEmOrdem(Arv*);
int maiorDois (int a, int b);
int alturaArvore(Arv* a);
void mostraArvore(Arv* a, int b);
void imprimeNo(char c, int b);
void exibicoesArvores(Arv*);

void imprimeNoDiferente(char c, int b);
void mostraArvoreDiferente(Arv* a, int b);
 

Arv* criaArvVazia(void){
    return NULL;
}

Arv* criaArvore(char c, Arv* esq, Arv* dir){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

main(){
    //sub-árvore d
    Arv* a1 = criaArvore('d',criaArvVazia(),criaArvVazia());
    //sub-árvore b
    Arv* a2 = criaArvore('b',criaArvVazia(),a1);
    //sub-árvore e
    Arv* a3 = criaArvore('e',criaArvVazia(),criaArvVazia());
    //sub-árvore f
    Arv* a4 = criaArvore('f',criaArvVazia(),criaArvVazia());
    //sub-árvore c
    Arv* a5 = criaArvore('c',a3,a4);
    //Árvore A
    Arv* a = criaArvore('a',a2,a5);
    /*
    A mesma arvore poderia ser criada assim:
    Arv* a = criaArvore('a',criaArvore('b',
                                       criaArvVazia(),
                                       criaArvore('d',criaArvVazia(),criaArvVazia())
                                       ),
                        criaArvore('c',criaArvore('e',criaArvVazia(),criaArvVazia()),
                                   criaArvore('f',criaArvVazia(),criaArvVazia())
                                   )
                        );
    */
    exibicoesArvores(a);  //exibicoes em pré-ordem
    printf("\nAcrescentando itens de forma recursiva!\n");
    printf("Pressione Enter quando estiver pronto");
    getchar();
    //pode-se acrescentar nós da seguinte forma (usando a definicao recursiva de criaArvore
    //assim:
    a->esq->esq = criaArvore('x',
                              criaArvore('y',criaArvVazia(),criaArvVazia()),
                              criaArvore('z',criaArvVazia(),criaArvVazia())
                            );
    exibicoesArvores(a);
    pula(1);
    printf("Pressione Enter para liberar itens!");
    getchar();
    //pode-se liberar usando:
    a->dir->esq = liberaArvore(a->dir->esq); pula(2);
    exibicoesArvores(a);

    char elemento; int opcao;
    printf("Qual elemento vc deseja buscar? "); scanf(" %c", &elemento);
    printf("O elemento = %c", elemento);
    if(!buscaArvore(a,elemento)){
        printf("\n\nElemento nao existe na arvore!\n\n");
    }else{
        printf("\n\nO elemento %c esta presente na arvore!\n\n", elemento);
    }
    pula(1);
    system("pause");
    system("cls");
    printf("\nOrdens de percurso em arvores!\n");
    system("pause");
    exibicoesArvores(a);
    //pre-ordem
    printf("\nPercorrendo em pre-ordem!\n(raiz esq dir):\t");
    imprimeArv(a); pula(2);

    //em ordem
    printf("Percorrendo em ordem!\n(esq raiz dir):\t");
    imprimeArvEmOrdem(a); pula(2);

    //pos-ordem
    printf("Percorrendo em pos-ordem:!\n(esq dir raiz)\t");
    imprimeArvPosOrdem(a); pula(2);
    system("pause");

    
    printf("Pronto!\nAcabou a brincadeira!!\n");
    getchar();


}

int arvoreVazia(Arv* a){
    return a==NULL;
}

void imprimeArv(Arv* a){        //Obs.: imprime em pré-ordem, como a definicao de arvore:
    if(!arvoreVazia(a)){        //      primeiro: raiz, depois esqueda em seguida direita.
        printf("%c ",a->info);  //raiz
        imprimeArv(a->esq);     //subárvore esquerda
        imprimeArv(a->dir);     //subarvore direita
    }
}
void imprimeArvNotacao(Arv* a){     //também imprime em pré-ordem.
    printf("<");
    if(!arvoreVazia(a)){
        printf("%c",a->info);           //raiz
        imprimeArvNotacao(a->esq);     //subárvore esquerda
        imprimeArvNotacao(a->dir);     //subarvore direita
    }
    printf(">");
}

Arv* liberaArvore(Arv* a){
    if(!arvoreVazia(a)){
        liberaArvore(a->esq);        //subárvore esquerda
        liberaArvore(a->dir);        //subarvore direita
        free(a);
    }
    return NULL;
    //observação ---> Usa pós-ordem! Primeiro subArvore esq, depois SubArvore direita,
    //                em seguida, a raiz.
}
int buscaArvore(Arv* a, char c){
    if(arvoreVazia(a))
        return 0;   //arvore vazia - nao encontrou
    else
        return a->info==c ||
                buscaArvore(a->esq,c) ||
                buscaArvore(a->dir,c);
    /* comentario sobre a funcao busca: ela interrompe a busca tão logo o elemento
    seja encontrado. Se a primeira expressão for verdadeira as duas outras não chegam
    a ser avaliadas.
    */
}

void imprimeArvEmOrdem(Arv* a){        //Obs.: imprime em ordem:
    if(!arvoreVazia(a)){        //      primeiro: subArv Esq, depois raiz em seguida SubArvDireita.
        imprimeArv(a->esq);     //subárvore esquerda
        printf("%c ",a->info);   //raiz
        imprimeArv(a->dir);     //subarvore direita
    }
}
void imprimeArvPosOrdem(Arv* a){        //Obs.: imprime em pos-ordem:
    if(!arvoreVazia(a)){        //      primeiro: subArv Esq, depois SubArvDireita em seguida raiz.
        imprimeArv(a->esq);     //subárvore esquerda
        imprimeArv(a->dir);     //subarvore direita
        printf("%c ",a->info);  //raiz
    }
}
int maiorDois (int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int alturaArvore(Arv* a){
    if(arvoreVazia(a))
        return -1;
    else
        return 1+maiorDois(alturaArvore(a->esq),alturaArvore(a->dir));
}

// A função mostraArvore faz um desenho esquerda-direita-raiz
// da árvore x. O desenho terá uma margem esquerda de
// 3b espaços.
void mostraArvore(Arv* a, int b) {
    if (a == NULL) {
        imprimeNo('*', b);
        return;
    }
    mostraArvore(a->dir, b+1);
    imprimeNo(a->info, b);
    mostraArvore(a->esq, b+1);
}

// A função auxiliar imprimeNo imprime o caracter
// c precedido de 3b espaços e seguido de uma mudança
// de linha.
void imprimeNo(char c, int b) {
    int i;
    for (i = 0; i < b; i++) printf("   ");
    printf("%c\n", c);
}

void mostraArvoreDiferente(Arv* a, int b) {
    if (a == NULL) {
        imprimeNo('*', b);
        return;
    }
    mostraArvoreDiferente(a->dir, b+1);
    imprimeNoDiferente(a->info, b);
    mostraArvoreDiferente(a->esq, b+1);
}
void imprimeNoDiferente(char c, int b) {
    int i;
    for (i = 0; i < b; i++) printf("\n\t");
    printf("|%c|\n", c);
}


//pula n linhas
void pula(int n){
    int i;
    for (i=0;i<n;i++)
        printf("\n");
}

void exibicoesArvores(Arv* a){
    printf("\nArvore como na memoria:\n");
    imprimeArv(a);
    printf("\n\nArvore usando a notacao de <raiz subArvEsq subArvDir>\n");
    printf("Nesta notacao, se o noh estiver vazio, ele eh representado por <>\n");
    printf("Fica assim:\n");
    imprimeArvNotacao(a); pula(1);
    printf("\nExibicao de Arvore - Livro do Sedgewick p.237\nVire a cabeca para a esquerda!!\t:)\n");
    pula(1);
    mostraArvore(a,2); 
//    mostraArvoreDiferente(a,2); 
    printf("\nA altura desta arvore = %d", alturaArvore(a)); pula(1);
    printf("Pressione Enter!");
    getchar();
}
