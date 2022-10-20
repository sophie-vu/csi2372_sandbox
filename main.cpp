#include <iostream>
#include "randomGenerator.cpp"
using namespace std;

int main() {
    RandomGenerator a = RandomGenerator();
    RandomGenerator b = RandomGenerator(2, 456, 8);
    cout << a << endl;
    cout << b << endl;
    return 0;
}