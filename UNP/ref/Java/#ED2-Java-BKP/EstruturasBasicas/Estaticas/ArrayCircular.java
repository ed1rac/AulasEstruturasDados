package EstruturasBasicas.Estaticas;

public class ArrayCircular implements EstruturaLinear {
    protected Object[] array;
    protected int inicio, fim, quantidade;

    public ArrayCircular(int tamanho) {
        this.array = new Object[tamanho];
        this.inicio = 0;
        this.fim = tamanho - 1; // Ou tamanho - 1, dependendo da lógica de implementação
        this.quantidade = 0;
    }


    @Override
    public boolean estaVazia() {
        return quantidade == 0;
    }

    public boolean estaCheio() {
        return quantidade >= array.length;
    }

    @Override
    public int tamanho() {
        return quantidade;
    }

    @Override
    public void inserir(Object p) {
        if (quantidade < array.length) {
            array[inicio = (++inicio % array.length)] = p;
            quantidade++;
        }

    }

    @Override
    public void inserirCauda(Object p) {
        if (quantidade < array.length) {
            array[fim] = p;
            fim = (--fim + array.length) % array.length;
            quantidade++;
        }

    }

    @Override
    public Object remover() {
        if (estaVazia())
            return null;
        quantidade--;
        int i = inicio;
        inicio = (--inicio + array.length) % array.length;
        return array[i];
    }

    @Override
    public Object removerCauda() {
        if (estaVazia())
            return null;
        quantidade--;
        return array[fim = (++fim % array.length)];
    }

    public void exibirElementos() {
        if (estaVazia()) {
            System.out.println("A lista está vazia.");
            return;
        }

        System.out.println("Elementos da lista: \n===========================");

        // Percorre todos os elementos do array circular
        int indice = inicio;
        for (int i = 0; i < quantidade; i++) {
            System.out.println("Índice " + indice + ": " + array[indice]);

            // Avança para o próximo índice circularmente
            indice = (indice + 1) % array.length;
        }
    }
}

/*

    A técnica de array circular é uma abordagem na qual os índices de um array são tratados de forma circular, ou seja, quando o índice atinge o final do array, ele volta para o início  isso permite que a estrutura de dados utilize todo o espaço disponível no array de forma eficiente, sem a necessidade de redimensionamento.


    No caso do código fornecido, a técnica de array circular é utilizada principalmente nos métodos `inserir` e `inserirCauda`. Vou explicar como ela funciona em cada um desses métodos:

1. **Método `inserir`**:
   - Quando um novo elemento é inserido na estrutura de dados, o índice `inicio` é incrementado e, em seguida, é calculado usando a operação de módulo `%` com o tamanho do array. Isso garante que, quando o índice `inicio` atingir o final do array, ele volte para o início.
   - Por exemplo, se o tamanho do array for 10 e o índice `inicio` for 9, ao adicionar mais um elemento, o índice `inicio` será incrementado para 10. No entanto, como o tamanho do array é 10, o índice `inicio` é calculado como `(10 + 1) % 10`, que resulta em 1, indicando o início do array circularmente.

2. **Método `inserirCauda`**:
   - Neste método, o novo elemento é inserido no final da estrutura de dados. O índice `fim` é decrementado e, em seguida, é calculado usando a operação de módulo `%` com o tamanho do array, garantindo que, quando o índice `fim` atingir o início do array, ele "dê a volta" e aponte para o final do array.
   - Por exemplo, se o tamanho do array for 10 e o índice `fim` for 0, ao adicionar mais um elemento, o índice `fim` será decrementado para -1. Em seguida, é calculado como `(-1 + 10) % 10`, resultando em 9, indicando o final do array circularmente.

    Essa técnica permite que os elementos sejam inseridos e removidos na estrutura de dados de forma circular, utilizando todo o espaço disponível no array, sem precisar aumentar ou diminuir o tamanho do array. Isso proporciona uma implementação eficiente e robusta da estrutura de dados de Array Circular.

*/


