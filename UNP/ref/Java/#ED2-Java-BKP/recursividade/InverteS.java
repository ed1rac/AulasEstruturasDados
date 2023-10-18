package recursividade;

public class InverteS {


    public static void main(String[] args) {

        String original = "Estruturas de Dados";
        String invertida = inverterString(original);
        System.out.println("String original: " + original);
        System.out.println("String invertida: " + invertida);

    }

    public static String inverterString(String str) {

        if (str.isEmpty()
        ) {
            return str;
        } else {

            char primeiroChar = str.charAt(0);
            String restoDaString = str.substring(1);
            String inversoDoResto = inverterString(restoDaString);
            return inversoDoResto + primeiroChar;

        }

    }

}
