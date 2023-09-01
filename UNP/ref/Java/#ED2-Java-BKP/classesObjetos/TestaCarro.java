package classesObjetos;

public class TestaCarro {
	public static void main(String[] args) {
		Carro carroDaThays = new Carro();
		
		carroDaThays.modelo = "Wrangler Rubicon";
		carroDaThays.ano = 2022;
		carroDaThays.combustivel = 'D';
		carroDaThays.cor = "Azul Petróleo";
		carroDaThays.placas = "MZW0099";
		
		carroDaThays.exibeDados();
	/*	carroDaThays.ligar();
		carroDaThays.andar(15);
		carroDaThays.parar();
		carroDaThays.desligar();		
	*/	
		Carro carroDaGabi = new Carro();		
		carroDaGabi.modelo = "Shelby Cobra MK13";
		carroDaGabi.cor = "vermelho";
		carroDaGabi.ano = 1968;
		carroDaGabi.combustivel = 'F';
		carroDaGabi.placas = "REPLICA";
		carroDaGabi.exibeDados();
	/*	carroDaGabi.ligar();
		carroDaGabi.desligar();
	*/	
	}

}
