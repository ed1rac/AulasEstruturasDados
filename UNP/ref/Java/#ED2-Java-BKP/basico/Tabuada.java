package basico;

import java.util.Scanner;

public class Tabuada {

	public static void main(String[] args) {
		//int num = 5;
		Scanner teclado = new Scanner(System.in);
		System.out.println("Digite um número: ");
		int num = teclado.nextInt();
		System.out.println("Tabuada de " +  num);
		System.out.println("=============");
		for(int i = 1;i<=10;i++) {
			System.out.println(num + " x " + i + " = " + (num * i));
		}
		teclado.close();

	}

}
