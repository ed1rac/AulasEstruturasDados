package basico;

import java.util.Calendar;

public class Calendario {

	public static void main(String[] args) {
		Calendar c1 = Calendar.getInstance();
		System.out.println(c1.get(Calendar.YEAR));
		
	/*	Calendar c2 = new GregorianCalendar();
		c2.setTimeInMillis(System.currentTimeMillis());
		System.out.println(c2.get(Calendar.YEAR));
*/
		System.out.println(c1.get(Calendar.MONTH));


	}

}
