#include "BigInteger.h"
#include "BaseConverter.cpp"
#include <string>
using namespace std;

/**
 * @brief The default constructor that initializes the number to 0 and the base to 10
 */
BigInteger::BigInteger() {
    this->isPositive = true;
    this->arr = {0};
    this->base = 10;
}

/**
 * @brief Takes a number and a base and initialize the number and base in the class
 * @param n 
 * @param b 
 */
BigInteger::BigInteger(int n, int b) {
    this->isPositive = (n < 0) ? false : true;
    this->arr = convertIntToArray(n);
    this->base = b;
}

/**
 * @brief The copy constructor
 * @param b 
 */
BigInteger::BigInteger(BigInteger const &b) {
    this->isPositive = b.isPositive;
    this->arr = b.arr;
    this->base = b.base;
}

/**
 * @brief The desctructor
 */
BigInteger::~BigInteger() {
    base = 0;
    isPositive = true;
    delete[] arr;
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
    int len = sizeof(arr) + 1;
    int newArr[len];
    for (int i = 0; i < len; i++) {
        if (i == (len-1)) {
            newArr[i] = n;
        } else {
            newArr[i] = arr[i];
        }
    }
    arr = newArr;
}

/**
 * @brief Remove a digit from the end of the number
 * @param n 
 */
void BigInteger::remove_digit(int n) {
    int len = sizeof(arr) - 1;
    int newArr[len];
    for (int i = 0; i < len; i++) {
        newArr[i] = arr[i];
    }
    arr = newArr;
}

/**
 * @brief Insert a digit at a particular position. Ignore the task if the position does not exist. 
 * @param i 
 * @param n 
 */
void BigInteger::insert_digit(int i, int n) {
    int len = sizeof(arr) + 1;
    arr[len]; // Initialize int array
    int idx; 
    for (idx = len; idx >= n; idx--) {
        arr[i] = arr[idx - 1]; // Shift elements forward
    }
    arr[n - 1] = n; // Insert n at i
}

/**
 * @brief For indexing the digits
 * @param i 
 * @return int 
 */
int BigInteger::operator[](int i) {
    return arr[i];
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
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    return (convertArrayToInt(arr) == other);}

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
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    return (convertArrayToInt(arr) > other);
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
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    return (convertArrayToInt(arr) < other);
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
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    return (convertArrayToInt(arr) >= other);
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
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    return (convertArrayToInt(arr) <= other);
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
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    return (convertArrayToInt(arr) != other);}

/**
 * @brief For assigning the second number to the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator=(BigInteger const &b) {
    base = b.base; // Reassign base
    isPositive = b.isPositive; // Reassign isPositive
    delete[] arr; // Destroy array
    arr = b.arr; // Reassign array 
    return *this;
}
/**
 * @brief For adding two numbers, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator+(BigInteger &b) {
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    int curr = convertArrayToInt(arr);
    int res = other + curr;
    *this = BigInteger(res, base);
    return *this;
}

/**
 * @brief For subtracting the second number from the first number, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator-(BigInteger &b) {
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    int curr = convertArrayToInt(arr);
    int res = other - curr;
    *this = BigInteger(res, base);
    return *this;
}

/**
 * @brief For multiplying two numbers, the result should be in the base of the first number
 * @param b 
 * @return BigInteger 
 */
BigInteger BigInteger::operator*(BigInteger &b) {
    int other = ConvertBase(convertArrayToInt(b.arr), b.base, base);
    int curr = convertArrayToInt(arr);
    int res = other * curr;
    *this = BigInteger(res, base);
    return *this;
}

/**
 * @brief For increasing the number by 1. In both prefix and postfix format.
 */
void BigInteger::operator++() {
    for (int i = 0; i < sizeof(arr); i++) {
        arr[i]++;
    }
}

/**
 * @brief For decreasing the number by 1. In both prefix and postfix format.
 */
void BigInteger::operator--() {
    for (int i = 0; i < sizeof(arr); i++) {
        arr[i]--;
    }
}



int BigInteger::convertArrayToInt(int* array) {
    int number = 0;
    for (int i = 0; i < 3; i++) {
        number *= 10;
        number += array[i];
    }
    return number;
}

int* BigInteger::convertIntToArray(int n) {
    int array[sizeof(arr)];
    for (int i = sizeof(arr); i >= 0; i--) {
        array[i] = n % 10;
        n /= 10;
    }
    return array;
}