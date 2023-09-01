package basico;
public class Variaveis {

	public static void main(String[] args) {
		//DECLARA VARI�VEIS
		//SINTXE:
		
		// <TIPO> <nome_da_variavel>
		
		//ATRIBUI��O
		//<nome_da_variavel> = <valor>
		
		String nome = "Gabi";
		char sexo = 'F'; 
		double pesoDaGabi = 41.5;
		String y = " anos ";
		int idade= 25;
		System.out.printf("A idade da %s � %d %s\n", nome, idade, y);
		idade = idade + 1;
		System.out.println("Ano que vem ela ter� " + idade + y);
		System.out.print("O peso dela �: " + pesoDaGabi);
		System.out.print(" kg\n");
		System.out.println("O sexo �: " + sexo);
		

	}

}
