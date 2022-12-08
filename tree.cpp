#include "tree.h"
#include <iostream>
#include <ostream>
using namespace std;
Tree::Tree() : Graph(0) {
    root = NULL;
    lst = LinkedList();
}

void Tree::insert_node(int val) {
    Node* new_node = new Node;
    Node* parent;
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;
    parent = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        Node* curr;
        curr = root;
        while (curr) {
            parent = curr;
            if (new_node->val > curr->val) {
                curr = curr->prev;
            } else {
                curr = curr->next;
            }
        }
        if (new_node->val < parent->val) {
            parent->next = new_node;
        } else {
            parent->prev = new_node;
        }
    }
}

void Tree::remove_node(int val) {
    bool found = false;
    if (root == NULL) {
        cout << "Tree is already empty." << endl;
        return;
    }
    Node* curr;
    Node* parent;
    curr = root;
    while (curr != NULL) {
        if (curr->val == val) {
            found = true;
            break;
        } else {
            parent = curr;
            if (val > curr->val) {
                curr = curr->prev;
            } else {
                curr = curr->next;
            }
        }
    }
    if (!found) {
        cout << "No value found in true." << endl;
        return;
    }
    bool case1 = (curr->next == NULL && curr->prev != NULL);
    bool case2 = (curr->next != NULL && curr->prev == NULL);
    bool case3 = (curr->next == NULL && curr->prev == NULL);
    bool case4 = (curr->next != NULL && curr->prev != NULL);
    if (case1 || case2) {
        if (case1) {
            if (parent->next == curr) {
                parent->next = curr->prev;
                delete curr;
            } else {
                parent->prev = curr->next;
                delete curr;
            }
        }
        return;
    }
    if (case3) {
        if (parent->next == curr) {
            parent->next = NULL;
        } else {
            parent->prev = NULL;
        }
        delete curr;
        return;
    }
    if (case4) {
        Node* child;
        child = curr->prev;
        if (child->next == NULL & child->prev == NULL) {
            curr = child;
            delete child;
            curr->prev = NULL;
        } else {
            if (curr->prev->next != NULL) {
                Node* lcurr;
                Node* lcurr_p;
                lcurr = curr->prev->next;
                while (lcurr->next != NULL) {
                    lcurr_p = lcurr;
                    lcurr = lcurr->next;
                }
                curr->val = lcurr->val;
                delete lcurr;
                lcurr_p->next = NULL;
            } else {
                Node* tmp;
                tmp = curr->prev;
                curr->val = tmp->val;
                curr->prev= tmp->prev;
                delete tmp;
            }
        }
        return;
    }
}

