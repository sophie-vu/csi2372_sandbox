#include <iostream>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() { // Default constructor
    arrSize = 1;
    coeffArr = new double[1];
    coeffArr[0] = 0;
}

Polynomial::Polynomial(int degree) {
    arrSize = degree + 1;
    coeffArr = new double[arrSize];
    for (int i = 0; i < arrSize; i++) {
        coeffArr[i] = 0;
    }
}

Polynomial::Polynomial(double* coeffientArray, int coefficientCount) {
    arrSize = coefficientCount;
    coeffArr = new double[coefficientCount];
    for (int i = 0; i < coefficientCount; i++) {
        coeffArr[i] = coeffientArray[i];
    }
}

Polynomial::Polynomial(Polynomial& other) { // Copy constructor
    arrSize = other.arrSize;
    coeffArr = new double[arrSize]; // Deep copy
    for (int i = 0; i < arrSize; i++) {
        coeffArr[i] = other.coeffArr[i];
    }
}

Polynomial::~Polynomial() {
    delete[] coeffArr;
    arrSize = 0;
    coeffArr = nullptr;
}

Polynomial Polynomial::Add(Polynomial& other) {
    int sizeOfAnswer = (arrSize >= other.arrSize) ? arrSize : other.arrSize;
    Polynomial answer(sizeOfAnswer - 1);
    if (arrSize >= other.arrSize) {
        for (int i = 0; i < other.arrSize; i++) {
            answer.coeffArr[i] = coeffArr[i] + other.coeffArr[i];
        }
    } else {
        for (int i = 0; i < arrSize; i++) {
            answer.coeffArr[i] = coeffArr[i] + other.coeffArr[i];
        }
    }
    return answer;
}

Polynomial Polynomial::Subtract(Polynomial &other) {
    int sizeOfAnswer = (arrSize >= other.arrSize) ? arrSize : other.arrSize;
    Polynomial answer(sizeOfAnswer - 1);
    if (arrSize >= other.arrSize) {
        for (int i = 0; i < other.arrSize; i++) {
            for (int i = 0; i < other.arrSize; i++) {
                answer.coeffArr[i] = coeffArr[i] - other.coeffArr[i];
            }

            for (int i = other.arrSize; i < arrSize; i++) {
                answer.coeffArr[i] = coeffArr[i];
            }
        }
    } else {
        for (int i = 0; i < arrSize; i++) {
            answer.coeffArr[i] = coeffArr[i] - other.coeffArr[i];
        }
        
        for (int i = arrSize; i < other.arrSize; i++) {
            answer.coeffArr[i] = other.coeffArr[i];
        }
    }
    return answer;
}

Polynomial Polynomial::Multiply(Polynomial &other) {
    int degreeOfAnswer = arrSize + other.arrSize - 2;
    Polynomial answer(degreeOfAnswer);
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < other.arrSize; j++) {
            answer.coeffArr[i + j] += (coeffArr[i] * other.coeffArr[i]);
        }
    }
    return answer;
}

int Polynomial::getDegree() {
    return arrSize - 1;
}

void Polynomial::derive() {
    for (int i = 0; i < arrSize; i++) {
        coeffArr[i] = coeffArr[i + 1] * (i + 1);
    }
    arrSize--;
}

double Polynomial::at(double value) {
    double answer = 0;
    if (arrSize == 1) {
        answer = coeffArr[0];
    } else {
        answer = coeffArr[arrSize - 1];
        for (int i = arrSize - 2; i >= 0; i--) {
            answer = answer * value + coeffArr[i];
        }
    }
    return answer;
}
 
void Polynomial::print() {
    int i;
    for (i = arrSize - 1; i >= 1; i--) {
        if (coeffArr[i] != 0) {
            cout << coeffArr[i] << "x^" << i << " + ";
        }
    }
    cout << coeffArr[0];
    cout << '\n';
}