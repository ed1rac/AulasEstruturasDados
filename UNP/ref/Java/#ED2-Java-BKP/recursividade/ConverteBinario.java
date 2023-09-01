package recursividade;

public class ConverteBinario {
    public static void main(String[] args) {
        for (int i = 0; i < 50; i++) {
            System.out.printf("%d em binário = ", i);
            imprime_binario(i);
            System.out.println();
        }

    }
    public static void imprime_binario(int x) {
        if(x==0) {
            System.out.printf("0");
            return;
        }
        imprime_binario(x/2);
        System.out.printf("%d", x%2);
    }
}
