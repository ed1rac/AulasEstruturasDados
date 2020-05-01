/*
** Função: LP_ExecFinal_27
** Autor(a): Pablo italo
** Data:  08/12/2016
** Observações:  
*/
import java.util.Scanner;
public class TriplaPitagoras {
 public static void main(String[] args) {
   Scanner sc = new Scanner(System.in);
    
       int lado1, lado2, hipotenusa; 
   for (lado1=1; lado1 <= 500; lado1++) 
      for (lado2=1; lado2<=500; lado2++) 
         for (hipotenusa=1; hipotenusa<=500; hipotenusa++) 
            if ((hipotenusa * hipotenusa) == (lado1 * lado1 + lado2 * lado2)) 
				System.out.printf("%d\t%d\t%d\n", lado1, lado2, hipotenusa);
	
	   


 
 }
}