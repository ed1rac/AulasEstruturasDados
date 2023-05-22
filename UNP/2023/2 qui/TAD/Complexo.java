public class Complexo {
    float a;
    float b;

    public Complexo(float n1, float n2) {
        a = n1;
        b = n2;
    }

    public void exibeComplexo(Complexo n1) {
        System.out.println("(" + a + " + " + b + " i)");
    }

}