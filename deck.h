#include <deque>
#include "card.cpp"
using namespace std;
class Deck {
    public:
        Deck();
        ~Deck();
        void print();
        void shuffle();
        Card* topCard();
        void popCard();
    private:
        deque<Card*> deck; // keep virtual functions
};