#include <iostream>
using namespace std;

class Time {
    private:
        int h;
        int min;
        int s;
        int mil; 
    public:
        Time();
        Time(int h, int min, int s, int mil);
        Time(const Time& t);
        bool operator==(const Time& t);
        Time& operator-(const Time& t);
        Time& operator+(const Time& t);
        friend istream& operator>>(istream& in, Time& t);
        friend ostream& operator<<(ostream& out, const Time& t);
};