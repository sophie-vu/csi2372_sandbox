#include "Q1.cpp"
#include "Q2.cpp"
#include "Q3.cpp"
#include "Q4.cpp"
using namespace std;

int main() {
    // ComplexNumber a, b, c;
    // cout << "Enter a real and complex coefficient of the first complex number: " << endl;
    // cin >> a.re;
    // cin >> a.im;

    // cout << "Enter a real and complex coefficient of the second complex number: " << endl;
    // cin >> b.re;
    // cin >> b.im;

    // c = a + b;
    // cout << c << endl;

    // c = a - b;
    // cout << c << endl;

    // str a, b, c;
    // char str_a [3] = {'a', 'b', 'c'};
    // char str_b [3] = {'d', 'e', 'f'};
    // char str_c [3] = {};
    // a.s = str_a;
    // a.len = 3;
    // b.s = str_b;
    // b.len = 3;
    // c.s = str_c;
    // c.len = 3;
    // cout << "Before: " << a << endl;
    // a = b;
    // cout << "After: " << a << endl;
    
    // Time teem = *new Time(16, 20, 30, 55);
    // cout << teem << endl;

    Dynamic d = *new Dynamic(0, 4);
    d.add_item(10);
    d.add_item(0);
    d.add_item(-2);
    d.add_item(1);
    // cout << d << endl;
    return 0;
}