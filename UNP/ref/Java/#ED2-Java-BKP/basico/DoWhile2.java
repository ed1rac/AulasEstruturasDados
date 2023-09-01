package basico;

import javax.swing.JOptionPane;

public class DoWhile2 {

	public static void main(String[] args) {
		int limite = Integer.parseInt((JOptionPane.showInputDialog(
				"Digite uma quantidade")));

		int contador = limite;
		while(contador>=0) {
			System.out.println(contador);
			contador--; //contador = contador -1;
		}
		System.out.println("Fim do contador regressivo");
		contador = 0;
		do {
			System.out.println(contador);
			contador++;			
		}while(contador<=limite);
		System.out.println("Fim do contador progressivo");
		System.exit(0);
	}
	

}
