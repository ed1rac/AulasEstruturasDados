package basico;

import java.util.Scanner;

public class DoWhile {

	public static void main(String[] args) {
		//int cont = 11;
		int soma = 0;
		Scanner teclado = new Scanner(System.in);
		int num;
		System.out.println("Digite um número maior que zero: ");
		num = teclado.nextInt();
		do {			
			for(int i=0;i<=num;i++) {
				soma+=i; //soma = soma + i
			}
			System.out.println("A soma é: " + soma);
			System.out.println("Digite um número maior que zero: ");
			num = teclado.nextInt();
			soma = 0;
		}while(num!=0);
		System.out.println("Final do programa!");
		teclado.close();
	}
}