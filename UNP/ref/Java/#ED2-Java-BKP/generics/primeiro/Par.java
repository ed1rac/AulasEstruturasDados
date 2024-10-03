package generics.primeiro;

public class Par<T, U> {
    private T primeiro;
    private U segundo;

    public Par(T primeiro, U segundo) {
        this.primeiro = primeiro;
        this.segundo = segundo;
    }

    public T getPrimeiro() {
        return primeiro;
    }

    public U getSegundo() {
        return segundo;
    }

    public static void main(String[] args) {
        // Criando um objeto Par para armazenar um Integer e uma String
        Par<Integer, String> par1 = new Par<>(1, "Um");

        // Criando um objeto Par para armazenar uma String e um Double
        Par<String, Double> par2 = new Par<>("Dois", 2.0);

        // Criando um objeto Par para armazenar dois valores Double
        Par<Double, Double> par3 = new Par<>(3.14, 2.718);

        // Exibindo os valores armazenados em par1
        System.out.println("Par 1:");
        System.out.println("Primeiro: " + par1.getPrimeiro());
        System.out.println("Segundo: " + par1.getSegundo());

        // Exibindo os valores armazenados em par2
        System.out.println("\nPar 2:");
        System.out.println("Primeiro: " + par2.getPrimeiro());
        System.out.println("Segundo: " + par2.getSegundo());

        // Exibindo os valores armazenados em par3
        System.out.println("\nPar 3:");
        System.out.println("Primeiro: " + par3.getPrimeiro());
        System.out.println("Segundo: " + par3.getSegundo());
    }
}
