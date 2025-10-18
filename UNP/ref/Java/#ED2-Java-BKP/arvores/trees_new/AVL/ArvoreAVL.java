package arvores.AVL;

import arvores.ArvoreBinaria;

public class ArvoreAVL {
    private No raiz;

    public void inserir(int chave) {
        raiz = inserirNo(raiz, chave);
    }

    private No inserirNo(No no, int chave) {
        if (no == null) {
            return new No(chave);
        }

        if (chave < no.chave) {
            no.filhoEsquerda = inserirNo(no.filhoEsquerda, chave);
        } else if (chave > no.chave) {
            no.filhoDireita = inserirNo(no.filhoDireita, chave);
        } else {
            // Duplicatas n�o s�o permitidas (voc� pode personalizar isso conforme
            // necess�rio)
            return no;
        }

        atualizarAltura(no);
        int fatorBalanceamento = calcularFatorBalanceamento(no);

        if (fatorBalanceamento > 1) {
            if (chave < no.filhoEsquerda.chave) {
                return rotacaoDireita(no);
            }

            if (chave > no.filhoEsquerda.chave) {
                no.filhoEsquerda = rotacaoEsquerda(no.filhoEsquerda);
                return rotacaoDireita(no);
            }
        }

        if (fatorBalanceamento < -1) {
            if (chave > no.filhoDireita.chave) {
                return rotacaoEsquerda(no);
            }

            if (chave < no.filhoDireita.chave) {
                no.filhoDireita = rotacaoDireita(no.filhoDireita);
                return rotacaoEsquerda(no);
            }
        }

        return no;
    }

    // Funções de rotação aqui
    private int altura(No no) {
        if (no != null) {
            return no.altura;
        } else {
            return 0;
        }
    }

    private int calcularFatorBalanceamento(No no) {
        if (no != null) {
            return altura(no.filhoEsquerda) - altura(no.filhoDireita);
        } else {
            return 0;
        }
    }

    private void atualizarAltura(No no) {
        if (no != null) {
            no.altura = 1 + Math.max(altura(no.filhoEsquerda), altura(no.filhoDireita));
        }
    }

    private No rotacaoEsquerda(No pai) {
        No filho = pai.filhoDireita;
        No T2 = filho.filhoEsquerda;

        filho.filhoEsquerda = pai;
        pai.filhoDireita = T2;

        atualizarAltura(pai);
        atualizarAltura(filho);

        return filho;
    }

    private No rotacaoDireita(No pai) {
        No filho = pai.filhoEsquerda;
        No T2 = filho.filhoDireita;

        filho.filhoDireita = pai;
        pai.filhoEsquerda = T2;

        atualizarAltura(pai);
        atualizarAltura(filho);

        return filho;
    }

    private No rotacaoEsquerdaDireita(No z) {
        z.filhoEsquerda = rotacaoEsquerda(z.filhoEsquerda);
        return rotacaoDireita(z);
    }

    private No rotacaoDireitaEsquerda(No z) {
        z.filhoDireita = rotacaoDireita(z.filhoDireita);
        return rotacaoEsquerda(z);
    }

    public void printArvoreAVL() {
        printArvoreAVL(raiz, 0);
    }

    private void printArvoreAVL(No no, int level) {
        if (no == null) {
            return;
        }

        printArvoreAVL(no.filhoDireita, level + 1);

        for (int i = 0; i < level; i++) {
            System.out.print("      ");
        }

        System.out.println(no.chave);

        printArvoreAVL(no.filhoEsquerda, level + 1);
    }

    public static void main(String[] args) {
        ArvoreAVL arvore = new ArvoreAVL();
        ArvoreBinaria binaria = new ArvoreBinaria();
        /*
         * arvore.inserir(5);
         * arvore.inserir(4);
         * arvore.inserir(3);
         */
        System.out.println("Binária: ");
        binaria.inserir(10);
        binaria.inserir(5);
        binaria.inserir(15);
        binaria.inserir(3);
        binaria.inserir(8);
        binaria.inserir(12);
        binaria.inserir(18);
        binaria.imprimeArvore();

        System.out.println();
        System.out.println("AVL");
        /*
         * arvore.inserir(1);
         * arvore.inserir(2);
         */
        arvore.inserir(10);
        arvore.inserir(5);
        arvore.inserir(15);
        arvore.inserir(3);
        arvore.inserir(8);
        arvore.inserir(12);
        arvore.inserir(18);
        arvore.printArvoreAVL();
    }
}
