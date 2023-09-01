package recursividade;

public class PotenciaRecursiva {

    public static void main(String[] args) {
        for (int i = 0; i <= 20; i++) {
            System.out.println("2 ^ " + i + " = " + pot(2,i));
        }
    }

    public static long pot(int base, int expoente){
        if(expoente==0)
            return 1;
        else
            return base * pot(base, expoente-1);
    }
}
