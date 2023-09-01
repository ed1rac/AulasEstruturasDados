package ref.Java.Basico.Generics;

import java.util.ArrayList;
import java.util.List;

public class PrimeiroGenerics {

  public static void main(String[] args) {
    List<String> listaStrings = new ArrayList<String>();
    listaStrings.add("Elemento 1");
    listaStrings.add("Elemento 2");
    listaStrings.add("Elemento 3");
    System.out.println(listaStrings);
    System.out.println("Tamanho da Lista: " + listaStrings.size());
    //iterar na lista
    for (String elemento : listaStrings) {
      System.out.println(elemento);
    }
  }
}
