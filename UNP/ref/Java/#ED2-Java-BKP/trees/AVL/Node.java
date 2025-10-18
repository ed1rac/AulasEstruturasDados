// Node.java (adicione o campo altura)

import java.util.Objects;

public class Node<T extends Comparable<T>> {
    T data;
    Node<T> esquerda;
    Node<T> direita;
    int altura = 1; // NOVO: altura da subárvore com raiz neste nó

    public Node(T data) { this.data = data; }

    @Override
    public String toString() { return String.valueOf(data); }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Node<?>)) return false;
        Node<?> outro = (Node<?>) obj;
        return Objects.equals(this.data, outro.data);
    }
}
