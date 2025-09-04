import java.util.Scanner;

import enums.Symbol;
import models.Board;
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

        Board board = new Board(n);

        
        scanner.close();
    }
}