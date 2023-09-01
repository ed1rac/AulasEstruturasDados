package EstruturasBasicas.listaligada;

public class Celula {
  private Object elemento;
  private Celula proximo;

  public Celula getProximo() {
    return proximo;
  }

  public void setProximo(Celula proximo) {
    this.proximo = proximo;
  }

  public Object getElemento() {
    return elemento;
  }

  public Celula(Object elemento, Celula proximo) {
    this.elemento = elemento;
    this.proximo = proximo;
  }

  public Celula(Object elemento) {
    this.elemento = elemento;
  }
}
