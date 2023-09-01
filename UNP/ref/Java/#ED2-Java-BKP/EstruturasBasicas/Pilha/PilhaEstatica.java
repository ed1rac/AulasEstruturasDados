package EstruturasBasicas.Pilha;

import javax.print.PrintException;

public class PilhaEstatica {
  private Object[] elementos;
  private int topo;

  public PilhaEstatica(int maximo) {
    this.elementos = new Object[maximo];
    this.topo = -1;
  }

  public boolean estaVazia() {
    return this.topo == -1;
  }

  public boolean estaCheia() {
    return this.topo == this.elementos.length - 1;
  }

  public void empilha(Object elemento) throws PrintException {
    if (this.estaCheia()) {
      throw new PrintException("A pilha está cheia");
    }
    this.elementos[++topo] = elemento;
  }

  public Object desempilha() throws PrintException {
    if (this.estaVazia()) {
      throw new PrintException("A pilha está vazia");
    }
    return this.elementos[topo--];
  }

  public Object topo() {
    if (this.estaVazia()) {
      return null;
    }
    return this.elementos[topo];
  }

  public int tamanho() {
    return this.topo + 1;
  }

  public void imprime() {
    if (this.estaVazia()) {
      System.out.println("Pilha vazia");
    } else {
      for (int i = 0; i <= this.topo; i++) {
        System.out.println(this.elementos[i]);
      }
    }
  }

  public static void main(String[] args) throws PrintException {
    PilhaEstatica pilha = new PilhaEstatica(10);
    pilha.empilha("Edkallenn");
    pilha.empilha(4);
    pilha.empilha("Paulo");
    pilha.empilha("Rafael");
    pilha.empilha("Ana");
    pilha.empilha("João");
    pilha.empilha("Maria");
    pilha.empilha("José");
    pilha.empilha("Carlos");
    pilha.empilha("Edson");
    pilha.imprime();
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    System.out.println("Desempilhando: " + pilha.desempilha());
    pilha.imprime();
  }
}
