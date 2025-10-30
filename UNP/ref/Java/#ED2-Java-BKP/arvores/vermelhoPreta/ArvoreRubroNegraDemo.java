package arvores.vermelhoPreta;

import java.util.*;

public class ArvoreRubroNegraDemo {

    // ========= Configuração de cores ANSI =========
    static final String RESET = "\u001B[0m";
    static final String VERMELHO = "\u001B[31m";
    static final String CINZA = "\u001B[90m";

    static String corVermelha(String s) { return VERMELHO + s + RESET; }
    static String corCinza(String s)    { return CINZA + s + RESET; }

    // ===================== Nó da Árvore =====================
    static final boolean VERMELHO_NO = true;
    static final boolean PRETO_NO = false;

    static class No<T extends Comparable<T>> {
        T chave;
        boolean cor = VERMELHO_NO; // novos nós nascem vermelhos
        No<T> esquerdo, direito, pai;
        No(T chave) { this.chave = chave; }
    }

    // ===================== Árvore Rubro-Negra =====================
    static class ArvoreRubroNegra<T extends Comparable<T>> {
        No<T> raiz;

        // Inserção pública
        public void inserir(T chave) {
            No<T> novo = new No<>(chave);
            inserirBST(novo);
            corrigirInsercao(novo);
        }

        // Inserção padrão (como ABB)
        private void inserirBST(No<T> novo) {
            No<T> pai = null;
            No<T> atual = raiz;

            while (atual != null) {
                pai = atual;
                int comp = novo.chave.compareTo(atual.chave);
                if (comp < 0) atual = atual.esquerdo;
                else if (comp > 0) atual = atual.direito;
                else return; // ignora duplicatas
            }

            novo.pai = pai;
            if (pai == null) raiz = novo;
            else if (novo.chave.compareTo(pai.chave) < 0) pai.esquerdo = novo;
            else pai.direito = novo;
        }

        // Rotação à esquerda
        private void rotacaoEsquerda(No<T> x) {
            No<T> y = x.direito;
            x.direito = y.esquerdo;
            if (y.esquerdo != null) y.esquerdo.pai = x;
            y.pai = x.pai;

            if (x.pai == null) raiz = y;
            else if (x == x.pai.esquerdo) x.pai.esquerdo = y;
            else x.pai.direito = y;

            y.esquerdo = x;
            x.pai = y;
        }

        // Rotação à direita
        private void rotacaoDireita(No<T> x) {
            No<T> y = x.esquerdo;
            x.esquerdo = y.direito;
            if (y.direito != null) y.direito.pai = x;
            y.pai = x.pai;

            if (x.pai == null) raiz = y;
            else if (x == x.pai.direito) x.pai.direito = y;
            else x.pai.esquerdo = y;

            y.direito = x;
            x.pai = y;
        }

        // Correção após inserção
        private void corrigirInsercao(No<T> no) {
            while (no.pai != null && no.pai.cor == VERMELHO_NO) {
                No<T> pai = no.pai;
                No<T> avo = pai.pai;

                if (pai == avo.esquerdo) {
                    No<T> tio = avo.direito;
                    // Caso 1: tio vermelho → recolore
                    if (tio != null && tio.cor == VERMELHO_NO) {
                        pai.cor = PRETO_NO;
                        tio.cor = PRETO_NO;
                        avo.cor = VERMELHO_NO;
                        no = avo;
                    } else {
                        // Caso 2: z é filho direito
                        if (no == pai.direito) {
                            no = pai;
                            rotacaoEsquerda(no);
                            pai = no.pai; avo = pai.pai;
                        }
                        // Caso 3: filho esquerdo
                        pai.cor = PRETO_NO;
                        avo.cor = VERMELHO_NO;
                        rotacaoDireita(avo);
                    }
                } else {
                    // Simétrico
                    No<T> tio = avo.esquerdo;
                    if (tio != null && tio.cor == VERMELHO_NO) {
                        pai.cor = PRETO_NO;
                        tio.cor = PRETO_NO;
                        avo.cor = VERMELHO_NO;
                        no = avo;
                    } else {
                        if (no == pai.esquerdo) {
                            no = pai;
                            rotacaoDireita(no);
                            pai = no.pai; avo = pai.pai;
                        }
                        pai.cor = PRETO_NO;
                        avo.cor = VERMELHO_NO;
                        rotacaoEsquerda(avo);
                    }
                }
            }
            raiz.cor = PRETO_NO; // a raiz é sempre preta
        }

        // ===================== Impressão sideways (ajustada) =====================
        public void exibirLateral() {
            System.out.println();
            exibirLateral(raiz, "", true, true); // ehRaiz = true
            System.out.println();
        }

        private void exibirLateral(No<T> no, String prefixo, boolean veioDaDireita, boolean ehRaiz) {
            if (no == null) {
                // imprime null com a barra correspondente
                System.out.println(prefixo + (veioDaDireita ? "/----- " : "\\----- ") + corCinza("<null>"));
                return;
            }

            boolean temEsq = (no.esquerdo != null);
            boolean temDir = (no.direito  != null);

            // 1) imprime primeiro a direita (no topo)
            // se também existe filho esquerdo, mantemos um tronco vertical (" |      ")
            String prefixoDireita = prefixo + (temEsq ? " |      " : "        ");
            exibirLateral(no.direito, prefixoDireita, true, false);

            // 2) imprime o próprio nó (raiz sem barras)
            String rotulo = no.chave + (no.cor == VERMELHO_NO ? corVermelha("(R)") : corCinza("(B)"));
            if (ehRaiz) {
                System.out.println(rotulo);
            } else {
                System.out.println(prefixo + (veioDaDireita ? "/----- " : "\\----- ") + rotulo);
            }

            // 3) imprime a esquerda
            // se também existe filho direito, mantemos tronco vertical
            String prefixoEsquerda = prefixo + (temDir ? " |      " : "        ");
            exibirLateral(no.esquerdo, prefixoEsquerda, false, false);
        }


        // ===================== Exibicao em camadas colorida (sem / e \) =====================
        public void exibirComoArvoreColorida() {
            if (raiz == null) {
                System.out.println(corCinza("(arvore vazia)"));
                return;
            }

            int altura = altura(raiz);
            List<List<No<T>>> porNivel = niveisComNulos(raiz, altura);
            int larguraRotulo = calculaLarguraRotulo(porNivel);

            for (int nivel = 0; nivel < porNivel.size(); nivel++) {
                List<No<T>> linha = porNivel.get(nivel);

                int espacosPre = (int)Math.pow(2, (altura - nivel)) - 1;
                int espacosEntre = (int)Math.pow(2, (altura - nivel + 1)) - 1;

                String lead = repetir(" ", espacosPre * (larguraRotulo + 2));
                String sep  = repetir(" ", espacosEntre * (larguraRotulo + 2));

                StringBuilder sb = new StringBuilder();
                sb.append(lead);

                for (int i = 0; i < linha.size(); i++) {
                    No<T> n = linha.get(i);
                    String rotulo = rotuloColorido(n, larguraRotulo);
                    sb.append(rotulo);
                    if (i < linha.size() - 1) sb.append(sep);
                }

                System.out.println(sb.toString());
            }
        }

        /* --------------------- Helpers --------------------- */

        // Altura (1 para folha)
        private int altura(No<T> n) {
            if (n == null) return 0;
            return 1 + Math.max(altura(n.esquerdo), altura(n.direito));
        }

        // Monta a lista de niveis com placeholders nulos
        private List<List<No<T>>> niveisComNulos(No<T> raiz, int niveis) {
            List<List<No<T>>> result = new ArrayList<>();
            Queue<No<T>> fila = new LinkedList<>();
            fila.add(raiz);
            for (int nivel = 0; nivel < niveis; nivel++) {
                int tam = fila.size();
                List<No<T>> linha = new ArrayList<>(tam);
                for (int i = 0; i < tam; i++) {
                    No<T> atual = fila.poll();
                    linha.add(atual);
                    if (atual != null) {
                        fila.add(atual.esquerdo);
                        fila.add(atual.direito);
                    } else {
                        fila.add(null);
                        fila.add(null);
                    }
                }
                result.add(linha);
            }
            return result;
        }

        // Rotulo colorido (🔴 e ⚫ ou (R)/(B))
        private String rotuloColorido(No<T> n, int larguraRotulo) {
            String rotulo;
            if (n == null) {
                rotulo = corCinza(".");
            } else {
                String valor = String.valueOf(n.chave);
                String cor = n.cor == VERMELHO_NO ? corVermelha("🔴") : corCinza("⚫");
                rotulo = valor + cor;
            }

            // Centraliza
            int faltam = larguraRotulo - rotulo.replaceAll("\u001B\\[[;\\d]*m", "").length();
            if (faltam > 0) {
                int esq = faltam / 2;
                int dir = faltam - esq;
                rotulo = repetir(" ", esq) + rotulo + repetir(" ", dir);
            }

            return " " + rotulo + " ";
        }

        // Calcula a largura do rotulo
        private int calculaLarguraRotulo(List<List<No<T>>> porNivel) {
            int max = 1;
            for (List<No<T>> linha : porNivel) {
                for (No<T> n : linha) {
                    if (n != null) {
                        int len = String.valueOf(n.chave).length() + 2;
                        if (len > max) max = len;
                    }
                }
            }
            return Math.min(max, 6);
        }

      /*  // Repeticao compativel com Java 8
        private String repetir(String s, int vezes) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < vezes; i++) sb.append(s);
            return sb.toString();
        }
*/
        // ===================== Exibicao em camadas ASCII (com cor ANSI opcional) =====================
        public void exibirComoArvoreASCII(boolean colorir) {
            if (raiz == null) {
                System.out.println(colorir ? corCinza("(arvore vazia)") : "(arvore vazia)");
                return;
            }

            int h = altura(raiz);
            List<List<No<T>>> porNivel = niveisComNulos(raiz, h);
            int larguraRotulo = calculaLarguraRotuloASCII(porNivel); // largura para centralizar

            for (int nivel = 0; nivel < porNivel.size(); nivel++) {
                List<No<T>> linha = porNivel.get(nivel);

                int espacosPre   = (int)Math.pow(2, (h - nivel)) - 1;
                int espacosEntre = (int)Math.pow(2, (h - nivel + 1)) - 1;

                String lead = repetir(" ", espacosPre * (larguraRotulo + 2));
                String sep  = repetir(" ", espacosEntre * (larguraRotulo + 2));

                StringBuilder sb = new StringBuilder();
                sb.append(lead);

                for (int i = 0; i < linha.size(); i++) {
                    No<T> n = linha.get(i);
                    String rot = rotuloASCII(n, larguraRotulo, colorir);
                    sb.append(rot);
                    if (i < linha.size() - 1) sb.append(sep);
                }
                System.out.println(sb.toString());
            }
        }
        // Rotulo ASCII seguro: "valor(R)" ou "valor(B)"; pinta apenas o sufixo se colorir=true
        private String rotuloASCII(No<T> n, int larguraRotulo, boolean colorir) {
            String rot;
            if (n == null) {
                rot = colorir ? corCinza(".") : ".";
            } else {
                String sufixo = n.cor == VERMELHO_NO ? "(R)" : "(B)";
                if (colorir) {
                    sufixo = n.cor == VERMELHO_NO ? corVermelha("(R)") : corCinza("(B)");
                }
                rot = String.valueOf(n.chave) + sufixo;
            }

            int visivel = comprimentoSemANSI(rot);
            int faltam = larguraRotulo - visivel;
            if (faltam > 0) {
                int esq = faltam / 2;
                int dir = faltam - esq;
                rot = repetir(" ", esq) + rot + repetir(" ", dir);
            }
            return " " + rot + " ";
        }

        private int calculaLarguraRotuloASCII(List<List<No<T>>> porNivel) {
            int max = 3;
            for (List<No<T>> linha : porNivel) {
                for (No<T> n : linha) {
                    if (n != null) {
                        int len = String.valueOf(n.chave).length() + 3; // + "(R)" ou "(B)"
                        if (len > max) max = len;
                    }
                }
            }
            return Math.min(max, 8);
        }

        // remove escapes ANSI para calcular centralizacao corretamente
        private int comprimentoSemANSI(String s) {
            return s.replaceAll("\u001B\\[[;\\d]*m", "").length();
        }

        // repetir(String,int) voce ja tem; se nao, mantenha este:
        private String repetir(String s, int vezes) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < vezes; i++) sb.append(s);
            return sb.toString();
        }




    }

    // ===================== Programa principal =====================
    public static void main(String[] args) {
        ArvoreRubroNegra<Integer> arvore = new ArvoreRubroNegra<>();

        // sequência de inserção que gera o mesmo formato do seu exemplo
        int[] chaves = {7, 3, 10, 1, 5, 8, 11, 2, 14};
        for (int valor : chaves) arvore.inserir(valor);

        //arvore.exibirLateral();
        //arvore.exibirComoArvoreColorida();
        // arvore.exibirComoArvoreColorida();
        arvore.exibirComoArvoreASCII(true);   // true = com cor ANSI; false = sem cor


        // teste adicional (inserção em tempo real)
        // arvore.inserir(6);
        // arvore.exibirLateral();
    }
}
