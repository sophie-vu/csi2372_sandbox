#include "player.h"

Player::Player() {
    tokens = 50;
}


Player::~Player() {
    for (Card* card : hand) {
        delete card;
    }
    hand.clear();
}

void Player::add_card(Card* c) {
    hand.push_front(c);
}

void Player::remove_card(Card* c) {
    hand.remove(c);
}

void Player::print_hand() {
    for (Card* c : hand) {
        c->print();
    }
}