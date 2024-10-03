package EstruturasBasicas.Estaticas;

public interface EstruturaLinear {

    public boolean estaVazia();

    public int tamanho();

    public void inserir(Object p);

    public void inserirCauda(Object p);

    public Object remover();

    public Object removerCauda();

}
