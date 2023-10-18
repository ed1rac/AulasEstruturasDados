package paradigmas;

class Sudoku {

    public static boolean isSafe(int[][] board, int row, int col, int num) {
        // Linha tem números únicos (colisão da linha)
        for (int d = 0; d < board.length; d++) {
            // Verifica se o número que estamos tentando
            // o local já está presente
            // nessa linha, return false;
            if (board[row][d] == num) {
                return false;
            }
        }

        // A coluna contém os números únicos (colisão da coluna)
        for (int r = 0; r < board.length; r++) {
            // Verifica se o número que estamos tentando
            // o local já está presente
            // nessa linha, return false;
            if (board[r][col] == num) {
                return false;
            }
        }

        // O quadrado correspondente tem
        // número único (colisão/confronto)
        int sqrt = (int) Math.sqrt(board.length);
        int boxRowStart = row - row % sqrt;
        int boxColStart = col - col % sqrt;

        for (int r = boxRowStart; r < boxRowStart + sqrt; r++) {
            for (int d = boxColStart; d < boxColStart + sqrt; d++) {
                if (board[r][d] == num) {
                    return false;
                }
            }
        }

        // se não há colisão/confronto então, tranquilo
        return true;
    }

    public static boolean solveSudoku(int[][] board, int n) {
        int row = -1;
        int col = -1;
        boolean isEmpty = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;

                    // Ainda temos alguns restantes
                    //valores ausentes no Sudoku
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }

        //Não resta espaço vazio
        if (isEmpty) {
            return true;
        }

        // Else para retrocesso/backtracking de cada linha
        for (int num = 1; num <= n; num++) {
            if (isSafe(board, row, col, num)) {
                board[row][col] = num;
                if (solveSudoku(board, n)) {
                    // print(board, n);
                    return true;
                } else {
                    // replace it
                    board[row][col] = 0;
                }
            }
        }
        return false;
    }

    public static void print(int[][] board, int N) {
        // Temos a resposta, basta imprimi-la
        for (int r = 0; r < N; r++) {
            for (int d = 0; d < N; d++) {
                System.out.print(board[r][d]);
                System.out.print(" ");
            }
            System.out.print("\n");

            if ((r + 1) % (int) Math.sqrt(N) == 0) {
                System.out.print("");
            }
        }
    }

    // Código principal
    public static void main(String[] args) {
        /*int[][] board = new int[][] {
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0},
        };*/
        int[][] board = new int[][] {
                {0, 0, 0, 7, 6, 8, 0, 0, 0},
                {6, 0, 5, 3, 0, 0, 7, 0, 2},
                {0, 9, 0, 1, 0, 0, 0, 3, 0},
                {0, 0, 0, 0, 0, 0, 3, 0, 4},
                {0, 6, 0, 0, 0, 0, 0, 5, 0},
                {2, 0, 9, 0, 0, 0, 0, 0, 0},
                {0, 2, 0, 0, 0, 1, 0, 7, 0},
                {8, 0, 1, 0, 0, 3, 4, 0, 6},
                {0, 0, 0, 4, 5, 9, 0, 0, 0},
        };
        int N = board.length;

        if (solveSudoku(board, N)) {
            // print solution
            print(board, N);
        } else {
            System.out.println("Sem solução!");
        }
    }
}
