package paradigmas.complexidade;

import java.util.Scanner;

public class ContandoInstrucoes2 {
    public static void main(String[] args) {
        // exemplo 2 - seleção e comparação
        Scanner sc = new Scanner(System.in);
        int numero = sc.nextInt();    // 1

        if (numero % 2 == 0) {        // if não conta. Comparação sim, = 1
            numero = numero + 1;      // ou essa linha ou a outra, = 1
        } else {
            numero = numero - 1;
        }

        System.out.println(numero);   // 1
        // 4 instruções no total
    }
}
