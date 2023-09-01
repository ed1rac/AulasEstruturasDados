package ref.Java.Basico.Generics;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class SegundoGenerics {

  public static void main(String[] args) {
    ArrayList<Pessoa> listaPessoas = new ArrayList<Pessoa>();
    listaPessoas.add(new Pessoa("Maria", 20));
    listaPessoas.add(new Pessoa("João", 30));
    listaPessoas.add(new Pessoa("André", 28));
    listaPessoas.add(new Pessoa("José", 40));
    //imprime a lista
    System.out.println(listaPessoas);
    //tamanho da lista
    System.out.println("Tamanho da Lista: " + listaPessoas.size());
    //itera na lista
    for (Pessoa pessoa : listaPessoas) {
      System.out.println(pessoa);
    }
    System.out.println("\nOrdenando...");
    System.out.println("Exibindo depois de ordenar...");
    Collections.sort(listaPessoas);
    System.out.println("");
    listaPessoas.forEach(
      pessoa -> {
        System.out.println("-------------");
        System.out.println(pessoa);
      }
    );

    System.out.println("\n\nOrdenando pela idade...");
    Collections.sort(listaPessoas, Comparator.comparing(Pessoa::getIdade));
    //ou
    //listaPessoas.sort(Comparator.comparing(Pessoa::getIdade));
    listaPessoas.forEach(
      pessoa -> {
        System.out.println("-------------");
        System.out.println(pessoa);
      }
    );
  }
}
