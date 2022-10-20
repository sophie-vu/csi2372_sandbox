#include "randomGenerator.h"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

RandomGenerator::RandomGenerator() {
    this->s = 4;
    this->first = getRand();
    this->second = getRand();
    seq.push_back(first);
    seq.push_back(second);
        cout << "Goes here" << endl;

}

RandomGenerator::RandomGenerator(int s, int first, int secon) {
    this->s = 2 * s;
    this->first = (first % s == 0) ? first : getRand();
    this->second = (second % s == 0) ? second : getRand();
    seq.push_back(first);
    seq.push_back(second);
}

RandomGenerator::RandomGenerator(RandomGenerator const &r) {
    this->s = r.s;
    this->first = r.first;
    this->second = r.second;
    this->seq = r.seq;
}

RandomGenerator::~RandomGenerator() {
    s = first = second = 0;
    vector<int>::iterator it1, it2;
    it1 = seq.begin();
    it2 = seq.end();
    seq.erase(it1, it2);
}

int RandomGenerator::operator[](int i) {
    return seq.at(i);
}

bool RandomGenerator::operator==(RandomGenerator const &r) {
    if (s != r.s) return false;
    for (int i = 0; i < r.seq.size(); i++) {
        if (seq.at(i) != r.seq.at(i)) {
            return false;
        }
    }
    return true;
}

bool RandomGenerator::operator!=(const RandomGenerator &r) {
    if (s != r.s) return true;
    for (int i = 0; i < r.seq.size(); i++) {
        if (seq.at(i) != r.seq.at(i)) {
            return true;
        }
    }
    return false;
}

void RandomGenerator::operator=(RandomGenerator const &r) {
    RandomGenerator tmp;
    tmp = r;
    return;
}

RandomGenerator RandomGenerator::operator+(const RandomGenerator &r) {
    int tmpS = (s > r.s) ? r.s : s; // Get the smallest s
    int tmpFirst = format(first + r.first, tmpS);
    int tmpSecond = format(second + r.second, tmpS);
    RandomGenerator tmp = RandomGenerator(tmpS, tmpFirst, tmpSecond);
    for (int i = 0; i < tmpS; i++) {
        tmp.seq.push_back(seq.at(i) + r.seq.at(i));
    }
    return tmp;
}

RandomGenerator RandomGenerator::operator-(const RandomGenerator &r) {
    int tmpS = getRand();
    int tmpFirst = first - r.first;
    int tmpSecodn = second - r.second;
    RandomGenerator tmp = RandomGenerator(tmpS, tmpFirst, tmpSecodn);
    for (int i = 0; i < tmpS; i++) {
        tmp.seq.push_back(seq.at(i) - r.seq.at(i));
    }
    return tmp;
}

RandomGenerator RandomGenerator::operator*(const RandomGenerator &r) {
    int tmpS = getRand();
    int tmpFirst = first * r.first;
    int tmpSecodn = second * r.second;
    RandomGenerator tmp = RandomGenerator(tmpS, tmpFirst, tmpSecodn);
    for (int i = 0; i < tmpS; i++) {
        tmp.seq.push_back(seq.at(i) + r.seq.at(i));
    }
    return tmp;
}

void RandomGenerator::operator+=(RandomGenerator const &r) {
    s = s + r.s;
    first = first + r.first;
    second = second + r.second;
    for (int i = 0; i < r.seq.size(); i++) {
        seq[i] = r.seq[i] + seq[i];
    }
    return;
}

void RandomGenerator::operator-=(RandomGenerator const &r) {
    s = s - r.s;
    first = first - r.first;
    second = second - r.second;
    for (int i = 0; i < r.seq.size(); i++) {
        seq[i] = r.seq[i] - seq[i];
    }
    return;
}

void RandomGenerator::operator*=(RandomGenerator const &r) {
    s = s * r.s;
    first = first * r.first;
    second = second - r.second;
    for (int i = 0; i < r.seq.size(); i++) {
        seq[i] = r.seq[i] * seq[i];
    }
    return;
}

void RandomGenerator::operator++() {
    int lastElem = seq.back();
    seq.push_back(format(lastElem, s));
}

void RandomGenerator::operator--() {
    seq.pop_back();
}

ostream& operator<<(ostream& os, RandomGenerator const &r) {
    cout << "Goes here" << endl;
    for (int i = 0; i < r.seq.size(); i++) {
        if (i == r.seq.size() - 1) {
            os << r.seq[i];
        } else {
            os << r.seq[i] << ", ";
        }
    }
    return os;
}

int RandomGenerator::getRand() { 

    string k = "9", j = "1";
    for (int i = 0; i < s; i++) {
        cout << "S IS: " << s << endl;
        k.append(0);
        j.append(0);
    }
    return rand() % stoi(k) + stoi(j); 
}

int RandomGenerator::format(int e, int givenS) {
    if ((log10(e) + 1) == givenS) { // If valid number of digits
        return e;
    } else {
        string str = to_string(e); // Parse to string
        string res = ""; 
        int i = str.length()/2; // Get middle index
        for (int k = givenS/2; k >= 0; k--) { // Lower half
            int idx = i - k;
            res.append(&str.at(idx));
        }
        for (int j = 1; j < givenS/2; j++) { // Upper half
            int idx = i + j;
            res.append(&str.at(idx));
        }
        return stoi(res); // Parse to int
    }
}

