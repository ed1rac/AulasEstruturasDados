package generics.primeiro;

import java.util.List;

/**
 * Um coringa não limitado (<?>) pode ser qualquer tipo. Ele é usado quando o tipo específico não é importante.
 * significa que você pode passar qualquer tipo de objeto para o método ou classe.
 * É como dizer: "Eu aceito qualquer tipo".
 */

public class Coringas {

    /*
         O método imprimirLista pode aceitar uma lista de qualquer tipo (List<?>).
         O tipo exato dos elementos na lista não importa, e eles serão tratados como Object dentro do método
     */

    public static void imprimirLista(List<?> lista) { // Aceita uma lista de qualquer t
        for (Object elem : lista) {
            System.out.println(elem);
        }
    }

    public static void main(String[] args) {
        List<String> listaDeStrings = List.of("A", "B", "C");
        List<Integer> listaDeIntegers = List.of(1, 2, 3);

        imprimirLista(listaDeStrings);
        imprimirLista(listaDeIntegers);
    }
}
