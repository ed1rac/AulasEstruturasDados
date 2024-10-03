package generics.primeiro;

/**
 * uma classe genérica Caixa que pode armazenar qualquer tipo de objeto
 * @param <T>
 */

public class Caixa<T> {
    private T item;

    public void adicionar(T item) {
        this.item = item;
    }

    public T retirar() {
        return item;
    }

    public static void main(String[] args) {
        Caixa<String> caixaDeTexto = new Caixa<>();
        caixaDeTexto.adicionar("Olá, Mundo!");
        System.out.println(caixaDeTexto.retirar());

        Caixa<Integer> caixaDeNumero = new Caixa<>();
        caixaDeNumero.adicionar(123);
        System.out.println(caixaDeNumero.retirar());

        Caixa<Pessoa> pessoaCaixa = new Caixa<>();
        pessoaCaixa.adicionar(new Pessoa("João das Neves", 38));
        System.out.println(pessoaCaixa.retirar().exibePessoa());

        Caixa<Object> caixaGenerica = new Caixa<>();
        caixaGenerica.adicionar(new Pessoa("Danny", 27));
        System.out.println(caixaGenerica.retirar());

    }
}
