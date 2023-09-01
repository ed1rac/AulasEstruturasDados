package recursividade;

import java.util.Scanner;

public class MetodosRecursivos {

	public static void main(String[] args) {
		System.out.println("Fatoriais até 10");
		for (int i = 0; i <= 10; i++) {
			System.out.printf("%d! = %d\n",	i, fatorial(i));			
		}
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite um número: ");
		int num1 = sc.nextInt();
		System.out.println("Digite um número: ");
		int num2 = sc.nextInt();
		System.out.printf("%d x %d = %d\n", num1, num2, 
				multiplica(num1,num2));
		sc.close();
	}
	
	public static long fatorial(int n) {
		if (n == 0) {
			return 1; //caso básico
		}else {
			return n * fatorial(n-1);
		}
	}
	
	static int multiplica(int num1, int num2) {
		if(num1==0 || num2==0) {
			return 0;
		}else if(num2==1) {
			return num1;
		}else {
			return (num1 + multiplica(num1, num2-1));
		}
	}

}
