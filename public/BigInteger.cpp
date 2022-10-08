#include "BigInteger.h"
using namespace std;

BigInteger::BigInteger() {
    this->num = 0;
    this->base = 0;
}

BigInteger::BigInteger(int num, int base) {
    this->num = num;
    this->base = base;    
}

BigInteger::BigInteger(BigInteger& other) {
    this->num = other.num_digits();
    this->base = other.base_digit();
}

BigInteger::~BigInteger() {
    this->num = ;

}