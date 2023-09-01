package classesObjetos;

public class TestaCachorro {

	public static void main(String[] args) {

		Cachorro ayla = new Cachorro("Ayla", 2, "Poodle", 'F', 5);
		Cachorro snow = new Cachorro();
		Cachorro c = new Cachorro("Theo", "Cho Chow");
		Cachorro c1 = new Cachorro("Zeus");
		Cachorro c2 = new Cachorro();

		snow.nome = "John Snow";
		snow.raca = "SRD";
		snow.idade = 2;
		snow.peso = 13;
		snow.sexo = 'M';
		
		c.idade = 2;
		c.peso = 20;		
		c.sexo = 'M';

		snow.exibeDados();
		ayla.exibeDados();
		c.exibeDados();
		c1.exibeDados();
		c2.exibeDados();
		
		snow.latir();
		snow.passear();
		snow.comer();

		ayla.latir();
		ayla.passear();
		ayla.comer();

		
		c.latir();
		c.passear();
		c.comer();

	}

}
