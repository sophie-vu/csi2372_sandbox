#include "BigInteger.h"
#include <list>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

BigInteger::BigInteger() {
    this->num = 0;
    this->base = 10;
    this->sign = 0;
    this->val = "0";
}

BigInteger::BigInteger(int base, int num) {
    this->num = num;
    this->base = base;
    this->sign = (num >= 0) ? 0 : 1;
    this->val = to_string(num);
}

BigInteger::BigInteger(const BigInteger& other) {
    this->num = other.num;
    this->base = other.base;
    this->sign = other.sign;
    this->val = other.val;
}

BigInteger::~BigInteger() {
    val.clear(); // Clear list
    this->num = 0; // Reset
    this->base = 0; // Reset
    this->sign = 0; // Reset
}

int BigInteger::size() {
    return val.size();
}

BigInteger BigInteger::inverse_sign() {
    this->sign *= -1;
    return *this;
}

BigInteger BigInteger::normalize(int sign) {
    for (int i = val.size() - 1; i > 0 && val[i] == '0'; i--) {
        val.erase(val.begin() + i);
    }
    this->sign = (val.size() == 1 && val[0] == '0' ? 1 : sign);
    return *this;
}

int BigInteger::num_digits() { // Calculate the number of digits of the num in the base
    return (int) (floor(log(num)/log(base)) + 1);
}

void BigInteger::add_digit(int a) {
    string str = to_string(this->num);
    str.append(to_string(a));
    this->num = stoi(str);  // Convert string to integer
}

void BigInteger::remove_digit() {
    string str = to_string(this->num);
    str.pop_back();
    this->num = stoi(str); // Convert string to integer
}

void BigInteger::insert_digit(int a, int i) {
    string str = to_string(this->num).insert(i, to_string(a));    
    this->num = stoi(str); // Convert string to integer
}

bool BigInteger::operator==(const BigInteger& other) {
    return this->val == other.val && this->sign == other.sign;
}

void BigInteger::operator=(const BigInteger &other) {
    string a = this->val;
    string b = other.val;
    a = b[0] == '-' ? b.substr(1) : b;
    reverse(a.begin(), a.end());
    this->normalize(b[0] == '-' ? -1 : 1);
}

bool BigInteger::operator<(const BigInteger &other) {
    string a = this->val;
    string b = other.val;
    if (sign != other.sign) {
        return sign < other.sign;
    }

    if (a.size() != b.size()) {
        return sign == 1 ? a.size() < b.size() : a.size() > b.size();
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            return sign == 1 ? a[i] < b[i] : a[i] > b[i];
        }
    }
    return false;
}

BigInteger BigInteger::operator+(BigInteger &other) {
    if (sign != other.sign) {
        BigInteger res = BigInteger(num - other.inverse_sign().num, base);
        return res;
    }
    BigInteger that;
    for (int i = 0, carry = 0; i < val.size() || i < other.size() || carry; i++) {
        carry += (i < val.size() ? val[i] - 48 : 0) + (i < other.val.size() ? other.val[i] - 48 : 0);
        that.val += (carry % 10 + 48);
        carry /= 10;
    }
    return that.normalize(sign);
}

BigInteger BigInteger::operator-(BigInteger &other) {
    BigInteger res;
    if (sign != other.sign) {
        res = BigInteger(num + other.inverse_sign().num, base);
        return res;
    }
    int s = sign;
    sign = other.sign = 1;

    if (num < other.num) {
        res = BigInteger(other.num - this->inverse_sign().normalize(-s).num, base);
        return res;
    }
    for (int i = 0, borrow = 0; i < val.size(); i++) {
        borrow = val[i] - borrow - (i < other.size() ? other.val[i] : 48);
        res.val += borrow >= 0 ? borrow + 48 : borrow + 58;
        borrow = borrow >= 0 ? 0 : 1;
    }
    return res.normalize(s);
}

BigInteger BigInteger::operator*(BigInteger &other) {
    string resVal = "0";
    for (int i = 0, k = val[i] - 48; i < val.size(); i++, k = val[i] - 48) {
        while (k--) {
            resVal += other.val;
            other.val.insert(other.val.begin(), '0');
        }
    }
    BigInteger res = BigInteger(stoi(resVal), base);
    return res.normalize(sign * other.sign);
}

BigInteger BigInteger::operator/(BigInteger &other) {
    if (other.size() == 1 && other.val[0] == '0') {
        other.val[0] /= (other.val[0] - 48);
    }
    string resVal = "0", d;
    for (int j = 0; j < val.size(); j++) {
        d += "0";
    }
    int dSign = sign * other.sign; 
    other.sign = 1;
    for (int i = size() - 1; i >= 0; i--) {
        resVal.insert(resVal.begin(), '0');
        resVal += val.substr(i, 1);
        while (! (resVal < other.val)) {
            resVal = to_string(stoi(resVal) - other.num);
            d[i]++;
        }
    }
    BigInteger res = BigInteger(stoi(d), base);
    return res.normalize(dSign); 
}

BigInteger BigInteger::operator%(BigInteger& other) {
    if (other.size() == 1 && other.val[0] == '0') {
        other.val[0] /= (other.val[0] - 48);
    }

    string resVal = "0";
    other.sign = 1;
    for (int i = size() - 1; i >= 0; i--) {
        resVal.insert(resVal.begin(), '0');
        resVal += val.substr(i, 1);
        while (!(resVal < other.val)) {
            resVal = stoi(resVal) - num;
        }
    }
    BigInteger res = BigInteger(stoi(resVal), base);
    return res;
}

void BigInteger::print() {
    if (sign == -1) {
        putchar('-');
        for (int i = size() - 1; i >= 0; i--) {
            putchar(val[i]);
        }
    }
}