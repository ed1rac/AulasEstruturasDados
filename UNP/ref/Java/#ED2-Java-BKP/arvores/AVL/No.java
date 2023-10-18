package arvores.AVL;

class No {
    int chave;
    No filhoEsquerda;
    No filhoDireita;
    int altura;

    public No(int chave) {
        this.chave = chave;
        this.filhoEsquerda = null;
        this.filhoDireita = null;
        this.altura = 1;
    }
}
