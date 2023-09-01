package classesObjetos;

public class Pessoa {
	// atributos
	public String nome;
	public int idade;
	public double peso;
	public double altura;
	public char sexo;
	public static int qtdePessoas = 0;;
	// métodos

	public void exibeInfo() {
		System.out.println("");
		System.out.println("=========================");
		System.out.println("Nome.......: " + this.nome);
		System.out.println("Idade......: " + this.idade);
		System.out.println("Peso.......: " + this.peso);
		System.out.println("Altura.....: " + this.altura);
		System.out.println("Sexo.......: " + this.sexo);
		System.out.println("IMC........:" + this.calculaIMC());
		System.out.println("=========================");
		System.out.println("");
	}
	
	public static void exibeSaudacao() {
		System.out.println("Legal! Esse é um método estático.");
		System.out.println("VocÊ criou uma pessoa!");
		
	}
	
	static void alteraQtd() {
		Pessoa.qtdePessoas++;
	}

	public Pessoa(String nome, int idade, double peso, double altura, char sexo) {
		this.nome = nome;
		this.idade = idade;
		this.peso = peso;
		this.altura = altura;
		this.sexo = sexo;
		Pessoa.exibeSaudacao();
		Pessoa.alteraQtd();
	}

	public Pessoa() {
		Pessoa.alteraQtd();
	}

	public Pessoa(String nome) {
		this.nome = nome;
		Pessoa.alteraQtd();
	}

	public Pessoa(String nome, char sexo) {
		this.nome = nome;
		this.sexo = sexo;
		Pessoa.alteraQtd();
	}
	
	/*protected void finalize() {
		//método destrutor
		//Não é necesseário nem em Java nem em C# por causa do 
		//Garbage Collector
	}
*/
	public double calculaIMC() {
		double imc = peso / (altura * altura);
		return imc;
	}
	

}
