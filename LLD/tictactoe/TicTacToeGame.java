import java.util.Scanner;
import game.TicTacToe;

public class TicTacToeGame {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Player1 name");
        String player1 = scanner.nextLine();
        System.out.println("Enter Player2 name");
        String player2 = scanner.nextLine();

        TicTacToe ticTacToe = new TicTacToe(player1, player2, scanner);
        ticTacToe.playGame();

        scanner.close();
    }
}
