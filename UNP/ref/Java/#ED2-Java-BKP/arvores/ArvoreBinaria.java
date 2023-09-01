package arvores;

public class ArvoreBinaria {
    //Arvore Binária usando a classe Node como base
    Node raiz;

    public ArvoreBinaria() {
        raiz = null;
    }

    public void inserir(Object data) {
        raiz = inserir(raiz, data);
    }

    private Node inserir(Node raiz, Object data) {
        if (raiz == null) {
            raiz = new Node(data);
        } else if ((Integer)data < (Integer)raiz.data) {
            raiz.esquerda = inserir(raiz.esquerda, data);
        } else {
            raiz.direita = inserir(raiz.direita, data);
        }
        return raiz;
    }

    public void exibir() {
        exibir(raiz);
    }

    private void exibir(Node raiz) {
        if (raiz != null) {
            exibir(raiz.esquerda);
            System.out.println(raiz.data);
            exibir(raiz.direita);
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

    //classe para testar a classe ArvoreBinaria
    public static void main(String[] args) {

        ArvoreBinaria arvore = new ArvoreBinaria();
        arvore.inserir(5);
        arvore.inserir(3);
        arvore.inserir(7);
        arvore.inserir(1);
        arvore.inserir(4);
        arvore.inserir(6);
        arvore.inserir(8);
        System.out.println("Método exibir: ");
        arvore.exibir();
        System.out.println("Método printTree: ");
        TreeExibeTexto.printTree(arvore.raiz, 0);
        System.out.println();
        System.out.println();
        System.out.println("Método exibirTexto: ");
        arvore.exibirTexto();
        System.out.println();
        System.out.println("Método exibirTextoInvertido: ");
        arvore.exibirTextoInvertido();
        System.out.println();

        ArvoreBinaria arvore2 = new ArvoreBinaria();
        //arvore2.inserir(0);
        arvore2.inserir(4);
        arvore2.inserir(3);
        arvore2.inserir(5);
        arvore2.inserir(6);
        arvore2.inserir(1);
        arvore2.inserir(2);
        System.out.println("Método exibir: ");
        arvore2.exibir();
        System.out.println();
        System.out.println("Método printTree: ");
        TreeExibeTexto.printTree(arvore2.raiz, 0);
        System.out.println();
        System.out.println("Método exibirTexto: ");
        arvore2.exibirTexto();
        System.out.println();
        System.out.println("Método exibirTextoInvertido: ");
        arvore2.exibirTextoInvertido();
        System.out.println();

    }
}
