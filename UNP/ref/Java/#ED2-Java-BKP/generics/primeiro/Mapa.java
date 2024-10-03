package generics.primeiro;

import java.util.HashMap;
import java.util.Map;

public class Mapa<K, V> {
    private Map<K, V> mapa = new HashMap<>();
    public void adicionar(K chave, V valor) {
        mapa.put(chave, valor);
    }
    public V obter(K chave) {
        return mapa.get(chave);
    }

    public static void main(String[] args) {
        // Criando uma instância da classe Mapa para armazenar pares de String e Integer
        Mapa<String, Integer> mapaIdade = new Mapa<>();
        // Adicionando pares chave-valor ao mapa
        mapaIdade.adicionar("Alice", 30);
        mapaIdade.adicionar("Bob", 25);
        mapaIdade.adicionar("Carol", 28);
        // Recuperando valores a partir das chaves
        System.out.println("Idade de Alice: " + mapaIdade.obter("Alice"));
        System.out.println("Idade de Bob: " + mapaIdade.obter("Bob"));
        System.out.println("Idade de Carol: " + mapaIdade.obter("Carol"));
        // Criando uma instância da classe Mapa para armazenar pares de Integer e String
        Mapa<Integer, String> mapaCodigoProduto = new Mapa<>();
        // Adicionando pares chave-valor ao mapa
        mapaCodigoProduto.adicionar(1001, "Teclado");
        mapaCodigoProduto.adicionar(1002, "Mouse");
        mapaCodigoProduto.adicionar(1003, "Monitor");
        // Recuperando valores a partir das chaves
        System.out.println("\nProduto com código 1001: " + mapaCodigoProduto.obter(1001));
        System.out.println("Produto com código 1002: " + mapaCodigoProduto.obter(1002));
        System.out.println("Produto com código 1003: " + mapaCodigoProduto.obter(1003));

        Mapa<Pessoa, Pessoa> mapaNamoro = new Mapa<>();
        Pessoa c = new Pessoa("Caio", 21);
        mapaNamoro.adicionar(c,new Pessoa("Joana", 19));
        //System.out.println("Namorada do Caio: " + mapaNamoro.obter(c.getNome())); //--> Não funciona

        // Pesquisar a namorada do Caio
        Pessoa pesquisada = new Pessoa("Caio", 21);
        Pessoa namorada = mapaNamoro.obter(pesquisada);
        System.out.println("Namorada do Caio: " + namorada);
    }
}
