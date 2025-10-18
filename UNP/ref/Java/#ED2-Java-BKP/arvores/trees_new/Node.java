package arvores;

import java.util.Objects;

public class Node {
  Object data;
  Node esquerda;
  Node direita;

  public Node(Object data) {
    this.data = data;
    this.esquerda = null;
    this.direita = null;
  }

  // comparador
  @Override
  public String toString() {
    return String.valueOf(data);
  }

  @Override
  public boolean equals(Object obj) {
    if (obj == null) {
      return false;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    final Node outro = (Node) obj;
    return Objects.equals(this.data, outro.data);
  }

}
