#include "Relation.cpp"
#include "Set.cpp"
#include <iostream>
using namespace std;

int main() {
    Set<string> s;
    string str = "string";
    s.add_element(str);
    s.add_element("wow");
    Relation<int> res;
    return 0;
}