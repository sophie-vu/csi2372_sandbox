#include <string>
#include <set>
using namespace std;
class Piece {
    string name;
    int color;
    int row;
    char col;
    public:
    Piece(string, int, int, char);
    string getName();
    int getRow();
    char getCol();
    void setRow(int);
    void setCol(char);
    bool isWhitePiece();
    bool isOnBoard(int, char);
    bool validMove(int, char);
    virtual bool move(int, char) = 0;
};

class King : public Piece {
    public:
    bool move(int, char);
};

class Queen : public Piece {
    public:
    bool move(int, char);
};

class Rook : public Piece {
    public:
    bool move(int, char);
};

class Knight : public Piece {
    public:
    bool move(int, char);
};

class Bishop : public Piece {
    public:
    bool move(int, char);
};