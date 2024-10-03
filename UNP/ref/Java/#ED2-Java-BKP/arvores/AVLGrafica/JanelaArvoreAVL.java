package arvores.AVLGrafica;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaArvoreAVL extends JFrame {
    private ArvoreAVL arvoreAVL;
    private DesenhoArvoreAVL painelDesenho;

    public JanelaArvoreAVL() {
        arvoreAVL = new ArvoreAVL();
        painelDesenho = new DesenhoArvoreAVL(arvoreAVL);

        setTitle("Árvore AVL Visual");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);
        setLocationRelativeTo(null);

        JPanel painelControle = new JPanel();
        JTextField campoInserir = new JTextField(10);
        JButton botaoInserir = new JButton("Inserir");
        JButton botaoZerar = new JButton("Zerar Árvore");  // Botão para zerar a árvore

        // Ação do botão Inserir
        botaoInserir.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int chave = Integer.parseInt(campoInserir.getText());
                    arvoreAVL.inserir(chave);
                    painelDesenho.repaint();
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Por favor, insira um número válido!");
                }
            }
        });

        // Ação do botão Zerar
        botaoZerar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arvoreAVL = new ArvoreAVL();  // Reinicializa a árvore AVL
                painelDesenho.setArvore(arvoreAVL);  // Atualiza o painel com a nova árvore
                painelDesenho.repaint();  // Re-renderiza a árvore (que agora está vazia)
            }
        });

        painelControle.add(new JLabel("Inserir Nó:"));
        painelControle.add(campoInserir);
        painelControle.add(botaoInserir);
        painelControle.add(botaoZerar);  // Adiciona o botão Zerar ao painel de controle

        getContentPane().add(painelControle, BorderLayout.NORTH);
        getContentPane().add(painelDesenho, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JanelaArvoreAVL janela = new JanelaArvoreAVL();
            janela.setVisible(true);
        });
    }
}
