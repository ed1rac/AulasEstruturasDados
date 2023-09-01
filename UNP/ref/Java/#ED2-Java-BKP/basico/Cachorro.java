package basico;

import java.util.Scanner;

public class Cachorro {
	// atributos
	String nome;
	int idade;
	char sexo;
	String raca;

	// métodos
	void latir() {
		System.out.println("O cão chamado " + nome + " está latindo!");
	}

	void passear() {
		System.out.println("O cão chamado " + nome + " está passeando!");
	}

	void passear(int km) {
		System.out.println("O cão chamado " + nome + " está passeando!");
		System.out.println("Ele vai passear " + km + " km");
	}

	void comer() {
		System.out.println("O cão chamado " + nome + " está comendo!");
	}

	void exibeDados() {
		System.out.println("");
		System.out.println("=================");
		System.out.println("Nome.......: " + nome);
		System.out.println("Idade......: " + idade);
		System.out.println("Sexo.......: " + sexo);
		System.out.println("Raça.......: " + raca);
		System.out.println("=================");
		System.out.println("");
	}

	void insereDados() {
		// Cachorro cao = new Cachorro();
		Scanner sc = new Scanner(System.in);

		System.out.println("Digite o nome do cão: ");
		this.nome = sc.nextLine();
		System.out.println("Digite a raça do cão: ");
		raca = sc.nextLine();
		System.out.println("Digite a idade do cão: ");
		idade = sc.nextInt();
		System.out.println("Digite o sexo do cão ('M' ou 'F')");
		sexo = sc.next().toUpperCase().charAt(0);
		sc.close();
		// return c;
	}

}
