package basico;

public class MetodosSemretorno {

	public static void main(String[] args) {
		exibeBoasVindas();
		print("Olá mundo! Com métodos!");
		soma(2, 3);
		System.out.println(MetodosComRetorno.potencia(2, 3));
	}

	static void exibeBoasVindas() {
		System.out.print("Aprendendo Métodos em Java");
		pulaLinha(2);
		System.out.print("Olha que legal!");
	}

	static void print(String texto) {
		System.out.println(texto);
	}

	static void soma(int a, int b) {
		System.out.println(a + b);
	}
	
	static void pulaLinha(int quant) {
		for(int i = 1;i<=quant;i++) {
			System.out.print("\n");
		}
	}
	

}
