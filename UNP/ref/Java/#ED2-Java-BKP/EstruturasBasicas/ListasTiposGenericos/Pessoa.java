package EstruturasBasicas.ListasTiposGenericos;

public class Pessoa {
    String nome;
    int idade;

    Pessoa(){}

    Pessoa(String s, int i){
        this.nome = s;
        this.idade = i;
    }

    @Override
    public String toString() {
        return "[" + this.nome + " - " + this.idade + "]";
    }
}
