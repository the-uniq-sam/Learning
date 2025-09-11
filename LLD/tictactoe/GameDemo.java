import java.util.Scanner;

import enums.Symbol;
import enums.GameStatus;
import models.Player;

public class GameDemo {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        // MULTIPLE PLAYERS CAN BE THERE
        System.out.println("Enter Player 1 Name");
        String name1 = scanner.nextLine();

        System.out.println("Enter Player 2 Name");
        String name2 = scanner.nextLine();

        Player player1 = new Player(name1, Symbol.X);
        Player player2 = new Player(name2, Symbol.O);

        System.out.println("Input Board Size");
        int n = scanner.nextInt();

        Game game = new Game(player1, player2, n);

        while(game.getGameStatus() == GameStatus.CONTINUE){
            System.out.println("Input Cell Coordinates");
            int i = scanner.nextInt();
            int j = scanner.nextInt();
            if(game.makeMove(i, j)){
                game.board.printBoard();
            }
        }
        if(GameStatus.DRAW == game.getGameStatus()){
            System.out.println("DRAW");
        }else{
            System.out.println(game.getCurrPlayer().getName() + " WINS");
        }
        
        scanner.close();
    }
}