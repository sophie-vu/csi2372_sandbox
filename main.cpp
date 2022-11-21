#include "Relation.cpp"
#include <iostream>
using namespace std;

int main() {
    Set<string> s;
    Relation<string> res;
    const string str = "string";
    s.add_element(str);
    s.add_element("wow");
    Pair<string> p;
    p.first = "test";
    p.second = "10";
    res.add_element(p);
    return 0;
}