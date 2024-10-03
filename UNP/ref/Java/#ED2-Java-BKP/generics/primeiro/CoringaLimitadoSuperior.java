package generics.primeiro;

import java.util.List;

/**
 * O coringa limitado superior (<? extends T>) especifica que o tipo pode ser T ou qualquer subclasse de T.
 * Ele � geralmente usado em cen�rios de leitura (read operations).
 *
 * - `<? extends Number>` significa que a lista pode ser de `Number` ou de qualquer subclasse de `Number` (como `Integer`, `Double`, etc.).
 * - Este coringa � �til quando voc� precisa ler dados de uma cole��o gen�rica, mas n�o modificar seu conte�do.
 */

public class CoringaLimitadoSuperior {

    public static double somar(List<? extends Number> lista) { // Aceita uma lista de Number ou de suas subclasses
        double soma = 0;
        for (Number numero : lista) {
            soma += numero.doubleValue();
        }
        return soma;
    }

    public static void main(String[] args) {
        List<Integer> listaDeIntegers = List.of(1, 2, 3);
        List<Double> listaDeDoubles = List.of(1.5, 2.5, 3.5);

        System.out.println(somar(listaDeIntegers)); // Funciona com Integer
        System.out.println(somar(listaDeDoubles)); // Funciona com Double
    }
}
