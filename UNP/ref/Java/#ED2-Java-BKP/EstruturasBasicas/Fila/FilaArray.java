package EstruturasBasicas.Fila;

public class FilaArray {
  //fila em array
  private Object[] fila;
  private int inicio;
  private int fim;

  public FilaArray(int maximo) {
    this.fila = new Object[maximo];
    this.inicio = 0;
    this.fim = -1;
  }

  public boolean estaVazia() {
    return this.inicio == this.fim + 1;
  }

  public boolean estaCheia() {
    return this.fim == this.fila.length - 1;
  }

  public void enfileira(Object elemento) throws Exception {
    if (this.estaCheia()) {
      throw new Exception("A fila está cheia");
    }
    this.fila[++fim] = elemento;
  }

  public Object desenfileira() throws Exception {
    if (this.estaVazia()) {
      throw new Exception("A fila está vazia");
    }
    return this.fila[inicio++];
  }

  public Object inicio() {
    if (this.estaVazia()) {
      return null;
    }
    return this.fila[inicio];
  }

  public int tamanho() {
    return this.fim - this.inicio + 1;
  }

  public void imprime() {
    if (this.estaVazia()) {
      System.out.println("Fila vazia");
    } else {
      for (int i = inicio; i <= fim; i++) {
        System.out.println(this.fila[i]);
      }
    }
  }

  public static void main(String[] args) throws Exception {
    FilaArray fila = new FilaArray(10);
    fila.enfileira("Edkallenn");
    fila.enfileira(4);
    fila.enfileira("Camila");
    fila.enfileira("Paulo");
    fila.enfileira("Rafael");
    fila.imprime();
    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Desenfileirando: " + fila.desenfileira());
    fila.imprime();
  }
}
