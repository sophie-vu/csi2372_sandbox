#include <iostream>
using namespace std;

class ComplexNumber {
    public:
    double re, im;
    ComplexNumber();
    ComplexNumber(double re, double im);
    ~ComplexNumber();
    ComplexNumber operator+(ComplexNumber c);
    ComplexNumber operator-(ComplexNumber c);
    ComplexNumber operator*(ComplexNumber c);
    ComplexNumber operator/(ComplexNumber c);
    void operator++(); // Prefix
    void operator--(); // Prefix
    void operator++(int i); // Postfix
    void operator--(int i); // Postfix
    friend ostream& operator<<(ostream& os, ComplexNumber c);
};