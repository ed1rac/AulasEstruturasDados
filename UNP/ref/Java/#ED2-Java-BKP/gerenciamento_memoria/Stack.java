package gerenciamento_memoria;


class Stack {
    public static void main(String[] args) {
        int x = 5;
        System.out.println(x);

        Pessoa p, p2;
        p = new Pessoa("Felipe Miranda", 25);
        p2 = p;        
        System.out.println("Exibindo p1: ");
        System.out.println(p.exibePessoa());
        System.out.println("Exibindo p2: ");
        System.out.println(p2.exibePessoa());

  
    }

}