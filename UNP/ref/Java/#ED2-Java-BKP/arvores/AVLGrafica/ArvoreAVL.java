package arvores.AVLGrafica;

class No {
    int chave, altura;
    No filhoEsquerda, filhoDireita;

    public No(int chave) {
        this.chave = chave;
        this.altura = 1;
    }
}

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
            return no;
        }

        atualizarAltura(no);
        int fatorBalanceamento = calcularFatorBalanceamento(no);

        if (fatorBalanceamento > 1) {
            if (chave < no.filhoEsquerda.chave) {
                return rotacaoDireita(no);
            } else {
                no.filhoEsquerda = rotacaoEsquerda(no.filhoEsquerda);
                return rotacaoDireita(no);
            }
        }

        if (fatorBalanceamento < -1) {
            if (chave > no.filhoDireita.chave) {
                return rotacaoEsquerda(no);
            } else {
                no.filhoDireita = rotacaoDireita(no.filhoDireita);
                return rotacaoEsquerda(no);
            }
        }

        return no;
    }

    private void atualizarAltura(No no) {
        if (no != null) {
            no.altura = 1 + Math.max(altura(no.filhoEsquerda), altura(no.filhoDireita));
        }
    }

    private int altura(No no) {
        return no == null ? 0 : no.altura;
    }

    private int calcularFatorBalanceamento(No no) {
        return no == null ? 0 : altura(no.filhoEsquerda) - altura(no.filhoDireita);
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

    public No getRaiz() {
        return raiz;
    }
}
