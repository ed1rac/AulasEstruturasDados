package EstruturasBasicas.Fila;

public class ElementoFilaPrioridade {
  private Object objeto;
  public int prioridade;

  public Object getObjeto() {
    return objeto;
  }

  public void setObjeto(Object elemento) {
    this.objeto = elemento;
  }

  public int getPrioridade() {
    return prioridade;
  }

  public void setPrioridade(int prioridade) {
    this.prioridade = prioridade;
  }

  public ElementoFilaPrioridade(Object elemento, int prioridade) {
    this.objeto = elemento;
    this.prioridade = prioridade;
  }

  public ElementoFilaPrioridade(Object elemento) {
    this.objeto = elemento;
  }

  //tostring
  @Override
  public String toString() {
    return ("Objeto na fila: [" + objeto + ", prioridade=" + prioridade + ']');
  }
}
