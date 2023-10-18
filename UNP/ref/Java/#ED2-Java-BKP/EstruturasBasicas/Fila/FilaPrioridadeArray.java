package EstruturasBasicas.Fila;

public class FilaPrioridadeArray {
  //fila de prioridades usando array e usando a classe ElementoFilaPrioridade
  private Object[] fila;
  private int inicio;
  private int fim;

  public FilaPrioridadeArray(int maximo) {
    this.fila = new ElementoFilaPrioridade[maximo];
    this.inicio = 0;
    this.fim = -1;
  }

  public boolean estaVazia() {
    return this.inicio == this.fim + 1;
  }

  public boolean estaCheia() {
    return this.fim == this.fila.length - 1;
  }

  public void enfileira(Object elemento, int prioridade) throws Exception {
    if (this.estaCheia()) {
      throw new Exception("A fila está cheia");
    }
    ElementoFilaPrioridade novo = new ElementoFilaPrioridade(
      elemento,
      prioridade
    );
    int i;
    for (i = fim; i >= inicio; i--) {
      if (
        novo.getPrioridade() >
        ((ElementoFilaPrioridade) this.fila[i]).getPrioridade()
      ) {
        this.fila[i + 1] = this.fila[i];
      } else {
        break;
      }
    }
    this.fila[i + 1] = novo;
    fim++;
  }

  public Object desenfileira() throws Exception {
    if (this.estaVazia()) {
      throw new Exception("A fila está vazia");
    }
    return this.fila[inicio++];
  }

  //desenfileira por prioridade
  public Object desenfileiraPorPrioridade() throws Exception {
    //desenfileira o elemento com menor prioridade
    if (this.estaVazia()) {
      throw new Exception("A fila está vazia");
    }
    //descobre a menor prioridade
    int menorPrioridade =
      ((ElementoFilaPrioridade) this.fila[inicio]).getPrioridade();
    int posicaoMenorPrioridade = inicio;
    for (int i = inicio + 1; i <= fim; i++) {
      if (
        menorPrioridade >
        ((ElementoFilaPrioridade) this.fila[i]).getPrioridade()
      ) {
        menorPrioridade =
          ((ElementoFilaPrioridade) this.fila[i]).getPrioridade();
        posicaoMenorPrioridade = i;
      }
    }
    Object elemento = this.fila[posicaoMenorPrioridade];
    //desenfileira o elemento com menor prioridade usando o método desenfileira(Object elemento)
    this.desenfileira(elemento);
    return elemento;
  }

  private void desenfileira(Object elemento) {
    if (this.estaVazia()) {
      System.out.println("Fila vazia");
    } else {
      for (int i = inicio; i <= fim; i++) {
        if (this.fila[i] == elemento) {
          System.out.println("Desenfileirando: " + this.fila[i]);
          for (int j = i; j < fim; j++) {
            this.fila[j] = this.fila[j + 1];
          }
          fim--;
        }
      }
    }
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

  public static void pulaLinha(int x) {
    for (int i = 0; i < x; i++) {
      System.out.println();
    }
  }

  public static void main(String[] args) throws Exception {
    FilaPrioridadeArray fila = new FilaPrioridadeArray(10);
    fila.enfileira("Edkallenn", 1);
    fila.enfileira(4, 2);
    fila.enfileira("Paulo", 3);
    fila.enfileira("Camila", 2);
    fila.enfileira("Rafael", 1);
    fila.imprime();
    pulaLinha(1);
    System.out.println("Desenfileirando: ");
    fila.desenfileiraPorPrioridade();
    pulaLinha(1);
    fila.imprime();
    pulaLinha(1);
    System.out.println("Desenfileirando: ");
    fila.desenfileiraPorPrioridade();
    pulaLinha(1);
    fila.imprime();
    pulaLinha(1);
    System.out.println("Desenfileirando: ");
    fila.desenfileiraPorPrioridade();
    pulaLinha(1);
    fila.imprime();
    pulaLinha(1);
    System.out.println("Desenfileirando: ");
    fila.desenfileiraPorPrioridade();
    pulaLinha(1);
    fila.imprime();
    pulaLinha(1);
    System.out.println("Desenfileirando: ");
    fila.desenfileiraPorPrioridade();
    pulaLinha(1);
    fila.imprime();
    pulaLinha(1);


  }
}
