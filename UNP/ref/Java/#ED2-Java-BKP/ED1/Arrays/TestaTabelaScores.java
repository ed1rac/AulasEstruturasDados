package ED1.Arrays;

public class TestaTabelaScores {
    public static void main(String[] args) {
        TabelaScores tabela = new TabelaScores(10);
        tabela.add(new EntradaJogo("Joeliton", 100));
        tabela.add(new EntradaJogo("Mariana", 200));
        tabela.add(new EntradaJogo("Joseph", 300));
        tabela.add(new EntradaJogo("Pietro", 400));
        tabela.add(new EntradaJogo("Alice", 500));
        tabela.add(new EntradaJogo("João", 600));
        tabela.add(new EntradaJogo("Maria", 700));
        tabela.add(new EntradaJogo("Jose", 800));
        tabela.add(new EntradaJogo("Pedro", 900));
        tabela.add(new EntradaJogo("Ana", 1000));
        tabela.add(new EntradaJogo("Carlos", 1100));
        System.out.println("Placares do jogo\n============================");
        System.out.println(tabela);
        tabela.remove(7);
        System.out.println("Placares do jogo\n============================");
        System.out.println(tabela);


    }
}
