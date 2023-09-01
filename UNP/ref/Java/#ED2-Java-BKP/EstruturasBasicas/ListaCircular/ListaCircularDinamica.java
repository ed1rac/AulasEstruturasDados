package EstruturasBasicas.ListaCircular;

public class ListaCircularDinamica {
    // lista circular dinamica usando a classe Celula como n� da lista
    private Celula cabeca;
    private Celula cauda;
    private int tamanho;

    public ListaCircularDinamica() {
        this.cabeca = null;
        this.cauda = null;
        this.tamanho = 0;
    }

    public void adicionar(Object elemento) {
        Celula nova = new Celula(elemento);
        if (this.tamanho == 0) {
            this.cabeca = nova;
            this.cauda = nova;
            this.cauda.setProximo(this.cabeca);
        } else {
            this.cauda.setProximo(nova);
            this.cauda = nova;
            this.cauda.setProximo(this.cabeca);
        }
        this.tamanho++;
    }

    public void adicionar(int posicao, Object elemento) {
        if (posicao == 0) {
            this.adicionarNoComeco(elemento);
        } else if (posicao == this.tamanho) {
            this.adicionar(elemento);
        } else {
            Celula anterior = this.cabeca;
            for (int i = 0; i < posicao - 1; i++) {
                anterior = anterior.getProximo();
            }
            Celula nova = new Celula(elemento, anterior.getProximo());
            anterior.setProximo(nova);
            this.tamanho++;
        }
    }

    public void adicionarNoComeco(Object elemento) {
        if (this.tamanho == 0) {
            this.adicionar(elemento);
        } else {
            Celula nova = new Celula(elemento, this.cabeca);
            this.cabeca = nova;
            this.cauda.setProximo(this.cabeca);
            this.tamanho++;
        }
    }

    public Object remover(int posicao) {
        if (posicao == 0) {
            return this.removerDoComeco();
        } else if (posicao == this.tamanho - 1) {
            return this.remover();
        } else {
            Celula anterior = this.cabeca;
            for (int i = 0; i < posicao - 1; i++) {
                anterior = anterior.getProximo();
            }
            Celula removida = anterior.getProximo();
            anterior.setProximo(removida.getProximo());
            this.tamanho--;
            return removida.getElemento();
        }
    }

    public Object remover() {
        if (this.tamanho == 1) {
            return this.removerDoComeco();
        } else {
            Celula penultima = this.cabeca;
            for (int i = 0; i < this.tamanho - 2; i++) {
                penultima = penultima.getProximo();
            }
            Celula removida = penultima.getProximo();
            penultima.setProximo(this.cabeca);
            this.cauda = penultima;
            this.tamanho--;
            return removida.getElemento();
        }
    }

    public Object removerDoComeco() {
        if (this.tamanho == 1) {
            Celula removida = this.cabeca;
            this.cabeca = null;
            this.cauda = null;
            this.tamanho--;
            return removida.getElemento();
        } else {
            Celula removida = this.cabeca;
            this.cabeca = removida.getProximo();
            this.cauda.setProximo(this.cabeca);
            this.tamanho--;
            return removida.getElemento();
        }
    }

    public Object buscar(int posicao) {
        if (posicao == 0) {
            return this.cabeca.getElemento();
        } else if (posicao == this.tamanho - 1) {
            return this.cauda.getElemento();
        } else {
            Celula atual = this.cabeca;
            for (int i = 0; i < posicao; i++) {
                atual = atual.getProximo();
            }
            return atual.getElemento();
        }
    }

    public int buscar(Object elemento) {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if (atual.getElemento().equals(elemento)) {
                return i;
            }
            atual = atual.getProximo();
        }
        return -1;
    }

    public int tamanho() {
        return this.tamanho;
    }

    public boolean contem(Object elemento) {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if (atual.getElemento().equals(elemento)) {
                return true;
            }
            atual = atual.getProximo();
        }
        return false;
    }

    public String toString() {
        if (this.tamanho == 0) {
            return "[]";
        } else {
            StringBuilder builder = new StringBuilder("[");
            Celula atual = this.cabeca;
            for (int i = 0; i < this.tamanho - 1; i++) {
                builder.append(atual.getElemento());
                builder.append(", ");
                atual = atual.getProximo();
            }
            builder.append(atual.getElemento());
            builder.append("]");
            return builder.toString();
        }
    }

    public void limpar() {
        this.cabeca = null;
        this.cauda = null;
        this.tamanho = 0;
    }

    public void inverter() {
        Celula atual = this.cabeca;
        Celula anterior = null;
        Celula proximo = null;
        while (atual != null) {
            proximo = atual.getProximo();
            atual.setProximo(anterior);
            anterior = atual;
            atual = proximo;
        }
        this.cabeca = anterior;
        this.cauda = this.cabeca;
    }

    public ListaCircularDinamica copiar() {
        ListaCircularDinamica nova = new ListaCircularDinamica();
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            nova.adicionar(atual.getElemento());
            atual = atual.getProximo();
        }
        return nova;
    }

    public void concatenar(ListaCircularDinamica lista) {
        Celula atual = lista.cabeca;
        for (int i = 0; i < lista.tamanho; i++) {
            this.adicionar(atual.getElemento());
            atual = atual.getProximo();
        }
    }

       public void remover(Object elemento) {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if (atual.getElemento().equals(elemento)) {
                this.remover(i);
            }
            atual = atual.getProximo();
        }
    }

    public void removerOcorrencias(Object elemento) {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if (atual.getElemento().equals(elemento)) {
                this.remover(i);
                i--;
            }
            atual = atual.getProximo();
        }
    }

    public void removerPares() {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if ((int) atual.getElemento() % 2 == 0) {
                this.remover(i);
                i--;
            }
            atual = atual.getProximo();
        }
    }

    public void removerImpares() {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if ((int) atual.getElemento() % 2 != 0) {
                this.remover(i);
                i--;
            }
            atual = atual.getProximo();
        }
    }

    public void removerMultiplos(int multiplo) {
        Celula atual = this.cabeca;
        for (int i = 0; i < this.tamanho; i++) {
            if ((int) atual.getElemento() % multiplo == 0) {
                this.remover(i);
                i--;
            }
            atual = atual.getProximo();
        }
    }


    // método main para testar a classe

    public static void main(String[] args) {
        ListaCircularDinamica lista = new ListaCircularDinamica();
        lista.adicionar("Edkallenn");
        lista.adicionar(2);
        lista.adicionar(3);
        lista.adicionar(4);
        lista.adicionar(5);
        lista.adicionar(6);
        lista.adicionar(7);
        lista.adicionar(8);
        lista.adicionar(9);
        lista.adicionar(10);
        lista.adicionar(11);
        lista.adicionar(12);
        lista.adicionar(13);
        lista.adicionar(14);
        lista.adicionar(15);
        lista.adicionar(16);
        lista.adicionar(17);
        lista.adicionar(18);
        lista.adicionar(19);
        lista.adicionar(20);
        lista.adicionar(21);
        lista.adicionar(22);
        lista.adicionar(23);

        System.out.println(lista);



        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);
        lista.remover(0);

        System.out.println(lista);

    }

}
