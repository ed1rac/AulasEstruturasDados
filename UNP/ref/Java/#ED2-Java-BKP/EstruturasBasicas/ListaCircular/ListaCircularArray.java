package EstruturasBasicas.ListaCircular;

public class ListaCircularArray {
    //lista circular em array
    private Object[] elementos;

    public ListaCircularArray(int maximo){
        this.elementos = new Object[maximo];
    }

    public boolean estaVazia(){
        return this.elementos[0] == null;
    }

    public boolean estaCheia(){
        return this.elementos[this.elementos.length-1] != null;
    }

    public void insere(Object elemento){
        if(this.estaCheia()){
            System.out.println("Lista cheia");
        }else{
            int i = 0;
            while(this.elementos[i] != null){
                i++;
            }
            this.elementos[i] = elemento;
        }
    }

    public void remove(Object elemento){
        if(this.estaVazia()){
            System.out.println("Lista vazia");
        }else{
            int i = 0;
            while(this.elementos[i] != elemento){
                i++;
            }
            this.elementos[i] = null;
            while(this.elementos[i+1] != null){
                this.elementos[i] = this.elementos[i+1];
                i++;
            }
            this.elementos[i] = null;
        }
    }

    public void imprime(){
        if(this.estaVazia()){
            System.out.println("Lista vazia");
        }else{
            for(int i = 0; i < this.elementos.length; i++){
                if(this.elementos[i] != null) System.out.println(this.elementos[i]);
            }
        }
    }

    public static void main(String[] args) {
        ListaCircularArray lista = new ListaCircularArray(20);
        lista.insere("Edkallenn");
        lista.insere(4);
        lista.insere("Maria");
        lista.insere(5);
        lista.insere("João");
        lista.insere(6);
        lista.insere("José");
        lista.insere(7);
        lista.insere("Pedro");
        lista.insere(8);
        lista.insere("Paulo");
        lista.insere(9);
        lista.imprime();
        System.out.println("Removendo");
        lista.remove("Maria");
        lista.imprime();
    }
    


}
