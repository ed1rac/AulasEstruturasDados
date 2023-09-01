package recursividade;

import java.util.Arrays;

/** Queen.java
 * basedao no codigo de Timothy Budd
 */

public class Queen {
    // Função para verificar se duas rainhas se ameaçam ou não
    private static boolean isSafe(char[][] mat, int r, int c)
    {
        // retorna false se duas rainhas compartilham a mesma coluna
        for (int i = 0; i < r; i++)
        {
            if (mat[i][c] == 'Q') {
                return false;
            }
        }

        // retorna false se duas rainhas compartilham a mesma `` diagonal
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        {
            if (mat[i][j] == 'Q') {
                return false;
            }
        }

        // retorna false se duas rainhas compartilham a mesma diagonal `/`
        for (int i = r, j = c; i >= 0 && j < mat.length; i--, j++)
        {
            if (mat[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    private static void printSolution(char[][] mat)
    {
        for (char[] chars: mat) {
            System.out.println(Arrays.toString(chars).replaceAll(",", ""));
        }
        System.out.println();
    }

    private static void nQueen(char[][] mat, int r)
    {
        // se `N` rainhas forem colocadas com sucesso, imprime a solução
        if (r == mat.length)
        {
            printSolution(mat);
            return;
        }

        // coloca a rainha em cada casa na linha atual `r`
        // e se repete para cada movimento válido
        for (int i = 0; i < mat.length; i++)
        {
            // se não houver duas rainhas ameaçando uma à outra
            if (isSafe(mat, r, i))
            {
                //coloca a rainha na casa atual
                mat[r][i] = 'Q';

                //recorre para a próxima linha
                nQueen(mat, r + 1);

                // retrocede e remove a rainha da casa atual
                mat[r][i] = '\u2013';
            }
        }
    }

    public static void main(String[] args)
    {
        // tabuleiro de xadrez `N × N`
        int N = 5;

        // `mat[][]` mantém o controle da posição das rainhas em
        // a configuração atual
        char[][] mat = new char[N][N];

        // inicializa `mat[][]` por `-`
        for (int i = 0; i < N; i++) {
            Arrays.fill(mat[i], '\u2013');
        }

        nQueen(mat, 0);
    }
}