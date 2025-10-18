package ED2.arvores;

import java.util.Objects;

public class Node<T extends Comparable<T>> {
    T data;
    Node<T> esquerda;
    Node<T> direita;

    public Node(T data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return String.valueOf(data);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Node<?> outro)) return false;
        return Objects.equals(this.data, outro.data);
    }
}
