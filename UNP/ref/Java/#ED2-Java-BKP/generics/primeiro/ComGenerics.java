package generics.primeiro;

import java.util.ArrayList;
import java.util.List;

public class ComGenerics {
    public static void main(String[] args) {
        List<String> lista = new ArrayList<>(); // Agora definimos o tipo como String
        lista.add("Texto");
        // lista.add(123); // Este c�digo geraria um erro de compila��o

        for (String str : lista) {
            System.out.println(str);
        }
    }
}
