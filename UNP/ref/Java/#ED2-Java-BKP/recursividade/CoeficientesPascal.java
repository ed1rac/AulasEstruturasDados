package recursividade;

public class CoeficientesPascal {

    public static int coeficiente(int n, int p){
        if(p==0) return 1;
        if(n==p) return 1;
        return coeficiente(n-1, p-1) + coeficiente(n-1, p);
    }

    public static void main(String[] args) {
        int n = 10;
        //exibePolinomio(n);
        for (int i = 0; i < n; i++) {
            exibePolinomio(i);
            System.out.println();
        }
        exibePascal(n);
    }

    public static void exibePolinomio(int n){
        for (int i = n; i >= 0; i--) {
            System.out.print(coeficiente(n, i) + "x^" + i + " + ");
        }
    }

    public static void exibePascal(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(coeficiente(i, j) + "\t");
            }
            System.out.println();
        }
    }


}
