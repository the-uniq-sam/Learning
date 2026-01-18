package strategy;

import models.Board;
import models.GameState;
import models.Symbol;

public interface Rules {
    GameState getGameState(Board board);
    static Boolean isValidMove(Integer x, Integer y, Integer boardSize, Board board){
        return x >= 0 && y >= 0 && x < boardSize && y < boardSize && board.getValue(x, y).equals(Symbol.Free);
    }
}
