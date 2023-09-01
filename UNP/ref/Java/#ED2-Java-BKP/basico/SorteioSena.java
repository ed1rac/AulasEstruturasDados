package basico;

public class SorteioSena {

	public static void main(String[] args) {
		for (int j = 1;j <= 10; j++) {
			System.out.println("Cartela #" + j);
			for (int i = 1; i <= 6; i = i + 1) {
				int num = (int) ((Math.random() * 60) + 1);
				System.out.print(num + "\t");
			}System.out.println("\n");
		}
	}

}
