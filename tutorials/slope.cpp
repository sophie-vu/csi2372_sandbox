#include <iostream>
using namespace std;
 
int getSlope(int m, int x, int b) {
    return m * x + b;
}

int main() {
    int a, b, c;
    cout << "Let's calculate slopes with the equation y = mx + b. " << endl;
    cout << "What is the value of m? ";
    cin >> a;
    cout << "What is the value of x? ";
    cin >> b;
    cout << "What is the value of b? ";
    cin >> c;
    cout << "The slope of the equation is " << getSlope(a, b, c) << ". ";
    // cin >> d;
    return 0;
}