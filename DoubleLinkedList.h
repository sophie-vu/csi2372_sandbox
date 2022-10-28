#include <iostream>
using namespace std;

typedef struct Node {
	friend class DoubleLinkedList;
    public:
        int data;
        Node* next;
        Node* prev;
} Node;

class DoubleLinkedList {
    public:
        Node* head;
        Node* first;
        Node* tmp;
        Node* tail;
        int i = 0; 
        DoubleLinkedList(); // Init pointers
        ~DoubleLinkedList(); // Release all memories allocaed for nodes
        void add_to_front(int data); // Add an elem to the beginning
        void add_to_back(int data); // Add an elem to the end
        void insert_item(int pos, int data); // Insert an elem at given prev node
        void remove_item(int pos); // Remove an elem at given index
        void remove_from_front(); // Remove first elem
        void remove_from_back(); // Remove last elem
        int operator[](int pos); // Indexing
        friend ostream& operator<<(ostream& os, DoubleLinkedList& d); // Printing
        int count_nodes(); 
};