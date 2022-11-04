#include "Line.cpp"
#include <tuple>
#include <iostream>
using namespace std;

int main() {
    Line l = Line();
    Line s = Line(2, 4);
    double x, y;
    cout << l << s;
    cout << "Enter pointX: ";
    cin >> x;
    cout << "Enter pointY: ";
    cin >> y;
    auto t = l.intersection_point(s, x , y);
    cout << "(" << get<0>(t) << ", " << get<1>(t) << ")\n";
    return 0;
}