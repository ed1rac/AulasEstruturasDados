package basico;

import javax.swing.JOptionPane;

public class MetodosStrings {
	public static void main(String[] args) {
		String frase = JOptionPane.showInputDialog("Forneça uma frase: ");
		int tamanho = frase.length();
		System.out.println("Frase: " + frase);
		System.out.println("tamanho: " + tamanho);
		System.out.println("Maiúscula: " + frase.toUpperCase());
		System.out.println("Minúscula: " + frase.toLowerCase());
		System.out.println("Remover espaços antes e depois: " + frase.trim());
		System.out.println("Substituindo: " + frase.replace(" ", "-"));
		
		System.out.println("Mostrando caractere por caractere");
		for(int i=0;i<tamanho;i++)
			System.out.println(frase.charAt(i));
		
		
		
		
	}

}
