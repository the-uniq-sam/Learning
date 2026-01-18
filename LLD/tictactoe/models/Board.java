package models;

public class Board {
    Integer size;
    private final Symbol[][] boardState;
    public Board(Integer size){
        this.size = size;
        this.boardState = new Symbol[size][size];
        // Initialize all cells to Free
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                boardState[i][j] = Symbol.Free;
                System.out.println(boardState[i][j]);
            }
        }
    }

    public void print(){
        for(Integer i = 0; i<size; i++){
            for(Integer j = 0; j<size; j++){
                System.out.print(boardState[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void setValue(Integer row, Integer col, Symbol val){
        boardState[row][col] = val;
        return;
    }

    public Symbol getValue(Integer row, Integer col){
        return boardState[row][col];
    }

    public Integer getSize(){
        return this.size;
    }

}
