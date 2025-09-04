package models;
import java.util.ArrayList;
import enums.Symbol;

public class Board{
    public int n;
    ArrayList<ArrayList<Cell>> board;
    
    public Board(int n){
        this.n = n;
        board = new ArrayList<ArrayList<Cell>>();
        for(int i = 0; i<n; i++){
            ArrayList<Cell> row = new ArrayList<Cell>();
            for(int j = 0; j<n; j++){
                row.add(new Cell());
            }
            board.add(row);
        }
    }

    public void printBoard(){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                System.out.print(board.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public Symbol getCell(int i, int j){
        return board.get(i).get(j).getSymbol();
    }

    public Boolean setCell(int i, int j, Symbol symbol){
        return board.get(i).get(j).setSymbol(symbol);
    }
}