package strategy;

import models.Board;
import models.GameState;
import models.Symbol;

public class DiagonalRule implements Rules {

    @Override
    public GameState getGameState(Board board) {
        for(int i = 0; i<2; i++){
            Integer valCount = 0;
            Symbol symbol = Symbol.Free;
            for(int j = 0; j<board.getSize(); j++){
                Symbol val = board.getValue(j, (i==1 ? board.getSize()-1-j : j));
                if(val == Symbol.Free)
                    break;
                if(val == symbol)
                    valCount++;
                else{
                    symbol = val;
                    valCount = 1;
                }
            }

            if(valCount == board.getSize())
                return GameState.Win;
        }
        return GameState.In_Progress;
    }
    
}
