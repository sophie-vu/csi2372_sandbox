#pragma once
#include <deque>
#include "card.cpp"
using namespace std;
class Deck {
    public:
        Deck();
        Deck(int);
        ~Deck();
        void print();
        void shuffle();
        Card* topCard();
        void popCard();
        Card* giveCard();
    private:
        deque<Card*> deck; // keep virtual functions
};