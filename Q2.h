#include <iostream>
#include <istream>
using namespace std;

class str {
    public: 
        char* s;
        int len;
        str(); // Default
        str(char* a); // User
        str(str const &s); // Copy constructor
        ~str(); // Destructor
        char operator[](int pos); 
        friend istream& operator>>(istream& in, str s); 
        friend ostream& operator<<(ostream& out, str s);
        string convertToString(char* a, int size);
        str operator+(str s); // Concat str
        // str operator+(string s); // Concat string
        // str operator+(char c); // Concat char
        str& operator=(const str& s);
};