/**
 * @brief Header file for the Big Integer class.
 * @author Sophie Vu
 */

#pragma once
#include <iostream>
#include <list>
using namespace std;

class BigInteger {
    private:
        int num;
        int base;
        int sign;
        string val; // Stores the digits
        BigInteger inverse_sign(); // Changes the sign

    public: 
        BigInteger(); // Default constructor
        BigInteger(int base, int num); // Constructor takes number and base
        BigInteger(const BigInteger& other); // Copy constructor
        ~BigInteger(); // Desctructor
        int size(); // Returns number of digits
        BigInteger normalize(int sign); // Removes leading 0 to fix the sign
        int num_digits(); // Number of digits in the number in the given base
        void add_digit(int a); // Add a digit to the end of the number (the least significant digit)
        void remove_digit(); // Remove a digit from the end of the number
        void insert_digit(int a, int i); // Insert a  digit at an index
        int operator[](int i); // Indexing
        bool operator==(const BigInteger& other); // Checks if two Big Integers are equal
        bool operator>(const BigInteger& other);
        bool operator<(const BigInteger& other);
        bool operator>=(const BigInteger& other);
        bool operator<=(const BigInteger& other);
        bool operator!=(const BigInteger& other);
        void operator=(const BigInteger& other);
        BigInteger operator+(BigInteger& other);  
        BigInteger operator-(BigInteger& other);
        BigInteger operator*(BigInteger& other);
        BigInteger operator/(BigInteger& other);
        BigInteger operator%(BigInteger& other);
        void print();
};