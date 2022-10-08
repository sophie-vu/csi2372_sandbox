#include <cstddef>
#include <iostream>
#include <array>
#include <math.h>
#include <stdlib.h>
#include "Vector.h"
using namespace std;

Vector::Vector() { // Default constructor
    dimension = 3;
    magnitude = 0.0;
    double val[] = {0.0, 0.0, 0.0};
}

Vector::Vector(double* arr, int num) { // Constructor with params
    val = arr;
    dimension = num;
    magnitude = sqrt((arr[0] * arr[0]) + (arr[1] * arr[1]));
}

Vector::Vector(Vector& other) { // Copy constructor
    dimension = other.getDimension();
    magnitude = other.getManitude();
    for (int i = 0; i < dimension; i++) {
        this->val[i] = other[i];
    }
}

Vector::~Vector() { // Destructor
     delete[] val;
     dimension = magnitude = 0.0;
}

int Vector::getDimension() { // Getter for dimension
    return dimension;
}

void Vector::add_dimension(int n) {
    if (dimension >= sizeof(val)) {
        cout << "The vector has reached the maximum dimension size of " << getDimension() << ".";
    } else { // There is still space left
        for (int i = 0; i < dimension; i++) {
            if (!val[i]) {
                val[i] = n;
                return;
            }
        }
    }
}

int deleteElement(int arr[], int n, int x)
{
// Search x in array
int i;
for (i=0; i<n; i++)
    if (arr[i] == x)
        break;
 
// If x found in array
if (i < n)
{
    // reduce size of array and move all
    // elements on space ahead
    n = n - 1;
    for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
}
 
return n;
}
 

void Vector::remove_dimension(int index) {
    if (index < this->dimension) {
        this->dimension = this->dimension - 1;
        for (int i = index; i < this->dimension; i++) {
            val[i] = val[i+1];
        }
    }
}

void Vector::insert_dimension(int index, int n) {
    if (n >= 0 && n < getDimension()) {
        val[index] = n;
    } else if (n < 0) {
        val[getDimension() + n % getDimension()] = n;
    } else {
        val[n % getDimension()] = n;
    }
}

int Vector::getManitude() { // Getter for the magnitude
    return magnitude;
}

bool Vector::operator[](int n) {
    if (n >= 0 && n < getDimension()) {
        return val[n];
    } else if (n < 0) {
        return val[getDimension() + n % getDimension()];
    } else {
        return val[n % getDimension()];
    }
}

bool Vector::operator==(Vector& other) {
    for (int i = 0; i < this->dimension; i++) {
        if (val[i] != other[i]) {
            return false;
        }
    }
    return (this->dimension == other.dimension) && (this->magnitude == other.magnitude);
}

bool Vector::operator!=(Vector& other) {
    bool res = (*this == other) ? false : true;
    return res;
}

void Vector::operator=(Vector& other) {
    this->dimension = other.getDimension();
    this->magnitude = other.getManitude();
    for (int i = 0; i < this->dimension; i++) {
        this->val[i] = other.val[i];
    }
}

Vector Vector::operator+(Vector& other) {
    int size = (this->getDimension() > other.getDimension()) ? getDimension() : other.getDimension();
    double* arr = new double[size];
    Vector res = *new Vector(arr, size);
    for (int i = 0; i < dimension; i++) {
        res.val[i] = this->val[i] + other.val[i];
    }
    return res;
}

Vector Vector::operator-(Vector& other) {
    int size = (this->getDimension() > other.getDimension()) ? getDimension() : other.getDimension();
    double* arr = new double[size];
    Vector res = *new Vector(arr, size);
    for (int i = 0; i < dimension; i++) {
        res.val[i] = this->val[i] - other.val[i];
    }
    return res;
}

Vector Vector::operator*(Vector& other) {
    int size = (this->getDimension() > other.getDimension()) ? getDimension() : other.getDimension();
    double* arr = new double[size];
    Vector res = *new Vector(arr, size);
    for (int i = 0; i < dimension; i++) {
        res.val[i] = this->val[i] * other.val[i];
    }
    return res;
}

void Vector::operator+=(Vector& other) {
    for (int i = 0; i < dimension; i++) {
        this->val[i] = this->val[i] + other.val[i];
    }
}

void Vector::operator-=(Vector& other) {
    for (int i = 0; i < dimension; i++) {
        this->val[i] = this->val[i] - other.val[i];
    }
}

void Vector::operator<<(Vector& other) {
    cout << "v = (";
    for (int i = 0; i < other.dimension; i++) {
        cout << other.val[i] << ", ";
    }
    cout << ")" << endl;
}