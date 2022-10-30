#include "Q2.h"
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

str::str() {
    this->s = {};
    this->len = 0;
}

str::str(char chars[]) {
    this->s = chars;
    auto placeholder = sizeof(*chars);
    this->len = placeholder / sizeof(char);
}

str::str(str const& s) {
    this->s = s.s;
    this->len = s.len;
}

str::~str() {
    delete this->s;
    this->len = 0;
}

char str::operator[](int pos) {
    return (this->s)[pos];
}

str str::operator+(str s) {
    int length = this->len + s.len;
    char* arr = new char[length];
    copy(this->s, this->s + this->len, arr);
    copy(s.s, s.s + s.len, arr + this->len);
    str res = str(arr);
    res.len = length;
    return res;
}

// str str::operator+(string s) {
//     str res;
//     int length = this->len + s.length();
//     char char_array[length];
//     strcpy_s(char_array, this->len, this->s);
//     strcpy_s(char_array, s.length(), s.c_str());
//     res.s = char_array;
//     return res;
// }

// str str::operator+(char c) {
//     str res;
//     int length = this->len + 1;
//     char char_array[length];
//     char single[1] = {c};
//     strcpy_s(char_array, this->len, this->s);
//     strcpy_s(char_array, 1, single);
//     res.s = char_array;
//     return res;
// }

string str::convertToString(char* a, int size) {
    string res = "";
    for (int i = 0; i < size; i++) {
        res += a[i];
    }
    return res;
}

str& str::operator=(const str& s) {
    this->s = s.s;
    this->len = s.len;
    // cout << *this << endl;
    return *this;
}

ostream& operator<<(ostream& out, str s) {
    out << "The string content is: ";
    for (int i = 0; i < s.len; i++) {
        if (i == (s.len - 1)) {
            out << s.s[i] << "." << endl;
        } else {
            out << s.s[i] << ", ";
        }
    }
    return out;
}

istream& operator>>(istream& in, str s) {
    in >> s.s;
    return in;   
}