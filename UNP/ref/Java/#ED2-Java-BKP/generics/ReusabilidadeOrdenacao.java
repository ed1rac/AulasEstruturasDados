package generics;

public class ReusabilidadeOrdenacao {

    public static void main(String[] args)
    {

        Integer[] a = { 100, 22, 58, 41, 6, 50 };

        Character[] c = { 'v', 'g', 'a', 'c', 'x', 'd', 't' };

        String[] s = { "Estados Unidos", "Irã", "Brasil", "Austrália","França", "Itália", "China" };

        System.out.print("Array de Inteiros ordenado: :  ");
        ordena_generico(a);

        System.out.print("Array de Char ordenado :  ");
        ordena_generico(c);

        System.out.print("Array de Strings ordenado :  ");
        ordena_generico(s);

    }

    public static <T extends Comparable<T> > void ordena_generico(T[] array)
    {

        // Como estamos comparando os tipos de dados não primitivos
        // precisamos usar a classe Comparable

        //Lógica de classificação por bolha
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j].compareTo(array[j + 1]) > 0) {
                    troca(j, j + 1, array);
                }
            }
        }

        //Imprimindo os elementos depois de ordenados
        for (T i : array){
            System.out.print(i + ", ");
        }
        System.out.println();

    }

    public static <T> void troca(int i, int j, T[] a)
    {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
