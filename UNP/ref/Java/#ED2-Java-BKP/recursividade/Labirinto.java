/**
 *  O labirinto é representado por um array bidimensional tipo char, onde '#' são paredes e '.' são caminhos a serem percorridos.

    Através da recursividade, você terá que percorrer este labirinto, onde a cada passo que possui um '.' seja marcado com um 'x'. Caso você seja levado a um caminho errado, este caminho deverá ser preenchido com uma 'o' ao invés do 'x' e tentar ir em outra direção
 */
package recursividade;

import java.util.Scanner;
import java.util.Random;

public class Labirinto {
    private char[][] maze; // representação do labirinto
    private int linha,
            coluna;
    Scanner input = new Scanner(System.in);
    Random randomNumber = new Random();

    private int coordenadaLinhaEntrada,
            coordenadaLinhaSaida,
            coordenadaColunaEntrada,
            coordenadaColunaSaida;

    private boolean mazeStatus = false; // inicia o status do maze como falso (sem saída)

    // construtor Labirinto sem argumentos
    public Labirinto() {
        // determina a quantidade de linhas e colunas
        System.out.print("Quantidade de linhas que o labirinto possui ( > 4 ): ");
        setLinha(input.nextInt());
        System.out.print("Quantidade de colunas que o labirinto possui ( > 4 ): ");
        setColuna(input.nextInt());

        mazeComSaida(); // maze gerado aleatoriamente sempre com saída
//  mazeComOuSemSaida(); // maze gerado aleatoriamente podendo ter ou não saída

    }

    private void gerarLabirinto() {
        // cria o array bidimensional
        maze = new char[linha][coluna];

        // preenche o labirinto
        preencherLabirinto();

        // determina a entrada e a saída
        determinarEntradaESaida();
        maze[coordenadaLinhaEntrada][coordenadaColunaEntrada] = '.';
        maze[coordenadaLinhaSaida][coordenadaColunaSaida] = '.';
    }

    private void setLinha(int qtdLinha) {
        while (qtdLinha < 5) {
            System.out.print("ERRO: quantidade inválida de linhas. Tente denovo.\n? ");
            qtdLinha = input.nextInt();
        }
        linha = qtdLinha;
    }

    private void setColuna(int qtdColuna) {
        while (qtdColuna < 5) {
            System.out.print("ERRO: quantidade inválida de colunas. Tente denovo.\n? ");
            qtdColuna = input.nextInt();
        }

        coluna = qtdColuna;
    }

    private void preencherLabirinto() {
        int maxLinha = maze.length - 1,
                maxColuna = maze[maxLinha].length - 1;

        // preenche as bordas do labirinto com #
        for (int i = 0; i <= maxColuna; i++) {
            maze[0][i] = '#';
            maze[maxLinha][i] = '#';
        }

        for (int i = 0; i <= maxLinha; i++) {
            maze[i][0] = '#';
            maze[i][maxColuna] = '#';
        }

        // preenche a parte interna do labirinto de modo aleatório
        for (int i = 1; i < maxLinha; i++) {
            for (int j = 1; j < maze[i].length - 1; j++) {
                maze[i][j] = randomizaParedes(randomNumber.nextInt(2));
            }
        }
    } // fim do método preencherLabirinto

    private char randomizaParedes(int number) {
        if (number == 0)
            return '#';
        else
            return '.';
    } // fim do método randomizaParedes

    private void determinarEntradaESaida() {
        // não pode ser diagonais
        int coordEsqDir = 1 + randomNumber.nextInt(maze.length - 3),
                coordCimaBaixo = 1 + randomNumber.nextInt(maze[coordEsqDir].length - 3);

        // determina a linha e coluna maxima do array bidimensional
        int linhaMaxima = maze.length - 1,
                colunaMaxima = maze[linhaMaxima].length - 1;

        // determina as entradas e saídas
        switch (randomNumber.nextInt(4)) {
            // entrada por cima
            case 0:
                coordenadaLinhaEntrada = 0;
                coordenadaColunaEntrada = coordCimaBaixo;

                switch (randomNumber.nextInt(3)) {
                    // saida pela direita
                    case 0:
                        coordenadaLinhaSaida = coordEsqDir;
                        coordenadaColunaSaida = colunaMaxima;
                        break;

                    // saida por baixo
                    case 1:
                        coordenadaLinhaSaida = linhaMaxima;
                        coordenadaColunaSaida = coordCimaBaixo;
                        break;

                    // saida pela esquerda
                    case 2:
                        coordenadaLinhaSaida = coordEsqDir;
                        coordenadaColunaSaida = 0;
                        break;
                }

                break;

            // entrada por baixo
            case 1:
                coordenadaLinhaEntrada = linhaMaxima;
                coordenadaColunaEntrada = coordCimaBaixo;

                switch (randomNumber.nextInt(3)) {
                    // saida pela direita
                    case 0:
                        coordenadaLinhaSaida = coordEsqDir;
                        coordenadaColunaSaida = colunaMaxima;
                        break;

                    // saida por cima
                    case 1:
                        coordenadaLinhaSaida = 0;
                        coordenadaColunaSaida = coordCimaBaixo;
                        break;

                    // saida pela esquerda
                    case 2:
                        coordenadaLinhaSaida = coordEsqDir;
                        coordenadaColunaSaida = 0;
                        break;
                }

                break;

            // entrada pela esquerda
            case 2:
                coordenadaLinhaEntrada = coordEsqDir;
                coordenadaColunaEntrada = 0;

                switch (randomNumber.nextInt(3)) {
                    // saida pela direita
                    case 0:
                        coordenadaLinhaSaida = coordEsqDir;
                        coordenadaColunaSaida = colunaMaxima;
                        break;

                    // saida por cima
                    case 1:
                        coordenadaLinhaSaida = 0;
                        coordenadaColunaSaida = coordCimaBaixo;
                        break;

                    // saida por baixo
                    case 2:
                        coordenadaLinhaSaida = linhaMaxima;
                        coordenadaColunaSaida = coordCimaBaixo;
                        break;
                }

                break;

            // entrada pela direita
            case 3:
                coordenadaLinhaEntrada = coordEsqDir;
                coordenadaColunaEntrada = colunaMaxima;

                switch (randomNumber.nextInt(3)) {
                    // saida pela esquerda
                    case 0:
                        coordenadaLinhaSaida = coordEsqDir;
                        coordenadaColunaSaida = 0;
                        break;

                    // saida por cima
                    case 1:
                        coordenadaLinhaSaida = 0;
                        coordenadaColunaSaida = coordCimaBaixo;
                        break;

                    // saida por baixo
                    case 2:
                        coordenadaLinhaSaida = linhaMaxima;
                        coordenadaColunaSaida = coordCimaBaixo;
                        break;
                }

                break;

        } // fim do switch que determina as entradas

    } // fim do método determinarEntradaESaida

    public void imprimirLabirinto() {
        System.out.println();
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze[i].length; j++) {
                System.out.print(maze[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    } // fim do método imprimirLabirinto

    private void percorrerLabirinto(int linhaAtual, int colunaAtual) {

        if ((linhaAtual == coordenadaLinhaSaida) && (colunaAtual == coordenadaColunaSaida)) {
            mazeStatus = true;
            maze[linhaAtual][colunaAtual] = 'x';
            imprimirLabirinto();
            mazeStatusMessage();
            System.exit(0);
        } else {
            maze[linhaAtual][colunaAtual] = 'x';

            // para cima
            if (linhaAtual - 1 >= 0) // verifica se não estoura o array na parte de cima
            {
                if (maze[linhaAtual - 1][colunaAtual] == '.') // verifica se o passo de cima é '.'
                {
                    percorrerLabirinto(linhaAtual - 1, colunaAtual);
                }
            }

            // para direita
            if (colunaAtual + 1 <= maze[linhaAtual].length - 1) // verifica se não estoura o array a direita
            {
                if (maze[linhaAtual][colunaAtual + 1] == '.') // verifica se o passo a direita é '.'
                {
                    percorrerLabirinto(linhaAtual, colunaAtual + 1);
                }
            }

            // para baixo
            if (linhaAtual + 1 <= maze.length - 1) // verifica se não estoura o array na parte de baixo
            {
                if (maze[linhaAtual + 1][colunaAtual] == '.') // verifica se o passo de baixo é '.'
                {
                    percorrerLabirinto(linhaAtual + 1, colunaAtual);
                }
            }

            // para esquerda
            if (colunaAtual - 1 >= 0) // verifica se não estoura o array a esquerda
            {
                if (maze[linhaAtual][colunaAtual - 1] == '.') // verifica se o passo a esquerda é '.'
                {
                    percorrerLabirinto(linhaAtual, colunaAtual - 1);
                }
            }

            maze[linhaAtual][colunaAtual] = 'o';
        } // fim do if/else externo

    } // fim do método percorrerLabirinto

    public String mazeStatusMessage() {
        if (mazeStatus)
            return String.format("%s\n", "Parabéns, chegastes ao fim do labirinto!");
        else
            return String.format("%s\n", "Este labirinto não possui saída...");
    }


    private void mazeComSaida() {
        while (!mazeStatus) {
            gerarLabirinto();
            percorrerLabirinto(coordenadaLinhaEntrada, coordenadaColunaEntrada);
        }
    }


    private void mazeComOuSemSaida() {
        gerarLabirinto();
        percorrerLabirinto(coordenadaLinhaEntrada, coordenadaColunaEntrada);
    }


    public static void main(String[] args) {
        Labirinto maze = new Labirinto();
        maze.imprimirLabirinto();
        System.out.print(maze.mazeStatusMessage());

    }
}
