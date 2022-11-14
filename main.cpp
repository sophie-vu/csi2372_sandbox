#include "Crossword.cpp"
#include <iostream>
using namespace std;

int main() {
	Crossword c = Crossword(2, 2);
	c.add_questions("2 + 2", "4", 0, 0, true);
	c.print();
	return 0;
}
