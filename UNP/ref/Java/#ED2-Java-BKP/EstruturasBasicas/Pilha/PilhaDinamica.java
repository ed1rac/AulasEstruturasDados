package EstruturasBasicas.Pilha;

public class PilhaDinamica {
  //pilha dinamica usando a claasse Celula
  private Celula topo;

  public PilhaDinamica() {
    this.topo = null;
  }

  public boolean estaVazia() {
    return this.topo == null;
  }

  public void empilha(Object elemento) {
    Celula nova = new Celula(elemento, topo);
    this.topo = nova;
  }

  public Object desempilha() {
    if (this.estaVazia()) {
      return null;
    }
    Object elemento = this.topo.getElemento();
    this.topo = this.topo.getProximo();
    return elemento;
  }

  public Object topo() {
    if (this.estaVazia()) {
      return null;
    }
    return this.topo.getElemento();
  }

  public int tamanho() {
    int tamanho = 0;
    Celula atual = topo;
    while (atual != null) {
      atual = atual.getProximo();
      tamanho++;
    }
    return tamanho;
  }

  public void imprime() {
    if (this.estaVazia()) {
      System.out.println("Pilha vazia");
    } else {
      Celula atual = topo;
      while (atual != null) {
        System.out.println(atual.getElemento());
        atual = atual.getProximo();
      }
    }
  }

  public static void main(String[] args) {
    //testa os métodos
    PilhaDinamica pilha = new PilhaDinamica();
    pilha.empilha("Rafael");
    pilha.empilha("Paulo");
    pilha.empilha("Camila");
    System.out.println("Exibindo Pilha:");
    pilha.imprime();
    System.out.println("Desempilhando elemento " + pilha.desempilha());
    System.out.println("Desempilhando elemento " + pilha.desempilha());
    System.out.println("Exibindo Pilha:");
    pilha.imprime();
    System.out.println("Empilhando elemento `Edkallenn`");
    pilha.empilha("Edkallenn");
    System.out.println("Exibindo Pilha:");
    pilha.imprime();
  }
}
