package generics.primeiro;

import java.util.Objects;

public class Pessoa {
    String nome;
    int idade;

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    Pessoa() {

    }
    Pessoa(String n, int i) {
        this.nome = n;
        this.idade = i;
    }
    public String exibePessoa() {
        return "Nome: " + this.nome + " - " + " Idade: " + this.idade;
    }
    @Override
    public String toString(){
        return this.exibePessoa();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pessoa pessoa = (Pessoa) o;
        return idade == pessoa.idade && Objects.equals(nome, pessoa.nome);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, idade);
    }
}
