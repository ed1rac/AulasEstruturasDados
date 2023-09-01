package EstruturasBasicas.ListasTiposGenericos;

public class Celula<T> {
    T info;
    Celula<T> proximo;

    @Override
    public String toString() {
        return "Celula{" + "info=" + info + "}->";
    }
}
