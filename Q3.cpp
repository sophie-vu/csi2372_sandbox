#include "Q3.h"
#include <iostream>
using namespace std;

Time::Time() {
    this->h = 0;
    this->min = 0;
    this->s = 0;
    this->mil = 0;
}

Time::Time(int h, int min, int s, int mil) {
    this->h = h;
    this->min = min;
    this->s = s;
    this->mil = mil;
}

Time::Time(const Time& t) {
    this->h = t.h;
    this->min = t.min;
    this->s = t.s;
    this->mil = t.mil;
}

bool Time::operator==(const Time& t) {
    return (this->h == t.h) && 
    (this->min == t.min) && 
    (this->s == t.s) && 
    (this->mil == t.mil);
}

Time& Time::operator+(const Time& t) {
    Time* res;
    int ho, mi, se, mill;

    mill = mil + t.mil;
    res->mil = mill%60;

    se = (res->mil / 60) + s + t.s;
    res->s = se%60;

    mi = (res->s) + min + t.mil;
    res->min = mi%60;

    ho = (res->min / 60) + h + t.h;
    res->h = ho%60;

    return *res;
}

Time& Time::operator-(const Time& t) {
    Time* res;
    int ho, mi, se, mill;

    mill = mil - t.mil;
    res->mil = mill%60;

    se = (res->mil / 60) - s - t.s;
    res->s = se%60;

    mi = (res->s) - min - t.mil;
    res->min = mi%60;

    ho = (res->min / 60) - h - t.h;
    res->h = ho%60;

    return *res;
}

istream& operator>>(istream& in, Time& t) {
    in >> t.h >> t.min >> t.s >> t.mil;
    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    if (t.h < 10) {
        out << "0" << t.h;
    } else {
        out << t.h;
    }
    out << " : ";
    if (t.min < 10) {
        out << "0" << t.min;
    } else {
        out << t.min;
    }
    out << " : ";
    if (t.s < 10) {
        out << "0" << t.s;
    } else {
        out << t.s;
    }
    out << " : ";
    if (t.mil < 10) {
        out << "0" << t.mil;
    } else {
        out << t.mil;
    }
    return out;
}