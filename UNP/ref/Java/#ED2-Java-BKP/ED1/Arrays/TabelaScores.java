package ED1.Arrays;

public class TabelaScores {


    private int numEntries = 0;

    private EntradaJogo[] board; //array of game entries(names & scores)

    public TabelaScores(int capacity){
        this.board = new EntradaJogo[capacity];
    }

    public void add(EntradaJogo e){
        int newScore = e.getScore();

        if(numEntries < board.length || newScore > board[numEntries-1].getScore()){
            if(numEntries < board.length)  // no score drops from the board
                numEntries++; //so overall number increases
        }

        int j = numEntries - 1;
        while(j > 0 && board[j-1].getScore() < newScore){
            board[j] = board[j-1]; //shift entry from j-1 to j
            j -- ;    //decrement
        }

        board[j] = e; //when done add new entry
    }

    public EntradaJogo remove(int i) throws IndexOutOfBoundsException{
        if (i < 0 || i >= numEntries){ // If index is less than 0 or index is greater than or equal than numEntries
            throw new IndexOutOfBoundsException("invalid index:" + i); // throw index out of bound exception

        }
        EntradaJogo temp = board[i];  // create temp variable to return

        for(int j = i; j < numEntries - 1; j++){ //for-loop through
            board[j] = board[j+1];
            board[numEntries - 1 ] = null;
            numEntries--;

        }
        return temp;
    }

    public String toString(){
        StringBuilder s = new StringBuilder("[");
        for (int i = 0; i < numEntries; i++) {
            if(i>0) s.append(", \n");
            s.append(board[i]);
        }
        return s + "]";
    }


}
