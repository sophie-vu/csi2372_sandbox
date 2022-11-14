#include <string.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
    string question;
    string answer;
    int mIndex;
    int nIndex;
    bool isHori;
};

class Crossword {
    private:
        char ** userView; // User grid for their answers
        char** puzzle; // Double array of vectors
        int n; // Columns
        int m; // Rows
        Node* questions; // Array of questions
    public:
        Crossword();
        Crossword(int, int);
        bool add_questions(string, string, int, int, bool);
        void solve(int, int, string);
        bool validInput(int, int, string, string, bool); // Added method
        bool match(string, int, int, bool); // Added method
        // int spaceLeft(string, int, int, bool);
        void print();
        Node* addToArray(Node*, const Node&, int&);
        // friend ostream& operator<<(ostream&, Crossword);
};