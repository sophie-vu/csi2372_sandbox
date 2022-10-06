#include <iostream>
class Polynomial {
    private:
        double* coeffArr;
        int arrSize;
    public:
        Polynomial(); // Default constructor
        Polynomial(int degree); // All given numbers is initialized to 0
        Polynomial(double* coefficientArray, int coefficientCount); // Creates with given size & distributes coefficients via given array
        Polynomial(Polynomial& other); // Copy constructor
        ~Polynomial(); // Destructor

        Polynomial Add(Polynomial& other);
        Polynomial Subtract(Polynomial& other);
        Polynomial Multiply(Polynomial& other);
        int getDegree();
        void derive();
        double at(double value); // Evaluates the poly at the given domain value
        void print();       
};