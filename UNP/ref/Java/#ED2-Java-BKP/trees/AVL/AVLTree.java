
public class AVLTree<T extends Comparable<T>> {

    Node<T> raiz;

    /* ===================== Helpers de altura & FB ===================== */

    private int altura(Node<T> n) {
        return (n == null) ? 0 : n.altura;
    } // Opção A
      // // Opção B (se NÃO adicionar 'altura' no Node):
      // private int altura(Node<T> n) {
      // if (n == null) return 0;
      // return 1 + Math.max(altura(n.esquerda), altura(n.direita));
      // }

    private void atualizarAltura(Node<T> n) {
        if (n != null) {
            n.altura = 1 + Math.max(altura(n.esquerda), altura(n.direita));
        }
    }

    /** FB = altura(dir) - altura(esq) => AVL válida se em {-1,0,1} */
    private int fatorBalanceamento(Node<T> n) {
        return (n == null) ? 0 : altura(n.direita) - altura(n.esquerda);
    }

    /* ===================== Rotações ===================== */

    /** Rotação simples à esquerda (caso RR) */
    private Node<T> rotacaoEsquerda(Node<T> y) {
        Node<T> x = y.direita;
        Node<T> T2 = x.esquerda;

        // Rotaciona
        x.esquerda = y;
        y.direita = T2;

        // Atualiza alturas
        atualizarAltura(y);
        atualizarAltura(x);

        return x; // nova raiz da subárvore
    }

    /** Rotação simples à direita (caso LL) */
    private Node<T> rotacaoDireita(Node<T> y) {
        Node<T> x = y.esquerda;
        Node<T> T2 = x.direita;

        // Rotaciona
        x.direita = y;
        y.esquerda = T2;

        // Atualiza alturas
        atualizarAltura(y);
        atualizarAltura(x);

        return x; // nova raiz da subárvore
    }

    /** Rotação dupla: esquerda-direita (caso LR) */
    private Node<T> rotacaoEsquerdaDireita(Node<T> n) {
        n.esquerda = rotacaoEsquerda(n.esquerda);
        return rotacaoDireita(n);
    }

    /** Rotação dupla: direita-esquerda (caso RL) */
    private Node<T> rotacaoDireitaEsquerda(Node<T> n) {
        n.direita = rotacaoDireita(n.direita);
        return rotacaoEsquerda(n);
    }

    /* ===================== Inserção (com rebalanceamento) ===================== */

    public void inserir(T valor) {
        raiz = inserir(raiz, valor);
    }

    private Node<T> inserir(Node<T> n, T valor) {
        if (n == null)
            return new Node<>(valor);

        int cmp = valor.compareTo(n.data);
        if (cmp < 0)
            n.esquerda = inserir(n.esquerda, valor);
        else if (cmp > 0)
            n.direita = inserir(n.direita, valor);
        else
            return n; // ignora duplicatas (ou trate conforme sua política)

        // Atualiza altura e calcula FB
        atualizarAltura(n);
        int fb = fatorBalanceamento(n);

        // Casos de rotação
        // 1) LL (pesado à esquerda e inserção foi na esquerda da esquerda)
        if (fb < -1 && valor.compareTo(n.esquerda.data) < 0) {
            return rotacaoDireita(n);
        }
        // 2) RR (pesado à direita e inserção foi na direita da direita)
        if (fb > 1 && valor.compareTo(n.direita.data) > 0) {
            return rotacaoEsquerda(n);
        }
        // 3) LR (pesado à esquerda e inserção foi na direita da esquerda)
        if (fb < -1 && valor.compareTo(n.esquerda.data) > 0) {
            return rotacaoEsquerdaDireita(n);
        }
        // 4) RL (pesado à direita e inserção foi na esquerda da direita)
        if (fb > 1 && valor.compareTo(n.direita.data) < 0) {
            return rotacaoDireitaEsquerda(n);
        }

        return n; // já balanceado
    }

    /* ===================== Remoção (com rebalanceamento) ===================== */

    public void remover(T valor) {
        raiz = remover(raiz, valor);
    }

    private Node<T> remover(Node<T> n, T valor) {
        if (n == null)
            return null;

        int cmp = valor.compareTo(n.data);
        if (cmp < 0) {
            n.esquerda = remover(n.esquerda, valor);
        } else if (cmp > 0) {
            n.direita = remover(n.direita, valor);
        } else {
            // Nó encontrado: 0, 1 ou 2 filhos
            if (n.esquerda == null || n.direita == null) {
                n = (n.esquerda != null) ? n.esquerda : n.direita;
            } else {
                // dois filhos: substitui pelo sucessor (mínimo na direita)
                Node<T> s = minimo(n.direita);
                n.data = s.data;
                n.direita = remover(n.direita, s.data);
            }
        }

        if (n == null)
            return null;

        // Atualiza altura e rebalanceia
        atualizarAltura(n);
        int fb = fatorBalanceamento(n);

        // Casos de rotação após remoção (note que agora comparamos FB dos filhos)
        // 1) LL
        if (fb < -1 && fatorBalanceamento(n.esquerda) <= 0) {
            return rotacaoDireita(n);
        }
        // 2) LR
        if (fb < -1 && fatorBalanceamento(n.esquerda) > 0) {
            return rotacaoEsquerdaDireita(n);
        }
        // 3) RR
        if (fb > 1 && fatorBalanceamento(n.direita) >= 0) {
            return rotacaoEsquerda(n);
        }
        // 4) RL
        if (fb > 1 && fatorBalanceamento(n.direita) < 0) {
            return rotacaoDireitaEsquerda(n);
        }

        return n;
    }

    private Node<T> minimo(Node<T> n) {
        while (n.esquerda != null)
            n = n.esquerda;
        return n;
    }

    /* ===================== Exibições (texto simples) ===================== */

    public void exibirEmOrdem() {
        emOrdem(raiz);
        System.out.println();
    }

    public void exibirPreOrdem() {
        preOrdem(raiz);
        System.out.println();
    }

    public void exibirPosOrdem() {
        posOrdem(raiz);
        System.out.println();
    }

    public void exibirArvore() {
        exibirArvore(raiz, 0);
    } // sideways

    private void emOrdem(Node<T> n) {
        if (n == null)
            return;
        emOrdem(n.esquerda);
        System.out.print(n.data + " ");
        emOrdem(n.direita);
    }

    private void preOrdem(Node<T> n) {
        if (n == null)
            return;
        System.out.print(n.data + " ");
        preOrdem(n.esquerda);
        preOrdem(n.direita);
    }

    private void posOrdem(Node<T> n) {
        if (n == null)
            return;
        posOrdem(n.esquerda);
        posOrdem(n.direita);
        System.out.print(n.data + " ");
    }

    // Impressão lateral: direita no topo
    private void exibirArvore(Node<T> n, int nivel) {
        if (n == null)
            return;
        exibirArvore(n.direita, nivel + 1);
        System.out.println("  ".repeat(nivel) + n.data + " (h=" + altura(n) + ", fb=" + fatorBalanceamento(n) + ")");
        exibirArvore(n.esquerda, nivel + 1);
    }

    public static void main(String[] args) {
        AVLTree<Integer> avl = new AVLTree<>();

        // Caso LL (rot. direita): insira 30, 20, 10
        avl.inserir(30);
        avl.inserir(20);
        avl.inserir(10);
        System.out.println("Após LL:");
        avl.exibirArvore();

        // Caso RR (rot. esquerda): insira 40, 50
        avl.inserir(40);
        avl.inserir(50);
        System.out.println("\nApós RR:");
        avl.exibirArvore();

        // Caso LR (rot. dupla esquerda-direita): forçar inserindo 25
        avl.inserir(25);
        System.out.println("\nApós LR:");
        avl.exibirArvore();

        // Caso RL (rot. dupla direita-esquerda): novo cenário
        AVLTree<Integer> avl2 = new AVLTree<>();
        for (int v : new int[] { 10, 30, 20 })
            avl2.inserir(v); // 10,30,20 => RL
        System.out.println("\nApós RL (nova árvore):");
        avl2.exibirArvore();

        // Percursos
        System.out.print("\nEm-ordem: ");
        avl.exibirEmOrdem();
        System.out.print("Pré-ordem: ");
        avl.exibirPreOrdem();
        System.out.print("Pós-ordem: ");
        avl.exibirPosOrdem();
    }
}
