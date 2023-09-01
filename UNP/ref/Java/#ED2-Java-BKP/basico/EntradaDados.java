package basico;

import java.util.Scanner;

public class EntradaDados {

	public static void main(String[] args) {
		//o meu scanner
		Scanner entrada = new Scanner(System.in);
		//entrada de dados
		System.out.println("Qual é o seu nome?");
		String nome = entrada.nextLine();
		System.out.println("Qual é a sua idade?");
		int idade = entrada.nextInt();
		System.out.println("Qual é a sua altura?");
		double altura = entrada.nextDouble();
		System.out.println("Qual é o seu peso");
		double peso = entrada.nextDouble();
		
		double imc = peso / (altura * altura);
		
		//saída de dados
		System.out.println("Bem vindo, " + nome);
		System.out.println("Você tem " + idade + " anos");
		System.out.println("Sua altura é " + altura);
		System.out.println("Seu IMC é: " + imc);
		entrada.close();
	}
}
