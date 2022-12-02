#include "deck.cpp"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(nullptr)); 
	Deck deck;
	deck.shuffle();
	deck.print();
	cout << endl;
	Card* card = deck.topCard();
	card->print();
	cout << endl;
	deck.popCard();
	deck.print();
	system("pause");
	return 0;
}