#include "board.hpp"

Board::Board(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7;j++){
            grid[i][j] = 0;
        }
    }
    rows = 6;
    columns = 7;
    currentPlayer = 1;
    win = 0;
    colInput = -1;
}

bool Board::checkAvailable(int column){
    if(grid[0][column] != 0)
        return 1;
    else    
        return 0;
}

bool Board::checkFull(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(grid[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

bool Board::placeChip(int column){
    if(checkAvailable(column) == 1)
        return 0;
    else{
        for(int i = rows-1; i >= 0 ; i--){
            if(grid[i][column] == 0){
                grid[i][column] = currentPlayer;
                return 1;
            }
        }
        return 0;
    }
}

void Board::removeChip(int column) {
    for(int i = rows-1; i >= 0 ; i--){
        if (grid[i][column] > 0){
            grid[i][column] = 0;
            return;
        }
    }
}

bool Board::checkWinner(){
    //horizontal
    int count;
    for(int i=0;i<rows;i++){
        count=0;
        for(int j=0;j<columns;j++){
            if(grid[i][j]==currentPlayer)
                count++;
            else if(grid[i][j]!=currentPlayer)
                count=0;
            if(count==4)
                return 1;
        }
    }

    //vertical
    for(int j=0;j<columns;j++){
        count=0;
        for(int i=0;i<rows;i++){
            if(grid[i][j]==currentPlayer)
                count++;
            else if(grid[i][j]!=currentPlayer)
                count=0;
            if(count==4)
                return 1;
        }
    }
    
    //diagonal1
    for(int x = 0; x < rows - 3; x++) {
        for(int y = 0; y < columns- 3; y++) {
            if(grid[x][y]==currentPlayer &&
                grid[x+1][y+1]==currentPlayer &&
                grid[x+2][y+2]==currentPlayer &&
                grid[x+3][y+3]==currentPlayer)
                return 1;
        }
    }
    //diagonal2
    for(int x = 0; x < rows- 3; x++) {
        for(int y = 3; y < columns; y++) {
            if(grid[x][y]==currentPlayer &&
                grid[x+1][y-1]==currentPlayer &&
                grid[x+2][y-2]==currentPlayer &&
                grid[x+3][y-3]==currentPlayer)
                return 1;
        }
    }

    return 0;
}

int Board::playTurn(int col){
    if (placeChip(col)) {
        if(checkWinner() == 1){
            win = currentPlayer;
        }
        else if(checkFull() == 1){
            win = 3;
        }

        currentPlayer = currentPlayer == 1 ? 2 : 1;

        //display();
        return 1;
    }

    return 0;
}


int Board::getCurrentPlayer() {
    return currentPlayer;
}

int Board::getWinner() {
    return win;
}

int Board::getCell(int row, int col) {
    return grid[row][col];
}

void Board::display(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%i ", grid[i][j]);
        }
        printf("\n");
    }
}