package paradigmas.complexidade;

import javax.swing.*;
import java.awt.*;
import java.util.List;
import java.util.*;

public class CaixeiroViajante {

    private static int[][] distancias; // Matriz de distâncias global

    public static void main(String[] args) {
        menu();
    }

    // Método para exibir o menu e iniciar o programa
    public static void menu() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Escolha o método de geração da matriz de distâncias:");
        System.out.println("1. Fixa");
        System.out.println("2. Aleatória");
        System.out.print("Digite o número da opção desejada: ");
        String escolha = scanner.nextLine();

        if (!escolha.equals("1") && !escolha.equals("2")) {
            System.out.println("Opção inválida.");
            return;
        }

        System.out.print("Digite o número de cidades (3, 5, 6, 7, 8, 10): ");
        int numCidades = Integer.parseInt(scanner.nextLine());

        if (escolha.equals("1")) {
            if (Arrays.asList(3, 5, 6, 7, 8, 10).contains(numCidades)) {
                distancias = matrizDistanciasFixa(numCidades);
            } else {
                System.out.println("Número de cidades não suportado para a matriz fixa.");
                return;
            }
        } else if (escolha.equals("2")) {
            distancias = matrizDistanciasAleatoria(numCidades);
        }

        System.out.println();
        imprimirMatriz(distancias);

        // Exibe o grafo da matriz de distâncias
        System.out.println("\nExibindo o grafo da matriz de distâncias:");
        exibirGrafo(distancias, null);

        long tempoInicio = System.currentTimeMillis();
        // Executa o algoritmo do caixeiro viajante
        Map.Entry<String, Integer> resultado = caixeiroViajante();
        String melhorRota = resultado.getKey();
        int menorDistancia = resultado.getValue();
        long tempoTotal = System.currentTimeMillis() - tempoInicio;

        System.out.println();
        imprimirMatriz(distancias);
        System.out.println();
        System.out.println("\nMelhor rota final: " + exibirMelhorRota(melhorRota));
        System.out.println("Menor distância final: " + menorDistancia);
        System.out.printf("Tempo total de execução: %.2f segundos.\n", tempoTotal / 1000.0);

        // Exibe o grafo destacando a melhor rota
        System.out.println("\nExibindo o grafo com a melhor rota:");
        exibirGrafo(distancias, melhorRota);
    }

    // Função para gerar uma matriz de distâncias fixa
    public static int[][] matrizDistanciasFixa(int numCidades) {
        int base = 10; // Base inicial para os cálculos de distância
        int[][] matriz = new int[numCidades][numCidades]; // Inicializa matriz vazia

        for (int i = 0; i < numCidades; i++) {
            for (int j = i + 1; j < numCidades; j++) {
                // Cálculo da distância: soma dos índices + 1, multiplicada por 5
                int distancia = (i + j + 1) * 5;
                matriz[i][j] = distancia;
                matriz[j][i] = distancia;
            }
        }

        return matriz;
    }

    // Função para gerar uma matriz de distâncias com valores aleatórios
    public static int[][] matrizDistanciasAleatoria(int numCidades) {
        int[][] matriz = new int[numCidades][numCidades];
        Random random = new Random();

        for (int i = 0; i < numCidades; i++) {
            for (int j = i + 1; j < numCidades; j++) {
                int distancia = random.nextInt(100) + 1;
                matriz[i][j] = distancia;
                matriz[j][i] = distancia;
            }
        }

        return matriz;
    }

    // Função para imprimir a matriz de distâncias
    public static void imprimirMatriz(int[][] distancias) {
        int numCidades = distancias.length;

        System.out.println("Matriz de distâncias para " + numCidades + " cidades:");

        // Encontrar o comprimento máximo dos valores para formatação
        int maxTamanho = 0;
        for (int[] linha : distancias) {
            for (int valor : linha) {
                int tamanho = String.valueOf(valor).length();
                if (tamanho > maxTamanho) {
                    maxTamanho = tamanho;
                }
            }
        }

        // Criar o cabeçalho horizontal
        StringBuilder cabecalhoHorizontal = new StringBuilder(" ".repeat(maxTamanho + 1));
        for (int i = 0; i < numCidades; i++) {
            cabecalhoHorizontal.append(String.format("%-" + maxTamanho + "s ", (char) (65 + i)));
        }
        System.out.println(cabecalhoHorizontal);

        // Criar o cabeçalho vertical e imprimir a matriz
        for (int i = 0; i < numCidades; i++) {
            StringBuilder linha = new StringBuilder(String.format("%-" + maxTamanho + "s ", (char) (65 + i)));
            for (int j = 0; j < numCidades; j++) {
                linha.append(String.format("%-" + maxTamanho + "d ", distancias[i][j]));
            }
            System.out.println(linha);
        }
    }

    // Função que calcula a distância total de uma rota específica
    public static int calcularDistancia(int[] rota) {
        int distanciaTotal = 0;
        for (int i = 0; i < rota.length - 1; i++) {
            distanciaTotal += distancias[rota[i]][rota[i + 1]];
        }
        distanciaTotal += distancias[rota[rota.length - 1]][rota[0]]; // Volta à cidade de origem
        return distanciaTotal;
    }

    // Função que converte rota de números para letras e formata com vírgulas
    public static String converterRotaParaLetras(int[] rota) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < rota.length; i++) {
            sb.append((char) (65 + rota[i]));
            if (i < rota.length - 1) {
                sb.append(", ");
            }
        }
        return sb.toString();
    }

    // Exibir a melhor rota de forma mais amigável
    public static String exibirMelhorRota(String melhorRota) {
        return melhorRota.replace(", ", " -> ");
    }

    // Simulação do problema do caixeiro viajante usando força bruta
    public static Map.Entry<String, Integer> caixeiroViajante() {
        int numCidades = distancias.length;
        int[] cidades = new int[numCidades];
        for (int i = 0; i < numCidades; i++) {
            cidades[i] = i;
        }

        int menorDistancia = Integer.MAX_VALUE;
        String melhorRota = null;

        // Permutação de todas as possíveis rotas
        List<int[]> permutacoes = permutacoes(cidades);

        for (int[] rota : permutacoes) {
            int distancia = calcularDistancia(rota);
            String rotaLetras = converterRotaParaLetras(rota);
            // Exibe a rota atual e sua distância
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                melhorRota = rotaLetras;
                System.out.printf("Rota: %s | Distância: %d <- Menor até agora\n", rotaLetras, distancia);
            } else {
                System.out.printf("Rota: %s | Distância: %d\n", rotaLetras, distancia);
            }
        }

        return new AbstractMap.SimpleEntry<>(melhorRota, menorDistancia);
    }

    // Função para gerar todas as permutações de um array
    public static List<int[]> permutacoes(int[] array) {
        List<int[]> resultado = new ArrayList<>();
        permutacaoHelper(array, 0, resultado);
        return resultado;
    }

    private static void permutacaoHelper(int[] array, int pos, List<int[]> resultado) {
        if (pos == array.length) {
            resultado.add(array.clone());
        } else {
            for (int i = pos; i < array.length; i++) {
                trocar(array, pos, i);
                permutacaoHelper(array, pos + 1, resultado);
                trocar(array, pos, i);
            }
        }
    }

    private static void trocar(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Função para exibir o grafo
    public static void exibirGrafo(int[][] distancias, String melhorRota) {
        JFrame frame = new JFrame("Grafo do Caixeiro Viajante");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 600);

        GraficoPanel graficoPanel = new GraficoPanel(distancias, melhorRota);
        frame.add(graficoPanel);
        frame.setVisible(true);
    }

    // Classe interna para desenhar o grafo
    static class GraficoPanel extends JPanel {
        int[][] distancias;
        String melhorRota;
        Map<String, Point> posicoes;
        int raio = 250;

        public GraficoPanel(int[][] distancias, String melhorRota) {
            this.distancias = distancias;
            this.melhorRota = melhorRota;
            this.posicoes = new HashMap<>();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            desenharGrafo(g);
        }

        private void desenharGrafo(Graphics g) {
            Graphics2D g2d = (Graphics2D) g;
            int numCidades = distancias.length;

            // Calcula a posição dos nós
            int centroX = getWidth() / 2;
            int centroY = getHeight() / 2;
            double angulo = 2 * Math.PI / numCidades;

            for (int i = 0; i < numCidades; i++) {
                int x = (int) (centroX + raio * Math.cos(i * angulo));
                int y = (int) (centroY + raio * Math.sin(i * angulo));
                String label = String.valueOf((char) (65 + i));
                posicoes.put(label, new Point(x, y));
            }

            // Desenhar as arestas
            for (int i = 0; i < numCidades; i++) {
                for (int j = i + 1; j < numCidades; j++) {
                    String cidadeA = String.valueOf((char) (65 + i));
                    String cidadeB = String.valueOf((char) (65 + j));
                    Point pontoA = posicoes.get(cidadeA);
                    Point pontoB = posicoes.get(cidadeB);

                    // Desenha a linha
                    g2d.setColor(Color.GRAY);
                    g2d.drawLine(pontoA.x, pontoA.y, pontoB.x, pontoB.y);

                    // Desenha o peso (distância)
                    String peso = String.valueOf(distancias[i][j]);
                    int xPeso = (pontoA.x + pontoB.x) / 2;
                    int yPeso = (pontoA.y + pontoB.y) / 2;
                    g2d.setColor(Color.BLACK);
                    g2d.drawString(peso, xPeso, yPeso);
                }
            }

            // Desenhar os nós
            for (Map.Entry<String, Point> entry : posicoes.entrySet()) {
                String cidade = entry.getKey();
                Point ponto = entry.getValue();
                int tamanho = 30;

                // Desenha o círculo
                g2d.setColor(Color.CYAN);
                g2d.fillOval(ponto.x - tamanho / 2, ponto.y - tamanho / 2, tamanho, tamanho);
                g2d.setColor(Color.BLACK);
                g2d.drawOval(ponto.x - tamanho / 2, ponto.y - tamanho / 2, tamanho, tamanho);

                // Desenha o rótulo
                g2d.drawString(cidade, ponto.x - 5, ponto.y + 5);
            }

            // Se houver uma melhor rota, destacar no grafo
            if (melhorRota != null) {
                String[] cidades = melhorRota.split(", ");
                g2d.setColor(Color.RED);
                g2d.setStroke(new BasicStroke(2));

                for (int i = 0; i < cidades.length; i++) {
                    String cidadeA = cidades[i];
                    String cidadeB = cidades[(i + 1) % cidades.length];
                    Point pontoA = posicoes.get(cidadeA);
                    Point pontoB = posicoes.get(cidadeB);

                    g2d.drawLine(pontoA.x, pontoA.y, pontoB.x, pontoB.y);
                }
            }
        }
    }
}
