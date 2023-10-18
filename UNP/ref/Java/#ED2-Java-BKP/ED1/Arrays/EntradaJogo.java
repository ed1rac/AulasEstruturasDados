package ED1.Arrays;

public class EntradaJogo {
    protected String nome;
    protected int score;

    public EntradaJogo(String nome, int score) {
        this.nome = nome;
        this.score = score;
    }

    public String getNome() {
        return nome;
    }

    public int getScore() {
        return score;
    }

    public String toString(){
        return "[" + this.nome + " - " + this.score + "]";
    }

}
