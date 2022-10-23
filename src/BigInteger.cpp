#include "BigInteger.h"
#include "BaseConverter.cpp"
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * @brief The default constructor that initializes the number to 0 and the base to 10
 */
BigInteger::BigInteger() {
    this->isPositive = true;
    this->arrVal[1] = {0};
    this->val = 0;
    this->base = 10;
}

/**
 * @brief Takes a number and a base and initialize the number and base in the class
 * @param n 
 * @param b 
 */
BigInteger::BigInteger(int n, int b) {
    this->isPositive = (n < 0) ? false : true;
    this->arrVal = convertIntToArray(n, numberOfDigits(n));
    this->val = n;
    this->base = b;
}

/**
 * @brief The copy constructor
 * @param b 
 */
BigInteger::BigInteger(BigInteger const &b) {
    this->isPositive = b.isPositive;
    this->arrVal = b.arrVal;
    this->val = b.val;
    this->base = b.base;
}

/**
 * @brief The desctructor
 */
BigInteger::~BigInteger() {
    base = 0, val = 0;
    isPositive = true;
    delete[] arrVal;
}

/**
 * @brief The number of digits in the number in the given base
 * @return int 
 */
int BigInteger::num_digits() {
    return (1 + floor(log10(base)));
}

/**
 * @brief Add a digit to the end of the number (The least significant digit)
 * @param n 
 */
void BigInteger::add_digit(int n) {
    int len = numberOfDigits(val);
    int* tmp = new int[len];
    for (int i = 0; i < len; i++) {
        tmp[i] = arrVal[i+1];
    }
    tmp[len] = n;
    arrVal = tmp;
    val = convertArrayToInt(arrVal, len + 1);
    return;
}

/**
 * @brief Remove a digit from the end of the number
 */
void BigInteger::remove_digit() {
    static int* res = new int[numberOfDigits(val) - 1];
    for (int i = 0; i < numberOfDigits(val); i++) {
        res[i] = arrVal[i];
    }
    arrVal = res;
    val = convertArrayToInt(res, numberOfDigits(val) - 1);
    return;
}

/**
 * @brief Insert a digit at a particular position. Ignore the task if the position does not exist. 
 * @param i 
 * @param n 
 */
void BigInteger::insert_digit(int i, int n) {
    int len = sizeof(arrVal) + 1;
    int* tmp = new int[len]; // Initialize int array
    int idx; 
    for (idx = len; idx >= n; idx--) {
        arrVal[i] = arrVal[idx - 1]; // Shift elements forward
    }
    arrVal[n - 1] = n; // Insert n at i
    val = convertArrayToInt(arrVal, len);
}

/**
 * @brief For indexing the digits
 * @param i 
 * @return int 
 */
int BigInteger::operator[](int i) {
    return arrVal[i];
}

/**
 * @brief Checks if two numbers are equal
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator==(const BigInteger &b) {
    if (isPositive != b.isPositive) {
        return false;
    }
    int other = ConvertBase(convertArrayToInt(b.arrVal, sizeof(arrVal)), b.base, base);
    val = convertArrayToInt(arrVal, sizeof(arrVal));
    return (convertArrayToInt(arrVal, sizeof(arrVal)) == other);}

/**
 * @brief Checks if the first number is greater than the second number
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator>(const BigInteger &b) {
    if (isPositive && !b.isPositive) {
        return true;
    }
    if (!isPositive && b.isPositive) {
        return false;
    }
    int other = ConvertBase(b.val, b.base, base);
    return (val > other);
}

/**
 * @brief Checks if the first number is greater than the second number
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator<(const BigInteger &b) {
if (isPositive && !b.isPositive) {
        return false;
    }
    if (!isPositive && b.isPositive) {
        return true;
    }
    int other = ConvertBase(b.val, b.base, base);
    return (val < other);
}

/**
 * @brief Checks if the first number is greater than or equal to the second number
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator>=(const BigInteger &b) {
    if (isPositive && !b.isPositive) {
        return true;
    }
    if (!isPositive && b.isPositive) {
        return false;
    }
    int other = ConvertBase(b.val, b.base, base);
    return (val >= other);
}

/**
 * @brief Checks if the first number is less than or equal to the second number
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator<=(const BigInteger &b) {
    if (isPositive && !b.isPositive) {
        return false;
    }
    if (!isPositive && b.isPositive) {
        return true;
    }
    int other = ConvertBase(b.val, b.base, base);
    return (val <= other);
}

/**
 * @brief Checks if two numbers are not equal
 * @param b 
 * @return true 
 * @return false 
 */
bool BigInteger::operator!=(const BigInteger &b) {
    if (isPositive != b.isPositive) {
        return true;
    }
    int other = ConvertBase(b.val, b.base, base);
    return (val != other);}

/**
 * @brief For assigning the second number to the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator=(BigInteger const &b) {
    base = b.base; // Reassign base
    isPositive = b.isPositive; // Reassign isPositive
    delete[] arrVal; // Destroy array
    arrVal = b.arrVal; // Reassign array 
    return *this;
}
/**
 * @brief For adding two numbers, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator+(BigInteger &b) {
    int other = ConvertBase(b.val, b.base, base);
    int res = other + val;
    *this = BigInteger(res, base);
    convertIntToArray(res, numberOfDigits(res));
    return *this;
}

/**
 * @brief For subtracting the second number from the first number, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator-(BigInteger &b) {
    int other = ConvertBase(b.val, b.base, base);
    int res = other - val;
    *this = BigInteger(res, base);
    convertIntToArray(res, numberOfDigits(res));
    return *this;
}

/**
 * @brief For multiplying two numbers, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator*(BigInteger &b) {
    int other = ConvertBase(b.val, b.base, base);
    int res = other * val;
    *this = BigInteger(res, base);
    convertIntToArray(res, numberOfDigits(res));
    return *this;
}

/**
 * @brief For increasing the number by 1. In both prefix format.
 */
BigInteger BigInteger::operator++() {
    val++;
    convertIntToArray(val, numberOfDigits(val));
    return *this;
}

/**
 * @brief For decreasing the number by 1. In both prefix format.
 */
BigInteger BigInteger::operator--() {
    for (int i = 0; i < sizeof(arrVal); i++) {
        arrVal[i]--;
    }
    val = convertArrayToInt(arrVal, sizeof(arrVal));
    return *this;
}

/**
 * @brief For increasing the number by 1. In both postfix format.
 */
BigInteger BigInteger::operator++(int n) {
    BigInteger tmp = *this;
    ++*this;
    return tmp;
}

/**
 * @brief For decreasing the number by 1. In both postfix format.
 */
BigInteger BigInteger::operator--(int n) {
    BigInteger tmp = *this;
    --*this;
    return tmp;
}



/**
 * @brief For diving the first number by the second number, the result should be in the base of the first number (Integer division)
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator/(BigInteger const &b) {
    int other = ConvertBase(b.val, b.base, base);
    int res = other / val;
    *this = BigInteger(res, base);
    convertIntToArray(val, numberOfDigits(val));
    return *this;
}

/**
 * @brief For getting the remainder of the division of the first number by the second number, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator%(BigInteger const &b) {
    int other = ConvertBase(b.val, b.base, base);
    int res = other % val;
    *this = BigInteger(res, base);
    convertIntToArray(val, numberOfDigits(val));
    return *this;
}

/**
 * @brief For printing a number
 * @param out
 * @return ostream& 
 */
ostream& operator<<(ostream& out, const BigInteger &b) {
    out << "(" << b.val << ")" << b.base << endl;
    return out;
}

istream& operator>>(istream& in, BigInteger &b) {
    int n;
    in >> n;
    b.isPositive = (n > 0) ? true : false;
    b.val = n;
    b.convertIntToArray(b.val, b.numberOfDigits(b.val));
    in >> b.base;
    return in;
}

int BigInteger::convertArrayToInt(int array[], int size) {
    int number = 0;
    for (int i = 0; i < size; i++) {
        number *= 10;
        number += array[i];
    }
    return number;
}

int* BigInteger::convertIntToArray(int n, int size) {
    int* arr = new int[size - 1];
    for (int i = size; i > 0; i--) {
        arr[i] = n % 10;
        n = n / 10;
    }
    return arr;
}

int BigInteger::numberOfDigits(int x) { 
    x = abs(x);  
    int res = (x < 10 ? 1 : 
    (x < 100 ? 2 : 
    (x < 1000 ? 3 :
    (x < 10000 ? 4 :
    (x < 100000 ? 5 :
    (x < 1000000 ? 6 :
    (x < 10000000 ? 7 :
    (x < 100000000 ? 8 :
    (x < 1000000000 ? 9 :
    10)))))))));
    return res;
}