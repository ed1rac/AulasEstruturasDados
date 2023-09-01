package EstruturasBasicas.ListasTiposGenericos;

public class Lista<T> {
    //a classe lista começa mesmo aqui
    Celula<T> primeiro;
    Celula<T> ultimo;
    int tamanho;

    public Lista() {
        this.tamanho = 0;
    }

    // Método para adicionar um elemento na lista
    public void adicionar(T informacao) {
        Celula<T> novaCelula = new Celula<>();
        novaCelula.info = informacao;
        novaCelula.proximo = null;

        if (primeiro == null) {
            primeiro = novaCelula;
        } else {
            ultimo.proximo = novaCelula;
        }
        ultimo = novaCelula;
        tamanho++;
    }

    // Método para imprimir a lista de forma recursiva!
    public void imprimir() {
        imprimirNo(primeiro);
    }

    private void imprimirNo(Celula<T> celula) {
        if (celula != null) {
            System.out.println(""+celula.info);
            imprimirNo(celula.proximo);
        }
    }

    public static void main(String[] args) {
        Lista<String> listaDeStrings = new Lista<>();
        listaDeStrings.adicionar("Elemento 1");
        listaDeStrings.adicionar("Elemento 2");
        listaDeStrings.adicionar("Elemento 3");
        listaDeStrings.imprimir();  // Imprime: Elemento 1, Elemento 2, Elemento 3

        Lista<Integer> listaDeInteiros = new Lista<>();
        listaDeInteiros.adicionar(1);
        listaDeInteiros.adicionar(2);
        listaDeInteiros.adicionar(3);
        listaDeInteiros.imprimir();  // Imprime: 1, 2, 3

        Lista<Object> listaObjetos = new Lista<>();
        listaObjetos.adicionar("Primeiro Objeto");
        listaObjetos.adicionar(8);
        listaObjetos.adicionar(new Pessoa("Edkallenn", 43));
        listaObjetos.imprimir();

}


}

