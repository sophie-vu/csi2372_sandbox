#include "Q1.h"
#include <iostream>
using namespace std;
// class Piece {
//     string name, color;
//     int row;
//     char col;
//     public:
//     Piece(string, string);
//     string getName();
//     int getRow();
//     char getCol();
//     bool isWhitePiece();
//     virtual bool validMove(int, char) = 0;
//     virtual bool move(int, char) = 0;
// };

Piece::Piece(string name, int color, int row, char col) {
    this->name = name;
    this->color = color;
    this->row = row;
    this->col = col;
}

string Piece::getName() {
    return name;
}

int Piece::getRow() {
    return row;
}

char Piece::getCol() {
    return col;
}

void Piece::setRow(int newRow) {
    this->row = newRow;
}

void Piece::setCol(char newCol) {
    this->col = newCol;
}

bool Piece::isOnBoard(int newRow, char newCol) {
    if (newRow < 1 || newRow > 8) return false; // Invalid input
    if (newCol < 'a' || newCol > 'h') return false; // Invalid input
    return true;
}

bool Piece::validMove(int newRow, char newCol) {
    if (move(newRow, newCol)) {
        setRow(newRow);
        setCol(newCol);
        cout << getName() << " moved to " << getRow() << ", " << getCol() << endl;
        return true;
    }
    cout << "Failed to move " << getName() << " to " << getRow() << ", " << getCol() << endl;
    return false;
}

bool Piece::isWhitePiece() {
    return color == 1;
}

// class King : public Piece {
//     public:
//     bool move(int, char);
// };

bool King::move(int newRow, char newCol) {
    if (!isOnBoard(newRow, newCol)) return false;
    int rowDiff = getRow() - newRow;
    int colDiff = getCol() - newCol;
    if ((rowDiff >= -1) && (rowDiff <= 1) && (colDiff >= -1) && (colDiff <= 1)) {
        return true;
    }
    return false;
}

// class Queen : public Piece {
//     public:
//     bool move(int, char);
// };

bool Queen::move(int newRow, char newCol) {
    if (!isOnBoard(newRow, newCol)) return false;
    int rowDiff, colDiff;
    if (getRow() == newRow) {
        colDiff = (newCol - getCol() > 0) ? 1 : -1;
        for (int i = getCol() + colDiff; i !=  newCol; i = i + colDiff) {
            // if (chessboard[newRow][i] != 0) return false; // Pseudocode for if there is already a piece there
        }
        return true;
    } else if (getCol() == newCol) {
        rowDiff = (newRow - getRow() > 0) ? 1 : -1;
        for (int i = newRow + rowDiff; i !=  newRow; i = i + rowDiff) {
            // if (chessboard[i][newCol] != 0) return false; // Pseudocode for if there is already a piece there
        }
        return true;
    } else if ((newCol - getCol() == newRow - getRow()) || (newCol - getCol() == getRow() - newRow)) {
        rowDiff = (newRow - getRow() > 0) ? 1 : -1;
        colDiff = (newCol - getCol() > 0) ? 1 : -1;
        int i, j;
        for (i = getRow() + rowDiff, j = getCol() + colDiff; i !=  newRow; i += rowDiff, j += colDiff) {
            // if (chessboard[i][j] != 0) return false; // Pseudocode for if ther eis already a piece there
        }
        return true;
    } else {
        return false;
    }
}

// class Rook : public Piece {
//     public:
//     bool move(int, char);
// };

bool Rook::move(int newRow, char newCol) {
    if (!isOnBoard(newRow, newCol)) return false;
    int rowDiff, colDiff;
    if (getRow() == newRow) {
        colDiff = (newCol - getCol() > 0) ? 1 : -1;
        for (int i = getCol() + colDiff; i != newCol; i+= colDiff) {
            // if (chessboard[getRow()][i] != 0) return false; // Pseudocode for if ther eis already a piece there
        }
        return true;
    } else if (getCol() == newCol) {
        rowDiff = (newRow - getRow() > 0) ? 1 : -1; 
        for (int i = getRow() + rowDiff; i != newRow; i += rowDiff) {
            // if (chessboard[i][getCol()] != 0) return false; // Pseudocode for if ther eis already a piece there
        }
        return true;
    } else {
        return false;
    }
}

// class Knight : public Piece {
//     public:
//     bool move(int, char);
// };

bool Knight::move(int newRow, char newCol) {
    if (!isOnBoard(newRow, newCol)) return false;
    if ((getCol() == newCol + 1) || (getCol() == newCol - 1)) {
        if ((getRow() == newRow + 2) || (getRow() == newRow - 2)) {
            return true;
        }
    }
    if ((getCol() == newCol + 2) || (getCol() == newCol - 2)) {
        return true;
    }
    return false;
}

// class Bishop : public Piece {
//     public:
//     bool move(int, char);
// };

bool Bishop::move(int newRow, char newCol) {
    int rowDiff, colDiff;
    if ((newCol - getCol() == newRow - getRow()) || (newCol - getCol() == getRow() - newRow)) {
        rowDiff = (newRow - getRow() > 0) ? 1 : -1;
        colDiff = (newCol - getCol() > 0) ? 1 : -1;
        int i, j;
        for (i = getRow() + j, i = getCol() + colDiff; i != newRow; i += rowDiff, j += colDiff) {
            // if (chessboard[i][j] != 0) return false; // Pseudocode for if ther eis already a piece there
        }
        return true;
    }
    return false;
}