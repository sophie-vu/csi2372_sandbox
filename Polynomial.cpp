#include "Polynomial.h"
#include <algorithm>
using namespace std;

Polynomial::Polynomial() {
    this->pol = {tuple<int, int>(0, 0)};
}

Polynomial::Polynomial(const Polynomial& p) {
    this->pol = p.pol;
}

void Polynomial::addTerm(int power, int coef) {
    pol.push_back(tuple<int, int>(coef, power));
    customSort();
}

void Polynomial::removeTerm(int power) {
    pol.erase(
        remove_if(
            pol.begin(), pol.end(),
            [power](const tuple<int, int>& x) -> bool {
                return get<0>(x) == power;
            }
        ), pol.end()
    );
}

void Polynomial::customSort() {
    sort(pol.begin(), pol.end(), sortBySec);
}

bool sortBySec(const tuple<int, int>& a, const tuple<int, int>& b) {
    return (get<1>(a) < get<1>(b));
}

void Polynomial::operator+(const Polynomial &p) {
    for (tuple<int, int> t : pol) {
        for (tuple<int, int> v : p.pol) {
            if (get<0>(t) == get<0>(v)) {
                get<1>(t) += get<1>(v);
            }
        }
    }
}


void Polynomial::operator-(const Polynomial &p) {
    for (tuple<int, int> t : pol) {
        for (tuple<int, int> v : p.pol) {
            if (get<0>(t) == get<0>(v)) {
                get<1>(t) -= get<1>(v);
            }
        }
    }
}

void Polynomial::operator*(const Polynomial &p) {
    for (tuple<int, int> t : pol) {
        for (tuple<int, int> v : p.pol) {
            if (get<0>(t) == get<0>(v)) {
                get<1>(t) *= get<1>(v);
            }
        }
    }
}

void Polynomial::operator*(int v) {
    for (tuple<int, int> t : pol) {
        get<1>(t) *= v;
    }
}