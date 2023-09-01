package basico;

public class TestaCarro {

	public static void main(String[] args) {
		Carro meuCarro;
		meuCarro= new Carro();
		
		Carro outroCarro = new Carro();
		
		meuCarro.ano=2018;
		meuCarro.cor="Branca";
		meuCarro.modelo="Prisma LTZ AUT";
		System.out.println(meuCarro.modelo);
		System.out.println(meuCarro.ano);
		System.out.println(meuCarro.cor);
		meuCarro.ligar();
		meuCarro.andar();
		meuCarro.parar();
		meuCarro.desligar();
		
		outroCarro.ano = 2022;

	}

}
