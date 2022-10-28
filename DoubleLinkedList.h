#include <iostream>
using namespace std;

struct Node {
	friend class DoubleLinkedList;
    public:
        int data;
        struct Node* next;
        struct Node* prev;
};

class DoubleLinkedList {
    public:
        DoubleLinkedList(); // Init pointers
        ~DoubleLinkedList(); // Release all memories allocaed for nodes
        void add_to_front(int data); // Add an elem to the beginning
        void add_to_back(int data); // Add an elem to the end
        void insert_item(int pos, int data); // Insert an elem at given prev node
        void remove_item(int pos); // Remove an elem at given index
        void remove_from_front(); // Remove first elem
        void remove_from_back(); // Remove last elem
        Node* operator[](int pos); // Indexing
        friend ostream& operator<<(ostream& os, const DoubleLinkedList d); // Printing
};