#include "graph.h"
#include <iostream>
class Tree {
    public:
        Tree(int);
        ~Tree();
        void insert(int);
        void destroy_tree();
        Node* remove(int);
        Node* search(int);
        Node* get_root();
        int get_max_depth();
        void print_tree(Node*);

    private:
        Node* root;
        void insert(int, Node*);
        Node* search(int, Node*);
        Node* get_min(Node*);
        Node* get_max(Node*);
        Node* remove(Node*, int);
        void destroy_tree(Node*);
        bool is_leaf_node(Node*);
        void print_tree(string, Node*, bool);
};

// Create a forest by cutting off root from tree 