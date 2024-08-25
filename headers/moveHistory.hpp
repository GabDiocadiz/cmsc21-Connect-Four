#pragma once

#include <stack>

class boardMove{
    public:
    boardMove(int);
    int column;
};

boardMove::boardMove(int c){
    column = c;
}

class moveHistory{
private:
    std::stack<boardMove> moves;
public:
    void addMove(boardMove m){
        moves.push(m);
    }

    boardMove undo(){
        boardMove m = moves.top();
        moves.pop();
        return m;
    }
};