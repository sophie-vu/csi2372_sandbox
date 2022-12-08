#include <iostream>
using namespace std;
class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    bool is_directed;
    friend ostream& operator<<(ostream& out, Node n) {
        out << n.val;
        return out;
    }
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void insert_directed_edge_at_end(Node*);
        void insert_undirected_edge_at_end(Node*);
        Node* delete_first();
        Node* delete_last();
        Node* delete_node(Node*);
};