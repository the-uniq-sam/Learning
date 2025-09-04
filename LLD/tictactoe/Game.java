import java.util.ArrayList;

import enums.*;
import models.*;
import strategy.*;
import interfaces.*;

public class Game{
    Player player1, player2;
    Board board;
    ArrayList<IGameStrategy> strategies = new ArrayList<IGameStrategy>();
    GameStatus status;

    public Game(Player player1, Player player2, int n){
        this.player1 = player1;
        this.player2 = player2;
        this.board = new Board(n);
        status = GameStatus.CONTINUE;
        strategies.add(new AllRowStrategy());
        strategies.add(new AllColumnStrategy());
        strategies.add(new AllDiagonalStrategy());
    }

    public Game(Player player1, Player player2){
        this(player1, player2, 3);
    }

    public GameStatus getGameStatus(){
        return this.status;
    }

    public void addGameStrategy(IGameStrategy strategy){
        strategies.add(strategy);
    }
}