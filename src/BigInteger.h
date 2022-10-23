#include <iostream>
using namespace std;

class BigInteger {
private:
    int base;
    bool isPositive;
    int *arrVal;
    int val;
public:
    BigInteger(); // Default constructor
    BigInteger(int n, int b); // Parameter constructor
    BigInteger(const string &input, int b); 
    BigInteger(BigInteger const &b); // Copy constructor
    ~BigInteger(); // Desctructor
    int num_digits(); // Returns the number of digits in the number of the given base
    void add_digit(int n); // Adds a digit to the end of the number
    void remove_digit(); // Remove a digit from the end of the number
    void insert_digit(int i, int n); // Insert a digit at a particular position
    int operator[](int i); // Indexing
    bool operator==(BigInteger const &b); // Checks if 2 numbers are equal
    bool operator>(BigInteger const &b); // Checks if the first number is greater than the second number
    bool operator<(BigInteger const &b); // Checks if the first number is less than the second number
    bool operator>=(BigInteger const &b); // Checks if the first number is greater than or equal to the second number
    bool operator<=(BigInteger const &b); // Checks if the first number is less than or equal to the second number
    bool operator!=(BigInteger const &b); // Checks if 2 numbers aren't equal
    BigInteger operator=(BigInteger const &b); // Assigns the second number to the first
    BigInteger operator+(BigInteger &b); // Addition of two numbers
    BigInteger operator-(BigInteger &b); // Substraction of two numbers
    BigInteger operator*(BigInteger &b); // Multiplication of two numbers
    BigInteger operator++(); // For increasing the number by 1 (pre)
    BigInteger operator--(); // For decreasing the number by 1 (pre)
    BigInteger operator++(int n); // For increasing the number by 1 (post)
    BigInteger operator--(int n); // For decreasing the number by 1 (post)
    BigInteger operator/(BigInteger const &b); // Integer division
    BigInteger operator%(BigInteger const &b); // Integer modulo
    friend istream& operator>>(istream &in, BigInteger &b);
    friend ostream& operator<<(ostream& os, BigInteger const &b);
    int* convertIntToArray(int n, int size);
    int convertArrayToInt(int [], int size);
    int numberOfDigits(int x);
};