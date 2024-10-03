package EstruturasBasicas.Fila;

public class FilaPrioridadeDinamica {
  //fila de prioridades usando a classe ElementoFilaPrioridade e a classe Celula
  private Celula inicio;
  private Celula fim;

  public FilaPrioridadeDinamica() {
    this.inicio = null;
    this.fim = null;
  }

  public boolean estaVazia() {
    return this.inicio == null;
  }

  public void enfileira(Object elemento, int prioridade) {
    ElementoFilaPrioridade novoElemento = new ElementoFilaPrioridade(
      elemento,
      prioridade
    );
    Celula nova = new Celula(novoElemento);
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

  public Object desenfileiraPorPrioridade() throws Exception {
    if (this.estaVazia()) {
      throw new Exception("A fila está vazia");
    }

    //descobre a menor prioridade
    int menorPrioridade =
            ((ElementoFilaPrioridade) this.inicio.getElemento()).getPrioridade();
    Celula aux = this.inicio;
    while (aux != null) {
      if (
              ((ElementoFilaPrioridade) aux.getElemento()).getPrioridade() <
                      menorPrioridade
      ) {
        menorPrioridade =
                ((ElementoFilaPrioridade) aux.getElemento()).getPrioridade();
      }
      aux = aux.getProximo();
    }

    //desenfileira o elemento com menor prioridade
    aux = this.inicio;
    Celula anterior = null;
    while (
      ((ElementoFilaPrioridade) aux.getElemento()).getPrioridade() !=
      menorPrioridade
    ) {
      anterior = aux;
      aux = aux.getProximo();
    }
    Object elemento = aux.getElemento();
    if (anterior == null) {
      this.inicio = this.inicio.getProximo();
    } else {
      anterior.setProximo(aux.getProximo());
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
    //testa os métodos
    FilaPrioridadeDinamica fila = new FilaPrioridadeDinamica();
    //enfileira vários elementos com diversas prioridades
    fila.enfileira("Rafael", 1);
    fila.enfileira("Camila", 3);
    fila.enfileira("Paulo", 2);
    fila.enfileira("Edkallenn", 1);
    fila.enfileira("Mariana", 4);
    fila.enfileira("Guilherme", 3);
    fila.enfileira("Ana", 2);
    fila.imprime();
    //desenfileira
    System.out.println("Desenfileirando: " + fila.desenfileiraPorPrioridade());
    System.out.println("");
    fila.imprime();

    System.out.println("Desenfileirando: " + fila.desenfileiraPorPrioridade());
    System.out.println("");
    fila.imprime();

    System.out.println("Desenfileirando: " + fila.desenfileiraPorPrioridade());
    System.out.println("");
    fila.imprime();

    System.out.println("Desenfileirando: " + fila.desenfileiraPorPrioridade());
    System.out.println("");
    fila.imprime();
  }
}
