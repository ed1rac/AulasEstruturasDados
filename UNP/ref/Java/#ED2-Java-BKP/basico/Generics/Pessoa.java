package ref.Java.Basico.Generics;

public class Pessoa implements Comparable<Pessoa> {
  private String nome;
  private int idade;

  public Pessoa(String nome, int idade) {
    this.nome = nome;
    this.idade = idade;
  }

  public String getNome() {
    return this.nome;
  }

  public int getIdade() {
    return this.idade;
  }

  @Override
  public String toString() {
    return "Nome: " + this.nome + " - Idade: " + this.idade;
  }

  //comparador
  @Override
  public int compareTo(Pessoa outraPessoa) {
    return this.nome.compareTo(outraPessoa.getNome());
  }
}
