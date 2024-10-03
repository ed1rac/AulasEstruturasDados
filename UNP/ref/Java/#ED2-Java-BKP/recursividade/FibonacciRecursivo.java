package recursividade;

public class FibonacciRecursivo {
    public static void main(String[] args) {
        for (int i = 0; i < 52; i++) {
            System.out.println("fib(" + i + ") = " + fib(i));
        }
    }
    public static double fibonacci(int n){
        if ((n == 0) || (n==1)) return 1;
        return fibonacci(n-1)+ fib(n-2);
    }

    public static double fib(int n){
        long[] array = new long[100];
        if ((n == 0) || (n==1)) return 1;
        array[0] = 1;
        array[1] = 1;
        for (int i = 2; i <= n; i++) {
            array[i] = array[i-1] + array[i-2];
        }
        return array[n];
    }
}
