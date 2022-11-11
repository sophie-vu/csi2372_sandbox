#pragma once
#include <iostream>
using namespace std;

struct Node {
    struct Node *prev;
    struct Node *next;
    int data;
};

 class DoubleLinkedList {
    private:
        Node *head;
        Node *tail;
    public:
        DoubleLinkedList();
        DoubleLinkedList(DoubleLinkedList& d);
        ~DoubleLinkedList();
        void insert_front(const int &data);
        void remove_front(const int &data);
        void insert_back(const int &data);
        void remove_back(const int &data);
        int getHead();
        int getTail();
        DoubleLinkedList& operator=(const DoubleLinkedList &d);
        bool isEmpty();
        void print();
        void remove(int);
        void delete_list(Node*);
        void copy_list(const Node*, Node *&);
 };