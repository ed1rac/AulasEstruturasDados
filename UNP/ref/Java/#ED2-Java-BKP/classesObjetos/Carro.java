package classesObjetos;
public class Carro {
	//atributos
	public String modelo;
	public int ano;
	public String cor;
	public String placas;
	public char combustivel;	
	
	//métodos
	public void exibeDados() {
		System.out.println("====================");
		retornaModelo();
		System.out.println("Ano.....:" + ano);
		System.out.println("Cor.....:" + cor);
		System.out.println("Placas..:" + placas);
		System.out.println("Combustível:" + retornaCombustivel());
		System.out.println("====================");
		System.out.println();
	}
	public String retornaCombustivel(){
		String retorno = null; 
		if(combustivel=='G') {
			retorno = "Gasolina";
		}else if(combustivel=='F') {
			retorno = "Flex";
		}else if(combustivel=='D') {
			retorno = "Diesel";
		}
		return retorno;			
	}
	public void retornaModelo() {
		System.out.println("O modelo do carro é: " + modelo);
	}
	
	public void andar(double km){
		System.out.println("O carro vai andar " + 
				km + " quilômetros");
	}
	void parar(){
		System.out.println("O carro parou!");
	}
	void ligar(){
		System.out.println("O carro ligou!");
	}
	void desligar(){
		System.out.println("Carro desligou!");
	}
	
	
}