#include <string>
using namespace std;
class Piece {
    string name;
    int color;
    int row;
    char col;
    public:
    Piece();
    Piece(string, int, int, char);
    int getRow();
    char getCol();
    void setRow(int);
    void setCol(char);
    bool isWhitePiece();
    bool isOnBoard(int, char);
    bool validMove(int, char);
    virtual string getName() = 0;
    virtual bool move(int, char) = 0;
};

class King : public Piece {
    public:
    string getName();
    bool move(int, char);
};

class Queen : public Piece {
    public:
    string getName();
    bool move(int, char);
};

class Rook : public Piece {
    public:
    string getName();
    bool move(int, char);
};

class Knight : public Piece {
    public:
    string getName();
    bool move(int, char);
};

class Bishop : public Piece {
    public:
    string getName();
    bool move(int, char);
};