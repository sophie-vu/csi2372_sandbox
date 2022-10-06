#include <iostream>
#include "Polynomial.cpp"
using namespace std;

int main() {
    int d1, d2;
    cout << "Enter degree of first polynomial p: ";
    cin >> d1;
    double* arr = new double[d1 + 1];
    for (int i = d1; i >= 0; i--) {
        cout << "Enter coefficient of x^" << i << ": ";
        cin >> arr[i];
    }
    Polynomial p(arr, d1 + 1);
    p.print();
    cout << "Enter degree of second polynomial q: ";
    cin >> d2;
    double* arr2 = new double[d2 + 1];
    for (int i = d2; i >= 0; i--) {
        cout << "Enter coefficient of x^" << i << ": ";
        cin >> arr2[i];
    }
    Polynomial q(arr2, d2 + 1);
    q.print();
}