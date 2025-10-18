package ED2.arvores;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ArvoreBinaria<T extends Comparable<T>> {
    Node<T> raiz;

    public ArvoreBinaria() {
        this.raiz = null;
    }

    private int comparar(T a, T b) {
        return a.compareTo(b);
    }

    public void inserir(T data) { raiz = inserir(raiz, data); }

    private Node<T> inserir(Node<T> raiz, T data) {
        if (raiz == null) return new Node<>(data);
        int compara = comparar(data, raiz.data);
        if (compara < 0) raiz.esquerda = inserir(raiz.esquerda, data);
        else             raiz.direita  = inserir(raiz.direita, data);
        return raiz;
    }

    public void remover(T data) { raiz = remover(raiz, data); }

    private Node<T> remover(Node<T> raiz, T data) {
        if (raiz == null) return null;

        int compara = comparar(data, raiz.data);
        if (compara < 0) {
            raiz.esquerda = remover(raiz.esquerda, data);
        } else if (compara > 0) {
            raiz.direita  = remover(raiz.direita, data);
        } else {
            if (raiz.esquerda == null) return raiz.direita;
            if (raiz.direita  == null) return raiz.esquerda;
            // dois filhos: substitui pelo menor da direita
            raiz.data = menor(raiz.direita);
            raiz.direita = remover(raiz.direita, raiz.data);
        }
        return raiz;
    }

    private T menor(Node<T> raiz) {
        return (raiz.esquerda == null) ? raiz.data : menor(raiz.esquerda);
    }

    private T maior(Node<T> raiz) {
        return (raiz.direita == null) ? raiz.data : maior(raiz.direita);
    }

    public void exibirEmOrdem() { exibirEmOrdem(raiz); }
    private void exibirEmOrdem(Node<T> r) {
        if (r != null) {
            exibirEmOrdem(r.esquerda);
            System.out.println(r.data);
            exibirEmOrdem(r.direita);
        }
    }

    public void exibirPreOrdem() { exibirPreOrdem(raiz); }
    private void exibirPreOrdem(Node<T> r) {
        if (r != null) {
            System.out.println(r.data);
            exibirPreOrdem(r.esquerda);
            exibirPreOrdem(r.direita);
        }
    }

    public void exibirPosOrdem() { exibirPosOrdem(raiz); }
    private void exibirPosOrdem(Node<T> r) {
        if (r != null) {
            exibirPosOrdem(r.esquerda);
            exibirPosOrdem(r.direita);
            System.out.println(r.data);
        }
    }

    public void exibirEmNivel() {
        if (raiz == null) return;
        Queue<Node<T>> fila = new LinkedList<>();
        fila.add(raiz);
        while (!fila.isEmpty()) {
            Node<T> no = fila.poll();
            System.out.print(no.data + " ");
            if (no.esquerda != null) fila.add(no.esquerda);
            if (no.direita  != null) fila.add(no.direita);
        }
        System.out.println();
    }

    public void imprimeArvore() { imprimeArvore(this.raiz, 0); }
    public static <E extends Comparable<E>> void imprimeArvore(Node<E> raiz, int level) {
        if (raiz == null) return;
        imprimeArvore(raiz.direita, level + 1);
        for (int i = 0; i < level; i++) System.out.print("      ");
        System.out.println(raiz.data);
        imprimeArvore(raiz.esquerda, level + 1);
    }

    public Node<T> buscar(T dado) { return buscar(raiz, dado); }
    private Node<T> buscar(Node<T> r, T dado) {
        if (r == null) return null;
        int compara = comparar(dado, r.data);
        if (compara == 0) return r;
        return (compara < 0) ? buscar(r.esquerda, dado) : buscar(r.direita, dado);
    }

    public Node<T> buscarElemento(T elemento) {
        Node<T> encontrado = buscar(elemento);
        if (encontrado != null) System.out.println("Elemento encontrado: " + encontrado.data);
        else                    System.out.println("Elemento não encontrado!");
        return encontrado;
    }

    

    private static String TipoArvore(Scanner sc) {
        System.out.println("Escolha o tipo da árvore:");
        System.out.println("1 - Integer");
        System.out.println("2 - String");
        int escolhaTipo = sc.nextInt();
        sc.nextLine(); // Limpa buffer
        return switch (escolhaTipo) {
            case 1 -> "Integer";
            case 2 -> "String";
            default -> "erro";
        };
    }

    private static <T extends Comparable<T>> void mostrarCaminhoBusca(ArvoreBinaria<T> arvore, T dado) {
        Node<T> r = arvore.raiz;
        System.out.print("Caminho: ");
        while (r != null) {
            System.out.print(r.data + " ");
            int compara = dado.compareTo(r.data);
            if (compara == 0) {
                System.out.println("\nElemento encontrado!");
                return;
            }
            r = (compara < 0) ? r.esquerda : r.direita;
        }
        System.out.println("\nElemento não encontrado!");
    }

    public static void menu() {
        Scanner sc = new Scanner(System.in);

        String tipo = null; // "Integer" ou "String"
        ArvoreBinaria<Integer> arvInt = null;
        ArvoreBinaria<String>  arvStr = null;

        while (true) {
            System.out.println("\n--- MENU ---");
            System.out.println("1 - Criar árvore vazia");
            System.out.println("2 - Exibir a árvore");
            System.out.println("3 - Inserir elemento");
            System.out.println("4 - Consultar elemento (mostrar caminho)");
            System.out.println("5 - Exibir menor e maior valor");
            System.out.println("6 - Sair");
            System.out.print("Escolha uma opção: ");
            int op = sc.nextInt();
            sc.nextLine(); // Limpa buffer

            switch (op) {
                case 1 -> {
                    String t = TipoArvore(sc);
                    if ("erro".equals(t)) {
                        System.out.println("Tipo inválido!");
                        break;
                    }
                    tipo = t;
                    if ("Integer".equals(tipo)) {
                        arvInt = new ArvoreBinaria<>();
                        arvStr = null;
                    } else {
                        arvStr = new ArvoreBinaria<>();
                        arvInt = null;
                    }
                    System.out.println("Árvore criada!");
                }

                case 2 -> {
                    if (tipo == null) { System.out.println("Crie a árvore primeiro!"); break; }
                    System.out.println("Escolha a forma de exibição:");
                    System.out.println("1 - Em ordem");
                    System.out.println("2 - Pré-ordem");
                    System.out.println("3 - Pós-ordem");
                    System.out.println("4 - Em nível");
                    System.out.println("5 - Estrutura visual");
                    int tipoExib = sc.nextInt(); sc.nextLine();

                    if ("Integer".equals(tipo)) {
                        if (arvInt == null || arvInt.raiz == null) { System.out.println("Árvore vazia!"); break; }
                        switch (tipoExib) {
                            case 1 -> arvInt.exibirEmOrdem();
                            case 2 -> arvInt.exibirPreOrdem();
                            case 3 -> arvInt.exibirPosOrdem();
                            case 4 -> arvInt.exibirEmNivel();
                            case 5 -> arvInt.imprimeArvore();
                            default -> System.out.println("Opção inválida!");
                        }
                    } else {
                        if (arvStr == null || arvStr.raiz == null) { System.out.println("Árvore vazia!"); break; }
                        switch (tipoExib) {
                            case 1 -> arvStr.exibirEmOrdem();
                            case 2 -> arvStr.exibirPreOrdem();
                            case 3 -> arvStr.exibirPosOrdem();
                            case 4 -> arvStr.exibirEmNivel();
                            case 5 -> arvStr.imprimeArvore();
                            default -> System.out.println("Opção inválida!");
                        }
                    }
                }

                case 3 -> {
                    if (tipo == null) { System.out.println("Crie a árvore primeiro!"); break; }
                    System.out.print("Digite o elemento a inserir: ");
                    if ("Integer".equals(tipo)) {
                        int elem = sc.nextInt(); sc.nextLine();
                        arvInt.inserir(elem);
                    } else {
                        String elem = sc.nextLine();
                        arvStr.inserir(elem);
                    }
                    System.out.println("Elemento inserido!");
                }

                case 4 -> {
                    if (tipo == null) { System.out.println("Crie a árvore primeiro!"); break; }
                    System.out.print("Digite o elemento a consultar: ");
                    if ("Integer".equals(tipo)) {
                        int busca = sc.nextInt(); sc.nextLine();
                        mostrarCaminhoBusca(arvInt, busca);
                    } else {
                        String busca = sc.nextLine();
                        mostrarCaminhoBusca(arvStr, busca);
                    }
                }

                case 5 -> {
                    if (tipo == null) { System.out.println("Crie a árvore primeiro!"); break; }
                    if ("Integer".equals(tipo)) {
                        if (arvInt == null || arvInt.raiz == null) { System.out.println("Árvore vazia!"); break; }
                        System.out.println("Menor valor: " + arvInt.menor(arvInt.raiz));
                        System.out.println("Maior valor: " + arvInt.maior(arvInt.raiz));
                    } else {
                        if (arvStr == null || arvStr.raiz == null) { System.out.println("Árvore vazia!"); break; }
                        System.out.println("Menor valor: " + arvStr.menor(arvStr.raiz));
                        System.out.println("Maior valor: " + arvStr.maior(arvStr.raiz));
                    }
                }

                case 6 -> {
                    System.out.println("Saindo...");
                    sc.close();
                    return;
                }

                default -> System.out.println("Opção inválida!");
            }
        }
    }

    public static void main(String[] args) {
        menu();
    }
}
