package basico;

public class MetodosComRetorno {

	public static void main(String[] args) {
		MetodosSemretorno.exibeBoasVindas();
		System.out.println(somar(2, 3));
		for (int i = 0; i <= 20; i++) {
			System.out.print("O fatorial de " + i + " é ");
			System.out.println(fatorial(i));
		}
	}

	static double potencia(double x, double y) {
		return Math.pow(x, y);
	}

	static double somar(double num1, double num2) {
		return num1 + num2;
	}

	static double fatorial(int n) {

		if (n == 0) {
			return 1;
		} else {
			return n * fatorial(n - 1);
		}

		// return n == 0 ? 1 : (n * fatorial(n - 1));

	}

	static double fat(int n) { // fatorial NÃO RECURSIVO
		double fatorial = 1;
		for (int i = 1; i <= n; i++) {
			fatorial *= i; // fatorial = fatorial * i
		}
		return fatorial;
	}

}
