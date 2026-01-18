package game;
import java.util.List;
import java.util.Scanner;

import models.*;
import strategy.*;
import models.GameState;

public class TicTacToe{
    String player1;
    String player2;
    Scanner scanner;

    public TicTacToe(String player1, String player2, Scanner scanner){
        this.player1 = player1;
        this.player2 = player2;
        this.scanner = scanner;
    }

    public void playGame(){
        System.out.println("Game started between " + player1 + " with symbol X and " + player2 + "with symbol O");
        System.out.println("Enter Board Size");
        Integer boardSize = scanner.nextInt();

        Board board = new Board(boardSize);
        
        Integer numOfMoves = boardSize*boardSize;
        Boolean Player1Chance = true;
        Boolean GameEnd = false;

        for(int i = 0; i<numOfMoves; i++){
            if(GameEnd)
                break;
            System.out.println("Input x and y axis for Player" + (Player1Chance ? player1 : player2));
            Integer x = scanner.nextInt();
            scanner.nextLine();
            Integer y = scanner.nextInt();
            if(Rules.isValidMove(x, y, boardSize, board)){
                board.setValue(x, y, (Player1Chance ? Symbol.X : Symbol.O));
                board.print();
                List<Rules> rules = List.of(
                    new HorizontalRule(),
                    new VerticalRule(),
                    new DiagonalRule()
                );
                for (Rules rule : rules) {
                    GameState state = rule.getGameState(board);
                    if(state.equals(GameState.In_Progress) != true){
                        System.out.println(state + " by Player" + (Player1Chance ? "1" : "2"));
                        GameEnd = true;
                        break;
                    }
                }
                Player1Chance = !Player1Chance;

            }else{
                System.out.println("Enter move is invalid");
            }
        }
        
    }
}