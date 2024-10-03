package arvores.AVLGrafica;

import javax.swing.*;
import java.awt.*;

class DesenhoArvoreAVL extends JPanel {
    private ArvoreAVL arvore;

    public DesenhoArvoreAVL(ArvoreAVL arvore) {
        this.arvore = arvore;
    }

    public void setArvore(ArvoreAVL arvore) {
        this.arvore = arvore;  // Atualiza a árvore exibida
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        desenharArvore(g, arvore.getRaiz(), getWidth() / 2, 30, getWidth() / 4, 50);
    }

    private void desenharArvore(Graphics g, No no, int x, int y, int deslocamentoX, int deslocamentoY) {
        if (no == null) return;

        g.setColor(Color.BLACK);
        g.fillOval(x - 15, y - 15, 30, 30);
        g.setColor(Color.WHITE);
        g.drawString(String.valueOf(no.chave), x - 7, y + 5);

        if (no.filhoEsquerda != null) {
            g.setColor(Color.BLACK);
            g.drawLine(x - 10, y + 10, x - deslocamentoX + 10, y + deslocamentoY - 10);
            desenharArvore(g, no.filhoEsquerda, x - deslocamentoX, y + deslocamentoY, deslocamentoX / 2, deslocamentoY);
        }

        if (no.filhoDireita != null) {
            g.setColor(Color.BLACK);
            g.drawLine(x + 10, y + 10, x + deslocamentoX - 10, y + deslocamentoY - 10);
            desenharArvore(g, no.filhoDireita, x + deslocamentoX, y + deslocamentoY, deslocamentoX / 2, deslocamentoY);
        }
    }
}
