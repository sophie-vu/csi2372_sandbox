#include <iostream>
#include <stdlib.h>
#include "Vector.cpp"
using namespace std;

int main() {
    int x, y, z, size;
    bool notValid = true;
    while (notValid) {
        cout << "What is the dimension of the array? " << endl;
        cin >> size;
        if ((size > 3) || (size < 2)) {
            cout << "Enter either a dimension that is either 2d or 3d. ";
        } else {
            notValid = false;
            break;
        }
    }
    double* arr = new double[size];
    cout << "Enter the x axis: " << endl;
    cin >> x;
    cout << "Enter the y axis: " << endl;
    cin >> y; 
    arr[0] = x;
    arr[1] = y;   
    if (size == 3) {
        cout << "Enter the z axis: " << endl;
        cin >> z;    
        arr[2] = z;
    }
    Vector v = Vector(arr, size);
}