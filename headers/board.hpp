#include <stdio.h>

class Board {
    private:
        // properties of board
        int grid[6][7];
        int rows;
        int columns;
        int currentPlayer;
        int win;

        int colInput;

    public:
        Board();            // Constructor
        bool checkAvailable(int);  
        bool checkFull();               
        bool placeChip(int);        // Takes a color and column as input
        void removeChip(int);
        bool checkWinner();  
        int playTurn(int);

        int getWinner();
        int getCurrentPlayer();

        int getCell(int, int);
        void display();
};