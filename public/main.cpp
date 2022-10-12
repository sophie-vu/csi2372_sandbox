 	

// function template
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "BigInteger.cpp"
#include "ctype.h"
using namespace std;

void runOperations(BigInteger &big1, BigInteger &big2) {
    cout << "Num digits: " << big1.num_digits() << endl;
}

int main () {
    try { // Try-catch for user input
        BigInteger big1, big2;
        int base1, number1, base2, number2;    
        cout << "Enter the base for the first big integer: ";
        cin >> base1;
        if (base1 <= 36) {
            cout << "You have entered: " << base1 << "." << endl;
        } else {
            throw base1;
        }

        cout << "Enter the number for the first big integer: ";
        cin >> number1;
        if (number1 <= 999) {
            cout << "You have entered: " << number1 << "." << endl;
        } else {
            throw number1;
        }

        cout << "Enter the base for the second big integer: ";
        cin >> base2;
        if (base2 <= 36) {
            cout << "You have entered: " << base2 << "." << endl;
        } else {
            throw base2;
        }

        cout << "Enter the base for the second big integer: ";
        cin >> number2;
        if (number2 <= 999) {
            cout << "You have entered: " << number2 << "." << endl;
        } else {
            throw number2;
        }

        big1 = BigInteger(base1, number1);
        big2 = BigInteger(base2, number2);

        runOperations(big1, big2); // Run calculations with Big Integers

    } catch (int myInput) {
        cout << "Please enter a valid input.";
    }
    return 0;
}