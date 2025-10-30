package EstruturasBasicas.EncadeadaPrimeiro;

public class Lista {
  Nodo primeiro;
  Nodo ultimo;
  int tamanho;

  public Lista() {
    this.tamanho = 0;
  }

  // M�todo para adicionar um elemento na lista
  public void adicionar(String info) {
    Nodo novoNodo = new Nodo();
    novoNodo.info = info;
    novoNodo.proximo = null;

    if (primeiro == null) {
      primeiro = novoNodo;
      ultimo = novoNodo;
    } else {
      ultimo.proximo = novoNodo;
      ultimo = novoNodo;
    }

    tamanho++;
  }

  // M�todo para imprimir a lista
  public void imprimir() {
    Nodo atual = primeiro;

    while (atual != null) {
      System.out.println(atual.info);
      atual = atual.proximo;
    }
  }
}
