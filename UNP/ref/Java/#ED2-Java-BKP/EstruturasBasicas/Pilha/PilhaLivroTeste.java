package EstruturasBasicas.Pilha;

import java.util.EmptyStackException;

// Definição do TAD Pilha
public class PilhaLivroTeste<T> {
    private Celula<T> top;

    // Definição da estrutura do nó da pilha
    private static class Celula<T> {
        private T info;
        private Celula<T> proximo;

        public Celula(T info) {
            this.info = info;
        }
    }

    // Operação para verificar se a pilha está vazia
    public boolean estaVazia() {
        return top == null;
    }

    // Operação para adicionar um elemento no topo da pilha
    public void push(T info) {
        Celula<T> novaCelula = new Celula<T>(info);
        novaCelula.proximo = top;
        top = novaCelula;
    }

    // Operação para remover e retornar o elemento no topo da pilha
    public T pop() {
        if (estaVazia()) {
            throw new EmptyStackException();
        }
        T info = top.info;
        top = top.proximo;
        return info;
    }

    // Operação para consultar o elemento no topo da pilha
    public T peek() {
        if (estaVazia()) {
            throw new EmptyStackException();
        }
        return top.info;
    }

    public static void main(String[] args) {
        PilhaLivroTeste<Integer> Pilha = new PilhaLivroTeste<Integer>();

        Pilha.push(3);
        Pilha.push(5);
        Pilha.push(7);

        System.out.println("Pilha: ");
        while (!Pilha.estaVazia()) {
            System.out.println(Pilha.pop());
        }
    }
}

