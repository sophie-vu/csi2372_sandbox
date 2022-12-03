#include "card.h"
#include <list>
using namespace std;

class Player {
    public:
        Player();
        ~Player();
        void add_card(Card*);
        void remove_card(Card*);
        void print_hand();
    private:
        list<Card*> hand;
        int tokens;
};