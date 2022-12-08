#include <iostream>
#include "linkedlist.cpp"
#include <stack>
using namespace std;

class Graph {
    public:
        LinkedList* list;
        int num_vertices;
    public:
        Graph(int);
        ~Graph();
        void add_directed_edge(int, int);
        void add_undirected_edge(int, int);
        void remove_directed_edge(int, int);
        void print();
        void visit(int, bool[], stack<int>&);
        bool is_cyclic();
        bool check_vertices(int, bool[], bool[]);
};