package classesObjetos;

public class TestaPessoa2 {
	public static void main(String[] args) {

		Pessoa p1 = new Pessoa("João das Neves", 34, 78, 1.80, 'M');
		Pessoa p2 = new Pessoa("Daenerys Targaryen");
		Pessoa p3 = new Pessoa("Rhaenyra Targaryen", 'F');

		p2.idade = 29;
		p2.altura = 1.65;
		p2.peso = 62;
		p2.sexo = 'F';
		
		p1.exibeInfo();
		p2.exibeInfo();
		p3.exibeInfo();
		System.out.println(Pessoa.qtdePessoas);
	}
}
