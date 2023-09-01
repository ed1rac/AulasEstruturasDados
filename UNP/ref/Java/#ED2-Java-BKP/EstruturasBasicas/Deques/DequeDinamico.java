package EstruturasBasicas.Deques;

public class DequeDinamico {
  //deque dinamico usando a classe Celula
  private Celula inicio;
  private Celula fim;

  public DequeDinamico() {
    this.inicio = null;
    this.fim = null;
  }

  public boolean estaVazio() {
    return this.inicio == null;
  }

  public void insereInicio(Object elemento) {
    Celula nova = new Celula(elemento);
    if (this.estaVazio()) {
      this.inicio = nova;
      this.fim = nova;
    } else {
      nova.setProximo(this.inicio);
      this.inicio = nova;
    }
  }

  public void insereFim(Object elemento) {
    Celula nova = new Celula(elemento);
    if (this.estaVazio()) {
      this.inicio = nova;
      this.fim = nova;
    } else {
      this.fim.setProximo(nova);
      this.fim = nova;
    }
  }

  public Object removeInicio() throws Exception {
    if (this.estaVazio()) {
      throw new Exception("O deque está vazio");
    }
    Object elemento = this.inicio.getElemento();
    this.inicio = this.inicio.getProximo();
    if (this.inicio == null) {
      this.fim = null;
    }
    return elemento;
  }

  public Object removeFim() throws Exception {
    if (this.estaVazio()) {
      throw new Exception("O deque está vazio");
    }
    Object elemento = this.fim.getElemento();
    Celula aux = this.inicio;
    while (aux.getProximo() != this.fim) {
      aux = aux.getProximo();
    }
    this.fim = aux;
    this.fim.setProximo(null);
    return elemento;
  }

  public Object inicio() {
    if (this.estaVazio()) {
      return null;
    }
    return this.inicio.getElemento();
  }

  public Object fim() {
    if (this.estaVazio()) {
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
    if (this.estaVazio()) {
      System.out.println("Deque vazio");
    } else {
      Celula aux = this.inicio;
      while (aux != null) {
        System.out.println(aux.getElemento());
        aux = aux.getProximo();
      }
    }
  }

  public static void main(String[] args) throws Exception {
    DequeDinamico deque = new DequeDinamico();
    deque.insereInicio("Edkallenn");
    deque.insereInicio(4);
    deque.insereFim("Maria");
    deque.insereFim(5);
    System.out.println("Imprimindo o deque");
    deque.imprime();
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("");
    System.out.println("Imprimindo o deque");
    deque.imprime();
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("");
    System.out.println("Imprimindo o deque");
    deque.imprime();
  }
}
