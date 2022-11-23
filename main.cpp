#include "Relation.cpp"
#include <iostream>
using namespace std;

int main() {
    Set<string> s;
    Relation<string> res;
    string str = "string";
    s.add_element(str);
    s.add_element("wow");
    for (int i = 0; i < s.cardinality(); i++) {
        cout << s.get_item(i) << endl;
    }
    return 0;
}