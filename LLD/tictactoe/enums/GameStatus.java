package enums;

public enum GameStatus{
    WIN, DRAW, CONTINUE;

    @Override
    public String toString() {
        switch(this){
            case WIN:
                return "WIN";
            case DRAW:
                return "DRAW";
            case CONTINUE:
                return "CONTINUE";
        }
        return "";
    }
}