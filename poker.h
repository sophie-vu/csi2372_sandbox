#pragma once
#include "deck.h"
#include "card.h"
#include "player.h"
#include <list>
using namespace std;

class Poker {
    private:
        int num_players;
        Deck deck;
        list<Card*> table;
        list<Player> players;
    public:
        Poker();
        Poker(int);
        void start();
        void play();
        bool isStraightFlush(list<Card*>);
        bool isFourofaKind (list<Card*>);
        bool isFullHouse (list<Card*>);
        bool isFlush(list<Card*>);
        bool isStraight(list<Card*>);
        bool isThreeofaKind(list<Card*>);
        bool isTwoPairs(list<Card*>);
        bool isOnePair(list<Card*>);
};