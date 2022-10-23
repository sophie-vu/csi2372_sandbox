// function template
#include <iostream>
#include "BigInteger.cpp"
using namespace std;

int main () {
    BigInteger b = BigInteger(200, 3);
    // BigInteger c = BigInteger(527, 7);
    cout << b;
    cout << b.num_digits() << endl;
    b.add_digit(9);
    cout << b << endl;
    b.remove_digit();
    cout << b << endl;

}