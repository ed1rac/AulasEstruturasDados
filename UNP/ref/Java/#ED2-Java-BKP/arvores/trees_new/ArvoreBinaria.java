package arvores;

import java.util.LinkedList;
import java.util.Queue;

public class ArvoreBinaria {
    // Arvore Bin�ria usando a classe Node como base
    Node raiz;

    public ArvoreBinaria() {
        raiz = null;
    }

    public void inserir(Object data) {

        raiz = inserir(raiz, data);
    }

    private <T extends Comparable<T>> Node inserir(Node raiz, Object data) {
        // if (raiz == null) {
        if (arvoreVazia(raiz)) {
            raiz = new Node(data);
            // } else if ((Integer)data < (Integer)raiz.data) {
        } else if (raiz.data.toString().compareTo(data.toString()) > 0) {
            raiz.esquerda = inserir(raiz.esquerda, data);
        } else {
            raiz.direita = inserir(raiz.direita, data);
        }
        return raiz;
    }

    boolean arvoreVazia(Node t) {
        return t == null;
    }

    public void remover(Object data) {
        raiz = remover(raiz, data);
    }

    private <T extends Comparable<T>> Node remover(Node raiz, Object data) {
        if (arvoreVazia(raiz)) {
            return null; // n�o tem filhos
        } else if (raiz.data.toString().compareTo(data.toString()) > 0) {
            raiz.esquerda = remover(raiz.esquerda, data); // n�o tem filhos a esquerda
        } else if (raiz.data.toString().compareTo(data.toString()) < 0) {
            raiz.direita = remover(raiz.direita, data); // n�o tem filhos a direita
        } else {
            if (raiz.esquerda == null) {
                return raiz.direita;
            } else if (raiz.direita == null) {
                return raiz.esquerda;
            }
            raiz.data = menor(raiz.direita);
            raiz.direita = remover(raiz.direita, raiz.data);
        }
        return raiz;
    }

    private <T extends Comparable<T>> Object menor(Node raiz) {
        if (raiz.esquerda == null) {
            return raiz.data;
        }
        return menor(raiz.esquerda);
    }

    public void exibirEmOrdem() {
        exibirEmOrdem(raiz);
    }

    private void exibirEmOrdem(Node raiz) {
        if (raiz != null) {
            exibirEmOrdem(raiz.esquerda);
            System.out.println(raiz.data);
            exibirEmOrdem(raiz.direita);
        }
    }

    public void exibirPreOrdem() {
        exibirPreOrdem(raiz);
    }

    private void exibirPreOrdem(Node raiz) {
        if (raiz != null) {
            System.out.println(raiz.data);
            exibirPreOrdem(raiz.esquerda);
            exibirPreOrdem(raiz.direita);
        }
    }

    // exibe em p�s ordem

    public void exibirPosOrdem() {
        exibirPosOrdem(raiz);
    }

    private void exibirPosOrdem(Node raiz) {
        if (raiz != null) {
            exibirPosOrdem(raiz.esquerda);
            exibirPosOrdem(raiz.direita);
            System.out.println(raiz.data);
        }
    }

    public void exibirEmNivel() {
        Node tree = raiz;
        if (tree == null) {
            return;
        }
        Queue<Node> fila = new LinkedList<>();
        fila.add(tree);
        while (!fila.isEmpty()) {
            Node no = fila.poll();
            System.out.print(no.data + " ");
            if (no.esquerda != null) {
                fila.add(no.esquerda);
            }
            if (no.direita != null) {
                fila.add(no.direita);
            }
        }
    }

    public void exibirTexto() {
        exibirTexto(raiz);
    }

    private void exibirTexto(Node raiz) {
        if (raiz != null) {
            exibirTexto(raiz.esquerda);
            System.out.print(raiz.data + " ");
            exibirTexto(raiz.direita);
        }
    }

    public void exibirTextoInvertido() {
        exibirTextoInvertido(raiz);
    }

    private void exibirTextoInvertido(Node raiz) {
        if (raiz != null) {
            exibirTextoInvertido(raiz.direita);
            System.out.print(raiz.data + " ");
            exibirTextoInvertido(raiz.esquerda);
        }
    }

    public void imprimeArvore() {
        imprimeArvore(this.raiz, 0);
    }

    public static void imprimeArvore(Node raiz, int level) {
        if (raiz == null) {
            return;
        }
        imprimeArvore(raiz.direita, level + 1);

        for (int i = 0; i < level; i++) {
            // System.out.print(" ");
            System.out.print("      ");
        }

        System.out.println(raiz.data);

        imprimeArvore(raiz.esquerda, level + 1);
    }

    public Node buscar(Object dado) {

        return buscar(raiz, dado);
    }

    private Node buscar(Node raiz, Object dado) {
        if (raiz == null) {
            return null;
        }

        int comparacao = raiz.data.toString().compareTo(dado.toString());

        if (comparacao == 0) {
            return raiz; // encontrou
        } else if (comparacao > 0) {
            return buscar(raiz.esquerda, dado); // vai à esquerda
        } else {
            return buscar(raiz.direita, dado); // vai à direita
        }
    }

    public Node buscarElemento(Object elemento) {
        Node encontrado = buscar(elemento);
        if (encontrado != null) {
            System.out.println("Elemento encontrado: " + encontrado.data);
        } else {
            System.out.println("Elemento n�o encontrado!");
        }
        return encontrado;
    }

    /*
     * 
     * A utiliza��o de dois m�todos sobrecarregados chamados "buscar" serve para
     * ocultar a complexidade da busca recursiva e permitir que o usu�rio da classe
     * "ArvoreBinaria" fa�a chamadas mais simples ao m�todo p�blico.
     * 
     * O m�todo p�blico buscar(Object data) � a interface externa que os usu�rios da
     * classe ir�o chamar. Ele permite que voc� inicie a busca a partir da raiz da
     * �rvore sem expor os detalhes da implementa��o. Este m�todo � uma esp�cie de
     * ponto de entrada para a busca na �rvore bin�ria.
     * 
     * O m�todo privado buscar(Node raiz, Object data) � o m�todo de busca real que
     * realiza a pesquisa recursiva na �rvore. Ele � chamado a partir do m�todo
     * p�blico e � respons�vel por navegar pela �rvore, comparar valores e decidir
     * se deve continuar a busca na sub�rvore esquerda ou direita. Este m�todo �
     * usado para manter o estado interno da recurs�o e � uma parte essencial da
     * implementa��o da busca na �rvore bin�ria.
     * 
     * Usando essa abordagem, voc� pode ocultar os detalhes da recurs�o e tornar a
     * interface p�blica mais simples para os usu�rios da classe, que s� precisam
     * passar o elemento que desejam buscar. O m�todo p�blico inicia a busca a
     * partir da raiz, enquanto o m�todo privado realiza a busca recursiva em cada
     * n� da �rvore.
     * 
     * Isso torna o c�digo mais organizado e encapsulado, seguindo o princ�pio da
     * oculta��o de informa��es (encapsulamento) e tornando a implementa��o mais
     * f�cil de entender e manter.
     * 
     */

    // classe para testar a classe ArvoreBinaria

    public static void main(String[] args) {

        ArvoreBinaria arvore = new ArvoreBinaria();
        arvore.inserir(5);
        arvore.inserir(3);
        arvore.inserir(7);
        arvore.inserir(1);
        arvore.inserir(4);
        arvore.inserir(6);
        arvore.inserir(8);
        System.out.println("M�todo exibir EM ORDEM <E - R - D>: ");
        arvore.exibirEmOrdem();
        System.out.println("M�todo exibeArvore: ");
        imprimeArvore(arvore.raiz, 0);
        System.out.println();
        System.out.println();
        /*
         * System.out.println("M�todo exibirTexto EM ORDEM <E - R - D>: : ");
         * arvore.exibirTexto();
         * System.out.println();
         */
        System.out.println("M�todo exibirTexto EM N�VEL: : ");
        arvore.exibirEmNivel();
        System.out.println();
        System.out.println();

        /*
         * System.out.println("M�todo exibirTextoInvertido: ");
         * arvore.exibirTextoInvertido();
         * System.out.println();
         * System.out.println();
         */
        System.out.println("M�todo exibir em PR�-ORDEM <R - E - D>: ");
        arvore.exibirPreOrdem();
        System.out.println();

        System.out.println("M�todo exibir em P�S-ORDEM <E - D - R>: ");
        arvore.exibirPosOrdem();
        System.out.println();

        Node encontrado = arvore.buscarElemento(5);
        Node encontrado1 = arvore.buscarElemento(10);
        arvore.remover(7);
        imprimeArvore(arvore.raiz, 0);

        // ArvoreBinaria arvore2 = new ArvoreBinaria();
        // arvore2.inserir(0);
        /*
         * arvore2.inserir(4);
         * arvore2.inserir(3);
         * arvore2.inserir(5);
         * arvore2.inserir(6);
         * arvore2.inserir(1);
         * arvore2.inserir(2);
         */
        /*
         * arvore2.inserir(200);
         * arvore2.inserir(150);
         * arvore2.inserir(100);
         * arvore2.inserir(170);
         * arvore2.inserir(350);
         * arvore2.inserir(250);
         * arvore2.inserir(500);
         * arvore2.inserir(400);
         * arvore2.inserir(600);
         * System.out.println();
         * System.out.println("M�todo exibir EM ORDEM <E - R - D>: : ");
         * arvore2.exibirEmOrdem();
         * System.out.println();
         * System.out.println("M�todo printTree: ");
         * imprimeArvore(arvore2.raiz, 0);
         * System.out.println();
         * System.out.println("M�todo exibirTexto EM ORDEM <E - R - D>: : ");
         * arvore2.exibirTexto();
         * System.out.println();
         * System.out.println("M�todo exibirTextoInvertido: ");
         * arvore2.exibirTextoInvertido();
         * System.out.println();
         */

        ArvoreBinaria arvore2 = new ArvoreBinaria();
        arvore2.inserir("Jo�o");
        arvore2.inserir("Bianca");
        arvore2.inserir("Danilo");
        arvore2.inserir("Marcelo");
        arvore2.inserir("Carlos");
        arvore2.inserir("Ana");
        arvore2.inserir("Pedro");
        // arvore2.exibirTexto();
        imprimeArvore(arvore2.raiz, 0);
        arvore2.exibirEmOrdem();

    }
}
