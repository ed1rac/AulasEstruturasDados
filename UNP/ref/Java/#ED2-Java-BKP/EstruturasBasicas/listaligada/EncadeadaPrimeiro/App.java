package EstruturasBasicas.listaligada.EncadeadaPrimeiro;

import EstruturasBasicas.EncadeadaPrimeiro.Lista;

public class App {

  public static void main(String[] args) {
    Lista lista = new Lista();

    // Adicionando elementos
    lista.adicionar("Elemento 1");
    lista.adicionar("Elemento 2");
    lista.adicionar("Elemento 3");
    //lista.adicionar(2);

    // Imprimindo a lista
    lista.imprimir();
  }
}
