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