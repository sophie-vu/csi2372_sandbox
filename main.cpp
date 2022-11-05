#include "Polynomial.cpp"
#include <iostream>
using namespace std;

int main() {
    Polynomial p, q;
    p.addTerm(0, 3);
    p.addTerm(1, 4);
    p.addTerm(2, 5);
    p.addTerm(3, 6);

    q.addTerm(0, 8);
    q.addTerm(2, 8);
    q.addTerm(4, -10);
    q.addTerm(6, -10);

    q.removeTerm(2);
    q.removeTerm(6);

    cout << p << endl << q << endl;
    return 0;
}