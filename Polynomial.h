#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Polynomial {
    private:
        vector<tuple<int, int>> pol;
    public:
        Polynomial();
        Polynomial(const Polynomial& p);
        void addTerm(int power, int coef);
        void removeTerm(int power);
        int getDegree();
        int getCoefficient(int power);
        int evaluate(int x);
        void customSort();
        static bool sortBySec(const tuple<int, int>& a, const tuple<int, int>& b);
        void operator+(const Polynomial &p);
        void operator-(const Polynomial &p);
        void operator*(const Polynomial &p);
        void operator*(int v);
};