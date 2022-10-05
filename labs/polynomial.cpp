#include <iostream>
#include <array>
#include <vector>
using namespace std;


int main() {
    string input;
    cout << "Enter a polynomial (eg. -5x7 +3x5 -2x2 -8x +4): " << endl;
    cin >> input;
    string spaceDelimiter = " ";
    vector<string> polynomial {};
    int pos = 0;
    while ((pos = input.find(spaceDelimiter)) != string::npos) {
        polynomial.push_back(input.substr(0, pos));
        input.erase(0, pos + spaceDelimiter.length());
    }

    for (const auto &str : polynomial) {
        cout << str << endl;
    }

    return EXIT_SUCCESS;

}

/*
−5𝑥7 + 3𝑥5 − 2𝑥2 − 8𝑥 + 4
Your class should have the following methods,
Constructor for default initialization
Copy Constructor
Add a term (Change the coefficient if the power exists)
Remove a term
Get the degree
Get the coefficient for a specific power
Evaluate
Operators +, -, * for two polynomials.
Operator * for scalar multiplication
*/