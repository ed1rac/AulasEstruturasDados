package TestaTrabalhos;

public class Testa {

    public static double calculateSum(int n) {

        if (n == 1) {
            return 1.0;
        } else {
            return calculateSum(n - 1) + 1.0 / n;
        }

    }

    public static void main(String[] args) {

        int n = 5; // Change this value to the desired number of terms
        double sum = calculateSum(n);
        System.out.println("Sum of the series: " + sum);
    }


}
