package paradigmas.complexidade;

import java.util.Scanner;

public class ContandoInstrucoes2 {
    public static void main(String[] args) {
        // exemplo 2 - sele��o e compara��o
        Scanner sc = new Scanner(System.in);
        int numero = sc.nextInt();    // 1

        if (numero % 2 == 0) {        // if n�o conta. Compara��o sim, = 1
            numero = numero + 1;      // ou essa linha ou a outra, = 1
        } else {
            numero = numero - 1;
        }

        System.out.println(numero);   // 1
        // 4 instru��es no total
    }
}
