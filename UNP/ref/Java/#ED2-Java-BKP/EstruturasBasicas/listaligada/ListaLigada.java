package EstruturasBasicas.listaligada;

public class ListaLigada {
  private Celula primeira = null;
  private Celula ultima = null;
  private int tamanho = 0;

  public void adicionaNoComeco(Object elemento) {
    //adiciona no começo da lista
    Celula nova;
    nova = new Celula(elemento, primeira);
    this.primeira = nova;
    if (tamanho == 0) {
      this.ultima = this.primeira;
    }
    tamanho++;
  }

  //adiciona no final da lista
  public void adiciona(Object elemento) {
    if (tamanho == 0) {
      adicionaNoComeco(elemento);
    } else {
      Celula nova = new Celula(elemento);
      this.ultima.setProximo(nova);
      this.ultima = nova;
      tamanho++;
    }
  }

  //exibe os elementos da lista
  @Override
  public String toString() {
    if (tamanho == 0) {
      return "[]";
    }
    Celula atual = primeira;
    String result = "[" + atual.getElemento();

    for (int i = 0; i < tamanho - 1; i++) {
      atual = atual.getProximo();
      result += ", " + atual.getElemento();
    }

    result += "]";
    return result;
  }


  /*
  public String toString() {
    if (tamanho == 0) {
      return "[]";
    }
    Celula atual = primeira;
    StringBuilder builder = new StringBuilder("[");
    for (int i = 0; i < tamanho - 1; i++) {
      builder.append(atual.getElemento());
      builder.append(", ");
      atual = atual.getProximo();
    }
    builder.append(atual.getElemento());
    builder.append("]");
    return builder.toString();
  }

*/

  public void exibeRecursivo(ListaLigada lista) {
      exibeCelula(lista.primeira);
  }

  public void exibeCelula(Celula lista){
    if (lista != null) {
      System.out.println(lista.getElemento());
      exibeCelula(lista.getProximo());
    }
  }

  public static void main(String[] args) {
    //testa os métodos
    ListaLigada lista = new ListaLigada();
    lista.adicionaNoComeco("Rafael");
    lista.adicionaNoComeco("Paulo");
    lista.adicionaNoComeco("Camila");
    System.out.println("Exibindo Lista:");
    System.out.println(lista);
    System.out.println("Adicionando `Edkallenn` e 4 no final");
    lista.adiciona("Edkallenn");
    lista.adiciona(4);
    System.out.println(lista);
    System.out.println("Exibindo Lista Recursivamente:");
    lista.exibeRecursivo(lista);
  }
}
