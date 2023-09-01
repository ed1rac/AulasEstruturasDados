package gerenciamento_memoria;

public class Pessoa {
    String nome;
    int idade;

    Pessoa() {

    }

    Pessoa(String n, int i) {
        this.nome = n;
        this.idade = i;
    }

    public String exibePessoa() {
        return "Nome: " + this.nome + " - " + " Idade: " + this.idade;
    }

}
