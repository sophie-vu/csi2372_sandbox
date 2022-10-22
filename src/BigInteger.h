#include <iostream>
using namespace std;

class BigInteger {
private:
    int base;
    bool isPositive;
    int *arr;
public:
    BigInteger(); // Default constructor
    BigInteger(int n, int b); // Parameter constructor
    BigInteger(const string &input, int b); 
    BigInteger(BigInteger const &b); // Copy constructor
    ~BigInteger(); // Desctructor
    int num_digits(); // Returns the number of digits in the number of the given base
    void add_digit(int n); // Adds a digit to the end of the number
    void remove_digit(int n); // Remove a digit from the end of the number
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
    void operator++(); // For increasing the number by 1
    void operator--(); // For decreasing the number by 1
    BigInteger operator/(BigInteger const &b); // Integer division
    BigInteger operator%(BigInteger const &b); // Integer modulo
    ostream& operator<<(ostream &os); 
    istream& operator>>(istream &os);
    int convertArrayToInt(int* n);
    int* convertIntToArray(int n);
};