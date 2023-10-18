package generics;

// Programa Java para mostrar vários
// tipos de parâmetros com Java Generics
class Multiplos<T, U>    // usamos < > para especificar o tipo de parâmetro
{
    T obj1; // Um objeto do tipo T
    U obj2; // Um objeto do tipo U

    // constructor
    Multiplos(T obj1, U obj2) {
        this.obj1 = obj1;
        this.obj2 = obj2;
    }


    public void print() {
        System.out.println(obj1);
        System.out.println(obj2);
    }

    public static void main(String[] args) {
        Multiplos<String, Integer> objeto = new Multiplos<String, Integer>("Uma String", 15);

        objeto.print();
    }


}