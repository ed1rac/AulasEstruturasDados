package generics.primeiro;

import java.util.List;

/**
 * Um coringa n�o limitado (<?>) pode ser qualquer tipo. Ele � usado quando o tipo espec�fico n�o � importante.
 * significa que voc� pode passar qualquer tipo de objeto para o m�todo ou classe.
 * � como dizer: "Eu aceito qualquer tipo".
 */

public class Coringas {

    /*
         O m�todo imprimirLista pode aceitar uma lista de qualquer tipo (List<?>).
         O tipo exato dos elementos na lista n�o importa, e eles ser�o tratados como Object dentro do m�todo
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
