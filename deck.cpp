#include <vector>
#include "deck.h"
#include <iostream>
#include <algorithm>
using namespace std;

Deck::Deck() {
    for (Card::Ranks r=Card::TWO; r <= Card::ACE; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1)) {
        for (Card::Suits s=Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s) + 1)) {
            Card* card = new Card(r, s);
            deck.push_front(card);
        }
    }
}

Deck::~Deck() {
    for (Card* card : deck) {
        delete card;
    }
    deck.clear();
}

void Deck::print() {
    for (Card* card : deck) {
        card->print();
        cout << " ";
    }
}

void Deck::shuffle() {
    random_shuffle(deck.begin(), deck.end());
}

Card* Deck::topCard() {
    return deck.front();
}

void Deck::popCard() {
    deck.push_back(deck.front()); // copy card from front -> back
    deck.erase(deck.begin()); // erase
}