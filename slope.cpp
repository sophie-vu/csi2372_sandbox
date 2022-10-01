// function template
#include <iostream>
using namespace std;

int getSlope(int m, int x, int b) {
    return (m * x + b);
}

int main () {
  int m = 3;
  int x = 4;
  int b = 5;

  cout << "The slope of y = " << m << "*" << x << " + " << b << "is " << getSlope(3, 4, 5);
}