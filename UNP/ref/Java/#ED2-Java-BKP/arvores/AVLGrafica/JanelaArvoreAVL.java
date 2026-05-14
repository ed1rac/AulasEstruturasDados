package arvores.AVLGrafica;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaArvoreAVL extends JFrame {
    private arvores.AVLGrafica.ArvoreAVL arvoreAVL;
    private arvores.AVLGrafica.DesenhoArvoreAVL painelDesenho;

    public JanelaArvoreAVL() {
        arvoreAVL = new arvores.AVLGrafica.ArvoreAVL();
        painelDesenho = new arvores.AVLGrafica.DesenhoArvoreAVL(arvoreAVL);

        setTitle("�rvore AVL Visual");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);
        setLocationRelativeTo(null);

        JPanel painelControle = new JPanel();
        JTextField campoInserir = new JTextField(10);
        JButton botaoInserir = new JButton("Inserir");
        JButton botaoZerar = new JButton("Zerar �rvore");  // Bot�o para zerar a �rvore

        // A��o do bot�o Inserir
        botaoInserir.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int chave = Integer.parseInt(campoInserir.getText());
                    arvoreAVL.inserir(chave);
                    painelDesenho.repaint();
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Por favor, insira um n�mero v�lido!");
                }
            }
        });

        // A��o do bot�o Zerar
        botaoZerar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arvoreAVL = new arvores.AVLGrafica.ArvoreAVL();  // Reinicializa a �rvore AVL
                painelDesenho.setArvore(arvoreAVL);  // Atualiza o painel com a nova �rvore
                painelDesenho.repaint();  // Re-renderiza a �rvore (que agora est� vazia)
            }
        });

        painelControle.add(new JLabel("Inserir N�:"));
        painelControle.add(campoInserir);
        painelControle.add(botaoInserir);
        painelControle.add(botaoZerar);  // Adiciona o bot�o Zerar ao painel de controle

        getContentPane().add(painelControle, BorderLayout.NORTH);
        getContentPane().add(painelDesenho, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            arvores.AVLGrafica.JanelaArvoreAVL janela = new arvores.AVLGrafica.JanelaArvoreAVL();
            janela.setVisible(true);
        });
    }
}
