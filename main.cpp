#include <iostream>
#include "randomGenerator.cpp"
using namespace std;

int main() {
    cout << "test" << endl;
    RandomGenerator a;
    a = RandomGenerator();
    cout << "First: " << a << endl;
    cout << "Second: " << a << endl;
    return 0;
}