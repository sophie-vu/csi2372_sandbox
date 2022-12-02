#include "card.h"
#include <iostream>
using namespace std;

Card::Card(Ranks rank, Suits suit) : rank(rank), suit(suit) {

}

Card::~Card() {

}

int Card::getRank() {
    return rank;
}

int Card::getSuit() {
    return suit;
}

int Card::getFaceValue() {
    if (rank <= TEN) {
        return static_cast<int>(rank);
    }
    if (rank <= KING) {
        return 10; // J, Q, K
    }
    return 11; // return ace
}

void Card::print() {
    if (rank <= NINE) {
        cout << rank;
    } else if (rank == TEN) {
        cout << "T"; 
    } else if (rank == JACK) {
        cout << "J";
    } else if (rank == QUEEN) {
        cout << "Q";
    } else if (rank == KING) {
        cout << "K";
    } else {
        cout << "A"; // ace
    }

    switch (suit) {
        case HEARTS:
            cout << "H";
            break;
        case DIAMONDS:
            cout << "D";
            break;
        case CLUBS:
            cout << "C";
            break;
        default:
            cout << "S"; // spades
            break;
    }
}