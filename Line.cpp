#include "Line.h"
#include <iostream>
using namespace std;

Line::Line() {
    this->m = 0; 
    this->b = 0;
}

Line::Line(int m, int b) {
    this->m = m;
    this->b = b;
}

Line::Line(const Line& l) {
    this->m = l.m;
    this->b = l.b;
} 

Line::~Line() {
    this->m = this->b = 0;
}

int Line::getM() {
    return m;
}

void Line::setM(int m) {
    this->m = m;
}

int Line::getB() {
    return this->b; 
}

void Line::setB(int b) {
    this->b = b;
}

bool Line::is_parallel(const Line &l) {
    return this->m == l.m;
}

int getY(const Line& l, double x) {
    return l.m * x + l.b;
}

tuple<int, int> Line::intersection_point(const Line &l, double &x, double &y) {
    int resX = (l.m * x - this->m * x) + (l.b - this->b);
    int resY = getY(l, resX);
    return tuple<int, int>(resX, resY);
}

ostream& operator<<(ostream& out, const Line& l) {
    out << "y = " << l.m << "x + " << l.b << "\n";
    return out;
}