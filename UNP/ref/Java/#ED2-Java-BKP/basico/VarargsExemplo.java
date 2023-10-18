package basico;

public class VarargsExemplo {
    public static void main(String[] args) {
        System.out.println(soma(1,2));
        System.out.println(soma(1,2,3,4,5,6,7,8,9,10));
        System.out.println(soma(1.1,1.2,1.3,1.4));
    }

    private static int soma(int a, int b) {
        return a +b;
    }

    private static int soma(Integer... vetor) {
        int sum = 0;
        for (int i = 0; i < vetor.length; i++) {
            sum += vetor[i];
        }
        return sum;
    }

    private static double soma(Double... vetor) {
        double sum = 0.0;
        for (Double aDouble : vetor) {
            sum += aDouble;
        }
        return sum;
    }
}
