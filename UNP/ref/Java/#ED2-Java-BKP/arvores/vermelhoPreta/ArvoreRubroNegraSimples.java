package arvores.vermelhoPreta;

import java.util.*;

public class ArvoreRubroNegraSimples {

    static final String RESET   = "\u001B[0m";
    static final String RED     = "\u001B[31m";
    static final String GRAY    = "\u001B[90m";
    static String corVermelha(String s) { return RED  + s + RESET; }
    static String corCinza(String s)    { return GRAY + s + RESET; }

    // ===== Node (somente int) =====
    static final boolean VERMELHO = true;
    static final boolean PRETO    = false;

    static class No {
        int chave;
        boolean cor = VERMELHO; // novo no nasce vermelho
        No esq, dir, pai;
        No(int c) { chave = c; }
    }

    // ===== Arvore =====
    No raiz;

    public void inserir(int x) {
        No z = new No(x);
        bstInsert(z);
        fixInsercao(z);
    }

    private void bstInsert(No z) {
        No y = null, x = raiz;
        while (x != null) {
            y = x;
            if (z.chave < x.chave) x = x.esq;
            else if (z.chave > x.chave) x = x.dir;
            else return; // ignora duplicata
        }
        z.pai = y;
        if (y == null) raiz = z;
        else if (z.chave < y.chave) y.esq = z;
        else y.dir = z;
    }

    private void rotacaoEsq(No x) {
        No y = x.dir;
        x.dir = y.esq;
        if (y.esq != null) y.esq.pai = x;
        y.pai = x.pai;
        if (x.pai == null) raiz = y;
        else if (x == x.pai.esq) x.pai.esq = y;
        else x.pai.dir = y;
        y.esq = x;
        x.pai = y;
    }

    private void rotacaoDir(No x) {
        No y = x.esq;
        x.esq = y.dir;
        if (y.dir != null) y.dir.pai = x;
        y.pai = x.pai;
        if (x.pai == null) raiz = y;
        else if (x == x.pai.dir) x.pai.dir = y;
        else x.pai.esq = y;
        y.dir = x;
        x.pai = y;
    }

    private void fixInsercao(No z) {
        while (z.pai != null && z.pai.cor == VERMELHO) {
            No p = z.pai;
            No g = p.pai;
            if (p == g.esq) {
                No tio = g.dir;
                if (tio != null && tio.cor == VERMELHO) {
                    p.cor = PRETO; tio.cor = PRETO; g.cor = VERMELHO; z = g;
                } else {
                    if (z == p.dir) { z = p; rotacaoEsq(z); p = z.pai; g = p.pai; }
                    p.cor = PRETO; g.cor = VERMELHO; rotacaoDir(g);
                }
            } else { // simetrico
                No tio = g.esq;
                if (tio != null && tio.cor == VERMELHO) {
                    p.cor = PRETO; tio.cor = PRETO; g.cor = VERMELHO; z = g;
                } else {
                    if (z == p.esq) { z = p; rotacaoDir(z); p = z.pai; g = p.pai; }
                    p.cor = PRETO; g.cor = VERMELHO; rotacaoEsq(g);
                }
            }
        }
        raiz.cor = PRETO;
    }


    public void exibirComoArvoreASCII(boolean colorir) {
        if (raiz == null) {
            System.out.println(colorir ? corCinza("(arvore vazia)") : "(arvore vazia)");
            return;
        }
        int h = altura(raiz);
        List<List<No>> niveis = niveisComNulos(raiz, h);
        int larg = larguraRotuloASCII(niveis);

        for (int niv = 0; niv < niveis.size(); niv++) {
            List<No> linha = niveis.get(niv);
            int pre   = (int)Math.pow(2, (h - niv)) - 1;
            int entre = (int)Math.pow(2, (h - niv + 1)) - 1;

            String lead = repetir(" ", pre * (larg + 2));
            String sep  = repetir(" ", entre * (larg + 2));

            StringBuilder sb = new StringBuilder();
            sb.append(lead);
            for (int i = 0; i < linha.size(); i++) {
                sb.append(rotuloASCII(linha.get(i), larg, colorir));
                if (i < linha.size() - 1) sb.append(sep);
            }
            System.out.println(sb.toString());
        }
    }


    private int altura(No n) {
        if (n == null) return 0;
        return 1 + Math.max(altura(n.esq), altura(n.dir));
    }

    private List<List<No>> niveisComNulos(No r, int h) {
        List<List<No>> res = new ArrayList<>();
        Queue<No> q = new LinkedList<>();
        q.add(r);
        for (int niv = 0; niv < h; niv++) {
            int t = q.size();
            List<No> linha = new ArrayList<>(t);
            for (int i = 0; i < t; i++) {
                No a = q.poll();
                linha.add(a);
                if (a != null) { q.add(a.esq); q.add(a.dir); }
                else { q.add(null); q.add(null); }
            }
            res.add(linha);
        }
        return res;
    }

    private String rotuloASCII(No n, int larg, boolean colorir) {
        String rot;
        if (n == null) rot = colorir ? corCinza(".") : ".";
        else {
            String suf = n.cor == VERMELHO ? "(R)" : "(B)";
            if (colorir) suf = n.cor == VERMELHO ? corVermelha("(R)") : corCinza("(B)");
            rot = n.chave + suf;
        }
        int vis = semANSI(rot).length();
        int faltam = larg - vis;
        if (faltam > 0) rot = repetir(" ", faltam/2) + rot + repetir(" ", faltam - faltam/2);
        return " " + rot + " ";
    }

    private int larguraRotuloASCII(List<List<No>> niveis) {
        int m = 3;
        for (List<No> lin : niveis)
            for (No n : lin)
                if (n != null) m = Math.max(m, String.valueOf(n.chave).length() + 3); // + "(R)" ou "(B)"
        return Math.min(m, 8);
    }

    private String semANSI(String s) { return s.replaceAll("\u001B\\[[;\\d]*m", ""); }

    private String repetir(String s, int v) {
        StringBuilder sb = new StringBuilder(Math.max(0, v) * s.length());
        for (int i = 0; i < v; i++) sb.append(s);
        return sb.toString();
    }


    public static void main(String[] args) {
        ArvoreRubroNegraSimples t = new ArvoreRubroNegraSimples();
        int[] vals = {7, 3, 10, 1, 5, 8, 11, 2, 14};
        for (int v : vals) t.inserir(v);

        // exibicao segura para aula (ASCII). true = com cor ANSI
        t.exibirComoArvoreASCII(true);
    }
}
