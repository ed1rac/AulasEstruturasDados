package arvores;

public class TreeExibeTexto {

  public static void printTree(Node raiz, int level) {
    if (raiz == null) {
      return;
    }
    printTree(raiz.direita, level + 1);

    for (int i = 0; i < level; i++) {
      System.out.print("    ");
    }

    System.out.println(raiz.data);

    printTree(raiz.esquerda, level + 1);
  }

  public static void main(String[] args) {
    Node raiz = new Node('A');
    raiz.esquerda = new Node('B');
    raiz.direita = new Node('C');
    raiz.esquerda.esquerda = new Node('D');
    raiz.esquerda.direita = new Node('E');
    raiz.direita.direita = new Node('F');
    raiz.esquerda.esquerda.esquerda = new Node('G');

    printTree(raiz, 0);
  }
}
