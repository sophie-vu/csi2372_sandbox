#include "poker.h"
using namespace std;

Poker::Poker() {
    num_players = 2;
    deck.shuffle();
    for (int i = 0; i < num_players; ++i) {
        Player p;
        players.push_front(p);
    }
}

Poker::Poker(int num) {
    if (num >= 3) {
        deck = Deck(num);
    } else {
        num_players = num;
        deck.shuffle();
        for (int i = 0; i < num_players; ++i) {
            Player p;
            players.push_front(p);
        }
    }
}

void Poker::start() { // Give 5 cards to each player
    Card* c1; 
    Card* c2; 
    Card* c3; 
    Card* c4; 
    Card* c5; 
    bool ans;
    int card_num;
    for (Player p : players) {
        c1 = deck.giveCard();
        c2 = deck.giveCard();
        c3 = deck.giveCard();
        c4 = deck.giveCard();
        c5 = deck.giveCard();
        p.add_card(c1);
        p.add_card(c2);
        p.add_card(c3);
        p.add_card(c4);
        p.add_card(c5);
        p.print_hand();
        cout << "Do you want to remove any of your cards? " << endl;
        cin >> ans;
        if (ans) {
            cout << "Which card? (Eg. QH 2D) " << endl;
        } else {
            break;
        }
    }
}

bool isStraightFlush(list<Card*>);
bool isFourofaKind (list<Card*>);
bool isFullHouse (list<Card*>);
bool isFlush(list<Card*>);
bool isStraight(list<Card*>);
bool isThreeofaKind(list<Card*>);
bool isTwoPairs(list<Card*>);
bool isOnePair(list<Card*>);