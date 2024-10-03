package generics.primeiro;
import java.util.ArrayList;
import java.util.List;

public class SemGenerics {
    public static void main(String[] args) {
        List<Object> lista = new ArrayList<>(); // Note que não especificamos o tipo dos elementos
        lista.add("Texto");
        lista.add(123); // Adicionamos um Integer

        for (Object obj : lista) {
            // Precisamos fazer casting explícito
            String str = (String) obj;
            System.out.println(str);
        }
    }
}

