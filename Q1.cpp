#include "Q1.h"
#include <ostream>

ComplexNumber::ComplexNumber() {
    this->re = 0.0;
    this->im = 0.0;
}

ComplexNumber::ComplexNumber(double re, double im) {
    this->re = re;
    this->im = im;
}

ComplexNumber::~ComplexNumber() {
    this->re = 0.0;
    this->im = 0.0;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber c) {
    ComplexNumber tmp = *new ComplexNumber();
    tmp.re = this->re + c.re;
    tmp.im = this->im + c.im;
    return tmp;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber c) {
    ComplexNumber tmp = *new ComplexNumber();
    tmp.re = this->re - c.re;
    tmp.im = this->im - c.im;
    return tmp;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber c) {
    ComplexNumber tmp = *new ComplexNumber();
    tmp.re = this->re * c.re;
    tmp.im = this->im * c.im;
    return tmp;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber c) {
    ComplexNumber tmp = *new ComplexNumber();
    tmp.re = this->re / c.re;
    tmp.im = this->im / c.im;
    return tmp;
}

void ComplexNumber::operator++() {
    (this->re)++;
    (this->im)++;
}

void ComplexNumber::operator++(int i) {
    this->re += i;
    this->im += i;
}

void ComplexNumber::operator--() {
    (this->re)--;
    (this->im)--;
}

void ComplexNumber::operator--(int i) {
    this->re -= i;
    this->im -= i;
}

ostream& operator<<(ostream& os, ComplexNumber c) {
    os << c.re << " + " << c.im << "i" << endl;
    return os;
}