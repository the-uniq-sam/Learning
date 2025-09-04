package strategy;
import enums.Symbol;
import interfaces.IGameStrategy;
import models.Board;

public class AllDiagonalStrategy implements IGameStrategy{
    @Override
    public Boolean checkGame(Board board){
        for(Symbol symbol : Symbol.values()){
            if(symbol == Symbol.None){
                continue;
            }
            Boolean flag = true;
            for(int i = 0; i<board.n; i++){
                if(board.getCell(i, i) != symbol){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }

            flag = true;
            for(int i = 0; i<board.n; i++){
                if(board.getCell(i, board.n-1-i) != symbol){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }

}