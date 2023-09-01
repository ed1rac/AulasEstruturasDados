package recursividade;

public class FatorialRecursivo {
    public static void main(String[] args) {
        for (int i = 0; i <=20 ; i++) {
            System.out.println(i + "! = " + fatorial(i));
        }
    }
    public static long fatorial(int n){
        if (n==0) return 1;
        return n * fatorial(n-1);
    }
}
