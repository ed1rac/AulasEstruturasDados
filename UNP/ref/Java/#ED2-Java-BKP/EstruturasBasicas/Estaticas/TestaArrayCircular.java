package EstruturasBasicas.Estaticas;

public class TestaArrayCircular
{
    public static void main(String[] args) {
        ArrayCircular arrayCircular;
        arrayCircular = new ArrayCircular(10);


        // Verificando se est� vazio
        System.out.println("Est� vazio? " + arrayCircular.estaVazia()); // Deve imprimir true

        // Inserindo alguns elementos
        arrayCircular.inserir("Elemento 1");
        arrayCircular.inserir("Elemento 2");
        arrayCircular.inserir("Elemento 3");

        arrayCircular.exibirElementos();

        // Verificando o tamanho
        System.out.println("Tamanho: " + arrayCircular.tamanho()); // Deve imprimir 3

        // Verificando se est� cheio
        System.out.println("Est� cheio? " + arrayCircular.estaCheio()); // Deve imprimir false

        // Removendo um elemento
        Object elementoRemovido = arrayCircular.remover();
        System.out.println("Elemento removido: " + elementoRemovido); // Deve imprimir "Elemento 1"

        // Verificando o tamanho novamente
        System.out.println("Tamanho: " + arrayCircular.tamanho()); // Deve imprimir 2

        // Inserindo mais elementos
        arrayCircular.inserir("Elemento 4");
        arrayCircular.inserir("Elemento 5");

        arrayCircular.exibirElementos();
        // Verificando se est� cheio agora
        System.out.println("Est� cheio? " + arrayCircular.estaCheio()); // Deve imprimir true

        // Tentando inserir mais um elemento (n�o deve ser poss�vel, pois est� cheio)
        arrayCircular.inserir("Elemento 6"); // N�o deve adicionar nada

        // Removendo elementos at� esvaziar
        while (!arrayCircular.estaVazia()) {
            System.out.println("Elemento removido: " + arrayCircular.remover());
        }
        System.out.println("Est� vazio? " + arrayCircular.estaVazia()); // Deve imprimir true

        arrayCircular.exibirElementos();


    }
}
