package basico;

public class Aleatorio {

	public static void main(String[] args) {
		for (int i = 1; i <= 10; i++) {
			String numerosCartao = "";
			for (int numCartao = 1; numCartao <= 6; numCartao++) {
				int num = (int) (Math.random() * 61);
				numerosCartao += num + " ";
			}
			System.out.println("Numeros da cartela " + i);
			System.out.println(numerosCartao);
			System.out.println(" ");
		}
	}
}
