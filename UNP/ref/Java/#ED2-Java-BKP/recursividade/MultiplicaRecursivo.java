package recursividade;
public class MultiplicaRecursivo {

    public static void main(String[] args) {
        for (int i = 2; i <= 12; i++) {
            System.out.printf("Tabuada de %d\n===============\n", i);
            for (int j = 1; j <= 10; j++) {
                System.out.printf("%-2d x %-2d = %-3d\n", i, j, multiplicaRecursivo(i,j));
            }
            System.out.println("=======================");
        }
    }
    public static int multiplicaRecursivo(int a, int b){
        if (a==0||b==0) return 0;
        else if (b==1) {
            return a;
        }
        else{
            return (a + multiplicaRecursivo(a, b-1));
        }
    }

}
