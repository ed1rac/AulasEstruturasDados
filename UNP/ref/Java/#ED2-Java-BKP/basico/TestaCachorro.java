package basico;

public class TestaCachorro {

	public static void main(String[] args) {
		Cachorro caoKaline;
		caoKaline = new Cachorro();
		
		/*caoKaline.nome = "Platão";
		caoKaline.idade = 2;
		caoKaline.sexo = 'M';
		caoKaline.raca = "Beagle";
		*/
		
		caoKaline.insereDados();
		caoKaline.exibeDados();
		caoKaline.latir();
		caoKaline.passear();
		caoKaline.comer();
		
		Cachorro caoMurilo = new Cachorro();
		
		caoMurilo.nome = "Nestor";
		caoMurilo.idade = 3;
		caoMurilo.raca = "Schnauzer";
		caoMurilo.sexo = 'M';
		caoMurilo.exibeDados();
		caoMurilo.latir();
		caoMurilo.passear(2);
		caoMurilo.comer();

	}
}
