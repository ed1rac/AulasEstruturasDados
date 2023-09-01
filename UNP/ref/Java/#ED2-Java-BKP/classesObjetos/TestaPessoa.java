package classesObjetos;

public class TestaPessoa {
	public static void main(String[] args) {
		Pessoa p1 = new Pessoa(); //instanciando
		Pessoa p2 = new Pessoa();
		//instanciar é criar objetos a partir de classes
		p1.nome = "Alicent Hightower";
		p1.idade = 28;
		p1.altura = 1.68;
		p1.peso = 54;
		p1.sexo = 'F';
		p1.exibeInfo();
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p1.calculaIMC());
		p2 = p1;		
		
		Pessoa.exibeSaudacao();
		System.out.println(Pessoa.qtdePessoas);
		//Pessoa.exibeInfo();
		
		System.out.println(p1);
		System.out.println(p2);
		p2.nome = "Rhaenyra Targaryen";
	//	p2.idade = 32;
		p1.exibeInfo();
		System.out.println(Pessoa.qtdePessoas);
	}
}




