package ref.Java.Basico.Generics.LinkedList;

import java.util.LinkedList;
import java.util.List;

public class Curso {
  private String nome;
  private String instrutor;
  private List<Aula> aulas = new LinkedList<Aula>();

  public Curso(String nome, String instrutor) {
    this.nome = nome;
    this.instrutor = instrutor;
  }

  public String getNome() {
    return nome;
  }

  public String getInstrutor() {
    return instrutor;
  }

  public List<Aula> getAulas() {
    return aulas;
  }

  public void adiciona(Aula aula) {
    this.aulas.add(aula);
  }
}
/*E se tivéssemos usado ArrayList na declaração do atributo aulas da classe Curso? O resultado seria exatamente o mesmo!

Então qual é a diferença? Basicamente performance. O ArrayList, como diz o nome, internamente usa um array para guardar os elementos. Ele consegue fazer operações de maneira muito eficiente, como invocar o método get(indice). Se você precisa pegar o décimo quinto elemento, ele te devolverá isso bem rápido. Quando um ArrayList é lento? Quando você for, por exemplo, inserir um novo elemento na primeira posição. Pois a implementação vai precisar mover todos os elementos que estão no começo da lista para a próxima posição. Se há muitos elementos, isso vai demorar... Em computação, chamamos isso de consumo de tempo linear.

Já o LinkedList possui uma grande vantagem aqui. Ele utiliza a estrutura de dados chamada lista ligada, e é bastante rápido para adicionar e remover elementos na cabeça da lista, isto é, na primeira posição. Mas é lento se você precisar acessar um determinado elemento, pois a implementação precisará percorrer todos os elementos até chegar ao décimo quinto, por exemplo.

Confuso? Não tem problema. Sabe o que é interessante? Você não precisa tomar essa decisão desde já e oficializar para sempre. Como utilizamos a referência a List, comprometendo-nos pouco, podemos sempre mudar a implementação, isso é, em quem damos new, caso percebamos que é melhor uma ou outra lista nesse caso em particular */
