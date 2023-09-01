package basico;

import java.lang.Thread.State;

public class MetodosRecursivos {

  public static void main(String[] args) {
    int num = 5;
    System.out.println(fatorial(num));
    /* 	System.out.println("Tabuada de " + num);
		for(int i = 1; i<=12;i++) {
			System.out.println(num + " x " + i + " = " +
					multiplica(num,i));
			
		}
		System.out.println("");
		System.out.println("Potencias de 2");
		for(int i=1;i<=20;i++)
			System.out.println("2 ^ " + i + " = " + eleva(2,i));
*/
  }

  static double fatorial(int n) {
    if (n == 0) {
      return 1;
    } else {
      //System.out.println(tab(n) + n);
      return n * fatorial(n - 1);
    }
    // return n == 0 ? 1 : (n * fatorial(n - 1));
  }

  /*  public static String tab(int n) {
    //insere tabs para organizar a saida
    String recuo = "";
    for (int i = 0; i < n; i++) {
      recuo += "\t";
    }
    return recuo;
  }*/

  public static int mdc(int dividendo, int divisor) {
    if (divisor == 0) return dividendo; else return mdc(
      divisor,
      dividendo % divisor
    );
  }

  static int multiplica(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
      return 0;
    } else if (num2 == 1) {
      return num1;
    } else {
      return (num1 + multiplica(num1, num2 - 1));
    }
  }

  public static int eleva(int base, int expoente) {
    if (expoente == 0) {
      return 1;
    } else {
      return base * eleva(base, expoente - 1);
    }
  }
}
