package EstruturasBasicas.Estaticas;

public class ArrayCircular implements EstruturaLinear {
    protected Object[] array;
    protected int inicio, fim, quantidade;

    public ArrayCircular(int tamanho) {
        this.array = new Object[tamanho];
        this.inicio = 0;
        this.fim = tamanho - 1; // Ou tamanho - 1, dependendo da l�gica de implementa��o
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
            System.out.println("A lista est� vazia.");
            return;
        }

        System.out.println("Elementos da lista: \n===========================");

        // Percorre todos os elementos do array circular
        int indice = inicio;
        for (int i = 0; i < quantidade; i++) {
            System.out.println("�ndice " + indice + ": " + array[indice]);

            // Avan�a para o pr�ximo �ndice circularmente
            indice = (indice + 1) % array.length;
        }
    }
}

/*

    A t�cnica de array circular � uma abordagem na qual os �ndices de um array s�o tratados de forma circular, ou seja, quando o �ndice atinge o final do array, ele volta para o in�cio  isso permite que a estrutura de dados utilize todo o espa�o dispon�vel no array de forma eficiente, sem a necessidade de redimensionamento.


    No caso do c�digo fornecido, a t�cnica de array circular � utilizada principalmente nos m�todos `inserir` e `inserirCauda`. Vou explicar como ela funciona em cada um desses m�todos:

1. **M�todo `inserir`**:
   - Quando um novo elemento � inserido na estrutura de dados, o �ndice `inicio` � incrementado e, em seguida, � calculado usando a opera��o de m�dulo `%` com o tamanho do array. Isso garante que, quando o �ndice `inicio` atingir o final do array, ele volte para o in�cio.
   - Por exemplo, se o tamanho do array for 10 e o �ndice `inicio` for 9, ao adicionar mais um elemento, o �ndice `inicio` ser� incrementado para 10. No entanto, como o tamanho do array � 10, o �ndice `inicio` � calculado como `(10 + 1) % 10`, que resulta em 1, indicando o in�cio do array circularmente.

2. **M�todo `inserirCauda`**:
   - Neste m�todo, o novo elemento � inserido no final da estrutura de dados. O �ndice `fim` � decrementado e, em seguida, � calculado usando a opera��o de m�dulo `%` com o tamanho do array, garantindo que, quando o �ndice `fim` atingir o in�cio do array, ele "d� a volta" e aponte para o final do array.
   - Por exemplo, se o tamanho do array for 10 e o �ndice `fim` for 0, ao adicionar mais um elemento, o �ndice `fim` ser� decrementado para -1. Em seguida, � calculado como `(-1 + 10) % 10`, resultando em 9, indicando o final do array circularmente.

    Essa t�cnica permite que os elementos sejam inseridos e removidos na estrutura de dados de forma circular, utilizando todo o espa�o dispon�vel no array, sem precisar aumentar ou diminuir o tamanho do array. Isso proporciona uma implementa��o eficiente e robusta da estrutura de dados de Array Circular.

*/


