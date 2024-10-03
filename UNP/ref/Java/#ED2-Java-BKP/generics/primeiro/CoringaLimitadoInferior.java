package generics.primeiro;

import java.util.List;
import java.util.ArrayList;

/**
 * O coringa limitado inferior (<? super T>) especifica que o tipo pode ser T ou qualquer superclasse de T.
 * Ele é usado principalmente em cenários de inserção (write operations).
 *
 * `<? super Integer>` significa que a lista pode ser de `Integer` ou de qualquer superclasse de `Integer` (como `Number` ou `Object`).
 * Este coringa é útil quando você precisa adicionar elementos a uma coleção,
 * garantindo que todos os elementos sejam do tipo `T` ou seus subtipos.
 */

public class CoringaLimitadoInferior {

    public static void adicionarNumero(List<? super Integer> lista) { // Aceita uma lista de Integer ou de qualquer superclasse de Integer (como Number)
        lista.add(42);
    }

    public static void main(String[] args) {
        List<Number> listaDeNumeros = new ArrayList<>(); // List<Number> pode receber Integers
        adicionarNumero(listaDeNumeros);
        System.out.println(listaDeNumeros);
    }
}
