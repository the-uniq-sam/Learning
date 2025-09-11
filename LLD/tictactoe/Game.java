import java.util.ArrayList;

import enums.*;
import models.*;
import strategy.*;
import interfaces.*;

public class Game{
    Player player1, player2;
    Player currentPlayer;
    Board board;
    ArrayList<IGameStrategy> strategies = new ArrayList<IGameStrategy>();
    GameStatus status;

    public Game(Player player1, Player player2, int n){
        this.player1 = player1;
        this.player2 = player2;
        currentPlayer = player1;
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

    public Boolean makeMove(int i, int j){
        if(board.getCell(i, j) != Symbol.None){
            //make exception here
            System.out.println("Cell is not empty");
            return false;
        }

        board.setCell(i, j, currentPlayer.getSymbol());
        for(IGameStrategy strategy : strategies){
            if(strategy.checkGame(board)){
                status = GameStatus.WIN;
                return true;
            }
        }
        switchPlayer();
        return true;
    }

    public Player getCurrPlayer(){
        return this.currentPlayer;
    }

    public void switchPlayer(){
        if(currentPlayer == player1){
            currentPlayer = player2;
        }else{
            currentPlayer = player1;
        }
        return;
    }

}