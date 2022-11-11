#include "DoubleLinkedList.cpp"
#include <iostream>
using namespace std;

int main() {
    DoubleLinkedList d;
    d.insert_back(0);
    d.insert_front(1);
    // cout << d.getHead() << endl;
    //     cout << d.getTail() << endl;
        d.delete_list(0);
cout << d.getTail() << endl;
    return 0;
}