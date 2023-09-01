package recursividade;

public class InverteString {
    public static void main(String[] args) {
        String s = "Estruturas de Dados";
        System.out.println(inverte(s));
    }

    public static String inverte(String s) {
        if (s.length() <= 1) {
            return s;
        }
        return inverte(s.substring(1)) + s.charAt(0);
    }
}
