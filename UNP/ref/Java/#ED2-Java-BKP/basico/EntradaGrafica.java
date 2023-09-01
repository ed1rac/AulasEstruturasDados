package basico;
import javax.swing.JOptionPane;

public class EntradaGrafica {

	public static void main(String[] args) {
		String nome = JOptionPane.showInputDialog("Digite seu nome:");
		String idade = JOptionPane.showInputDialog("Digite sua idade: ");
		int age = Integer.parseInt(idade);

		JOptionPane.showMessageDialog(null, "Seu nome é: " + nome + "\nE sua idade é " + age);

	}

}
