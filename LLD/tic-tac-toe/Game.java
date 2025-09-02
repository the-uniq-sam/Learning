import java.util.Scanner;
import java.util.ArrayList;

enum Symbol{
    X, O, None;
}

enum Result{
    WIN, DRAW, CONTINUE;
}

final class Player{
    String name;

    public Player(String name){
        this.name = name;
    }
}

final class Board{
    int n;
    ArrayList<ArrayList<Symbol>> board;
    
    public Board(int n){
        this.n = n;
        board = new ArrayList<ArrayList<Symbol>>();
        for(int i = 0; i<n; i++){
            ArrayList<Symbol> row = new ArrayList<Symbol>();
            for(int j = 0; j<n; j++){
                row.add(Symbol.None);
            }
            board.add(row);
        }
    }

    public void printBoard(){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                System.out.print(board.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}


//To-Do - Somehow follow Strategy pattern to apply multiple rules in this
final class Strategy{

    public Strategy(){}
    
    Result strategy(Board board){
        board.printBoard();
        for(int i = 0; i<board.n; i++){
            int count = 0;
            for(Symbol symbol : Symbol.values()){
                if(symbol == Symbol.None)
                    continue;
                count = 0;
                for(int j = 0; j<board.n; j++){
                    if(board.board.get(i).get(j) == symbol){
                        count++;
                        if(count == board.n){
                            return Result.WIN;
                        }
                    }
                }
                count = 0;
                for(int j = 0; j<board.n; j++){
                    if(board.board.get(j).get(i) == symbol){
                        count++;
                        if(count == board.n){
                            return Result.WIN;
                        }
                    }
                }
            }
        }

        
        for(Symbol symbol : Symbol.values()){
            if(symbol == Symbol.None)
                continue;
            int count = 0;
            for(int i = 0; i<board.n; i++){
                if(board.board.get(i).get(i) == symbol){
                    count++;
                    if(count == board.n)
                        return Result.WIN;
                }
            }
            count = 0;
            for(int i = 0; i<board.n; i++){
                if(board.board.get(i).get(board.n - i - 1) == symbol){
                    count++;
                    if(count == board.n)
                        return Result.WIN;
                }
            }
        }
        

        for(int i = 0; i<board.n; i++){
            for(int j = 0; j<board.n; j++){
                if(board.board.get(i).get(j) == Symbol.None){
                    return Result.CONTINUE;
                }
            }
        }


        return Result.DRAW;
    }
}

public class Game{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        // MULTIPLE PLAYERS CAN BE THERE
        System.out.println("Enter Player 1 Name");
        String name1 = scanner.nextLine();

        System.out.println("Enter Player 2 Name");
        String name2 = scanner.nextLine();

        Player player1 = new Player(name1);
        Player player2 = new Player(name2);

        // impove this part
        System.out.println("Assigning X to " + player1.name);
        System.out.println("Assigning O to " + player2.name);

        System.out.println("Input Board Size");
        int n = scanner.nextInt();

        Board board = new Board(n);

        Strategy strategy = new Strategy();

        int turn = 1;

        while(true){
            board.printBoard();
            System.out.println("Enter your move " + (turn == 1 ? player1.name : player2.name));
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if(board.board.get(x).get(y) == Symbol.None && x >= 0 && x < n && y >= 0 && y < n){
                board.board.get(x).set(y, turn == 1 ? Symbol.X : Symbol.O);
            }else{
                System.out.println("Invalid Move");
                continue;
            }

            Result current = strategy.strategy(board);

            if(current == Result.DRAW){
                System.out.println("Match DRAW happened");
                break;
            }

            if(current == Result.WIN){
                System.out.println((turn == 1 ? player1.name : player2.name) + " Won");
                break;
            }

            turn = (turn == 1 ? 2 : 1);
        }

        scanner.close();
    }
}