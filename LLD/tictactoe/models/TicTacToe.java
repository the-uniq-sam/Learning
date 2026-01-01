package models;
import java.util.Scanner;

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
        System.out.println("Game started between " + player1 + " and " + player2);
    }
}