package generics;

public class ClasseGenerica<T> { //Primeiro essa sintaxe aqui: usamos < > para especificar o tipo de parâmetro
    //Um objeto do tipo T é declarado
    T objeto;

    public ClasseGenerica(T objeto) {  //construtor
        this.objeto = objeto;
    }
    public T getObjeto() {
        return this.objeto;
    }

    public static void main(String[] args) {

        exibeSplashScreen();
        //Instância de um tipo Inteiro
        ClasseGenerica<Integer> objetoInteiro = new ClasseGenerica<Integer>(10);
        System.out.println("Objeto Inteiro: " + objetoInteiro.getObjeto());

        //Instância de um tipo String
        ClasseGenerica<String> objetoString = new ClasseGenerica<String>("Estruturas de Dados");
        System.out.println("Objeto String: " + objetoString.getObjeto());

    }

    public static void exibeSplashScreen(){
        System.out.println("  ____ _____ _   _ _____ ____  ___ ____ ____  ");
        System.out.println(" / ___| ____| \\ | | ____|  _ \\|_ _/ ___/ ___| ");
        System.out.println("| |  _|  _| |  \\| |  _| | |_) || | |   \\___ \\ ");
        System.out.println("| |_| | |___| |\\  | |___|  _ < | | |___ ___) |");
        System.out.println(" \\____|_____|_| \\_|_____|_| \\_\\___\\____|____/ ");
    }
}
/*
    Parâmetros em Java Generics
    ============================
    As convenções de nomenclatura dos parâmetros de tipo são importantes para aprender
    completamente os genéricos. Os parâmetros de tipo comuns são os seguintes:

        T – Tipo
        E – Elemento
        K – Chave
        N – Número
        V – Valor

*/
