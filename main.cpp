#include <iostream>
#include "DoubleLinkedList.cpp"
using namespace std;
  
int main() {
    DoubleLinkedList d = *new DoubleLinkedList();
    d.add_to_front(99);
    d.add_to_front(88);
    d.add_to_back(77);
    d.remove_from_front();
    d.remove_item(1);
    cout << d << endl;
    return 0;
}