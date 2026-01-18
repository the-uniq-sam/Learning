package models;

public enum Symbol {
    X("X"), 
    O("O"), 
    Free("-"); // Use a dash or space for better visualization

    private final String display;

    // Enum constructor (always private)
    Symbol(String display) {
        this.display = display;
    }

    @Override
    public String toString() {
        return this.display;
    }
}