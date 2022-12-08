#include "graph.cpp"
#include <iostream>
using namespace std;

class Tree : private Graph {
    public:
        Tree();
        void insert_node(int);
        void remove_node(int);
        Node* search(int);
        Node* get_root();
        int get_max_depth(Node*);
        int get_height();
        void print();

    private:
        Node* root;
        LinkedList lst;
        void print_tree(Node*, int);
};

// Create a forest by cutting off root from tree 