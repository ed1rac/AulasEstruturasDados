package recursividade;

import java.util.Scanner;

public class TestaPermutacao {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Permutacao p = new Permutacao();
		
		System.out.println("Entre com uma string: ");
		String entrada = scanner.nextLine();
		
		p.permutacaoString("", entrada);
		System.out.println("Quantidade de permutações: " + p.quant);
		
		scanner.close();

	}

}
