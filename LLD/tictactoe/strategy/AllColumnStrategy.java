package strategy;
import enums.Symbol;
import interfaces.IGameStrategy;
import models.Board;

public class AllColumnStrategy implements IGameStrategy{
    @Override
    public Boolean checkGame(Board board){
        for(Symbol symbol : Symbol.values()){
            if(symbol == Symbol.None){
                continue;
            }
            for(int i = 0; i<board.n; i++){
                Boolean flag = true;
                for(int j = 0; j<board.n; j++){
                    if(board.getCell(j, i) != symbol){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }

}