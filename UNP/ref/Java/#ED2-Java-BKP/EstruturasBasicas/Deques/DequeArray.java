package EstruturasBasicas.Deques;

public class DequeArray {
  //implementando deque usando array
  private int inicio;
  private int fim;
  private int tamanho;
  private Object[] deque;

  public DequeArray(int tamanho) {
    this.inicio = 0;
    this.fim = 0;
    this.tamanho = 0;
    this.deque = new Object[tamanho];
  }

  public boolean estaVazio() {
    return this.tamanho == 0;
  }

  public boolean estaCheio() {
    return this.tamanho == this.deque.length;
  }

  public void insereInicio(Object elemento) throws Exception {
    if (this.estaCheio()) {
      throw new Exception("O deque está cheio");
    }
    if (this.inicio == 0) {
      this.inicio = this.deque.length - 1;
    } else {
      this.inicio--;
    }
    this.deque[this.inicio] = elemento;
    this.tamanho++;
  }

  public void insereFim(Object elemento) throws Exception {
    if (this.estaCheio()) {
      throw new Exception("O deque está cheio");
    }
    this.deque[this.fim] = elemento;
    if (this.fim == this.deque.length - 1) {
      this.fim = 0;
    } else {
      this.fim++;
    }
    this.tamanho++;
  }

  public Object removeInicio() throws Exception {
    if (this.estaVazio()) {
      throw new Exception("O deque está vazio");
    }
    Object elemento = this.deque[this.inicio];
    if (this.inicio == this.deque.length - 1) {
      this.inicio = 0;
    } else {
      this.inicio++;
    }
    this.tamanho--;
    return elemento;
  }

  public Object removeFim() throws Exception {
    if (this.estaVazio()) {
      throw new Exception("O deque está vazio");
    }
    if (this.fim == 0) {
      this.fim = this.deque.length - 1;
    } else {
      this.fim--;
    }
    Object elemento = this.deque[this.fim];
    this.tamanho--;
    return elemento;
  }

  public Object inicio() {
    if (this.estaVazio()) {
      return null;
    }
    return this.deque[this.inicio];
  }

  public Object fim() {
    if (this.estaVazio()) {
      return null;
    }
    if (this.fim == 0) {
      return this.deque[this.deque.length - 1];
    }
    return this.deque[this.fim - 1];
  }

  public int tamanho() {
    return this.tamanho;
  }

  public void imprime() {
    if (this.estaVazio()) {
      System.out.println("Deque vazio");
    } else {
      for (int i = this.inicio; i != this.fim; i++) {
        if (i == this.deque.length) {
          i = 0;
        }
        System.out.println(this.deque[i]);
      }
    }
  }

  public static void main(String[] args) throws Exception {
    DequeArray deque = new DequeArray(20);
    deque.insereInicio("Edkallenn");
    deque.insereInicio(4);
    deque.insereFim("Paulo");
    deque.insereFim(5);
    deque.insereInicio("Maria");
    deque.insereFim("João");
    deque.insereInicio("José");
    deque.insereFim("Pedro");
    deque.insereInicio("Carlos");
    deque.insereFim("Ana");
    deque.insereInicio("Marta");
    deque.insereFim("Mariana");
    deque.imprime();
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
    System.out.println("Removendo do início: " + deque.removeInicio());
    System.out.println("Removendo do fim: " + deque.removeFim());
  }
}
