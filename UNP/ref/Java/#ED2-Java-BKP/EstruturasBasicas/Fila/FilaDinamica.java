package EstruturasBasicas.Fila;

public class FilaDinamica {
  //fila dinamica usando a classe Celula
  private Celula inicio;
  private Celula fim;

  public FilaDinamica() {
    this.inicio = null;
    this.fim = null;
  }

  public boolean estaVazia() {
    return this.inicio == null;
  }

  public void enfileira(Object elemento) {
    Celula nova = new Celula(elemento);
    if (this.estaVazia()) {
      this.inicio = nova;
      this.fim = nova;
    } else {
      this.fim.setProximo(nova);
      this.fim = nova;
    }
  }

  public Object desenfileira() throws Exception {
    if (this.estaVazia()) {
      throw new Exception("A fila está vazia");
    }
    Object elemento = this.inicio.getElemento();
    this.inicio = this.inicio.getProximo();
    if (this.inicio == null) {
      this.fim = null;
    }
    return elemento;
  }

  public Object inicio() {
    if (this.estaVazia()) {
      return null;
    }
    return this.inicio.getElemento();
  }

  public Object ultimo() {
    if (this.estaVazia()) {
      return null;
    }
    return this.fim.getElemento();
  }

  public int tamanho() {
    int tamanho = 0;
    Celula aux = this.inicio;
    while (aux != null) {
      tamanho++;
      aux = aux.getProximo();
    }
    return tamanho;
  }

  public void imprime() {
    if (this.estaVazia()) {
      System.out.println("Fila vazia");
    } else {
      Celula aux = this.inicio;
      while (aux != null) {
        System.out.println(aux.getElemento());
        aux = aux.getProximo();
      }
    }
  }

  public static void main(String[] args) throws Exception {
    FilaDinamica fila = new FilaDinamica();
    fila.enfileira("Edkallenn");
    fila.enfileira(4);
    fila.enfileira("Paulo");
    fila.enfileira(3.141592);
    fila.enfileira("Ana Maria");
    System.out.println("Exibindo Fila:");
    fila.imprime();
    System.out.println("Tamanho da fila: " + fila.tamanho());
    System.out.println("Elemento do inicio: " + fila.inicio());
    System.out.println("Elemento do final: " + fila.ultimo());
    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Exibindo Fila:");
    fila.imprime();
    System.out.println("Tamanho da fila: " + fila.tamanho());
    System.out.println("Elemento do inicio: " + fila.inicio());
    System.out.println("Elemento do final: " + fila.ultimo());

    System.out.println("Desenfileirando: " + fila.desenfileira());
    System.out.println("Exibindo Fila:");
    fila.imprime();
  }
}
