import java.util.Scanner;
import models.TicTacToe;

public class TicTacToeGame {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String player1 = scanner.nextLine();
        String player2 = scanner.nextLine();

        TicTacToe ticTacToe = new TicTacToe(player1, player2, scanner);
        ticTacToe.playGame();

        scanner.close();
    }
}
