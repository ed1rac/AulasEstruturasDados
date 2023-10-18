package generics;

public class PrintGenerico {

    static <T> void printGenerico(T element)
    {
        System.out.println(element.getClass().getName() + " = " + element);
    }

    // Driver method
    public static void main(String[] args)
    {

        printGenerico(11);
        printGenerico("Estruturas de Dados");
        printGenerico(1.0);
    }
}