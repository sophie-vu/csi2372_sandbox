#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief Convert from base N to base 10
 * @param input 
 * @param base 
 * @return long 
 */
long ConvertTo10(const string& input, int base) {
    if (base < 2 || base > 36) { // Invalid base input
        return 0;
    }
    bool isNegative = (input[0] == '-');
    int startIndex = input.length() - 1;
    int endIndex   = isNegative ? 1 : 0;
    long value = 0;
    int digitValue = 1;
    
    for (int i = startIndex; i >= endIndex; i--) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            c -= ('a' - 'A');
        }
        if (c >= '0' && c <= '9') { // Valid char value
            c -= '0';
        } else {
            c = c - 'A' + 10;
        }
        if (c >= base) {
            return 0;
        }
        value += c * digitValue; // Base 10 value of digit
        digitValue *= base;
    }
    if (isNegative) {
        value *= -1;
    }
    return value;
}

/**
 * @brief Convert from base 10 to base N 
 * @param value 
 * @param base 
 * @return string 
 */
string ConvertFrom10(long value, int base) {
    if (base < 2 || base > 36) { // Invalid input base
        return "0";
    }
    bool isNegative = (value < 0);
    if (isNegative) {
        value *= -1;
    }
    string output;
    do {
        char digit = value % base;
     
        if (digit < 10) { // 0-9
            digit += '0';
        }
        else { // A-Z
            digit = digit + 'A' - 10;
        }
        output += digit; // Append digit to string
        value /= base;
    } while (value > 0);
    if (isNegative) {
        output += '-';
    }    
    reverse(output.begin(), output.end());
    return output;
}

/**
 * @brief Converts the input from one base to another * 
 * @param input 
 * @param baseFrom 
 * @param baseTo 
 * @return int 
 */
int ConvertBase(const int& input, int baseFrom, int baseTo) {
    return stoi(ConvertFrom10(ConvertTo10(to_string(input), baseFrom), baseTo));
}

// int main() {
//     cout << "88 to base 2: " << ConvertBase("88", 10, 2) << endl;
//     return 0;
// }