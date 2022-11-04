#include <tuple>
#include <iostream>
using namespace std;

class Line {
    private:
        int m;
        int b;
    public:
        Line(); 
        Line(int m, int b);
        Line(const Line& l);
        ~Line();
        int getM();
        void setM(int m);
        int getB();
        void setB(int b);
        bool is_parallel(const Line& l);
        tuple<int, int> intersection_point(const Line& l, double &x, double &y);
        friend int getY(const Line& l, double x);
        friend ostream& operator<<(ostream& out, const Line& l);
};