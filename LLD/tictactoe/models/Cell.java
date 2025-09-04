package models;
import enums.Symbol;

public class Cell{
    Symbol symbol;

    public Cell(){
        this.symbol = Symbol.None;
    }

    public Cell(Symbol symbol){
        this.symbol = symbol;
    }

    public Boolean setSymbol(Symbol symbol){
        if(this.symbol != Symbol.None){
            return false;
        }
        this.symbol = symbol;
        return true;
    }

    public Symbol getSymbol(){
        return symbol;
    }

    @Override
    public String toString() {
        return symbol.toString();
    }
}