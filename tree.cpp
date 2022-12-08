#include "tree.h"
#include <iostream>
#include <ostream>
#include <iomanip>
using namespace std;
/**
 * @brief Constructor calls Graph base class with param 0
 * 
 */
Tree::Tree() : Graph(0) {
    root = NULL;
}

/**
 * @brief Inserts a new leaf node / creates a new tree if empty
 *        (smaller values go left and higher elements go right)
 * 
 * @param val 
 */
void Tree::insert_node(int val) {
    Node* new_node = new Node;
    Node* parent;
    new_node->val = val;
    new_node->next = NULL; // Left
    new_node->prev = NULL; // Right
    parent = NULL;

    if (root == NULL) { // Check if new tree
        root = new_node;
    } else { // Inserts leaf node if empty
        Node* curr;
        curr = root;
        while (curr) { // Find parent node
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

/**
 * @brief Removes a node of a given value
 * 
 * @param val 
 */
void Tree::remove_node(int val) {
    bool found = false;
    if (root == NULL) { // Checks if is empty
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
    if (case1 || case2) { // Removing node with 1 child
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
    if (case3) { // Removing a leaf node
        if (parent->next == curr) {
            parent->next = NULL;
        } else {
            parent->prev = NULL;
        }
        delete curr;
        return;
    }
    if (case4) { // Removing a node with 2 children -> replace node with smallest value in right subtree
        Node* child_right;
        child_right = curr->prev;
        if (child_right->next == NULL & child_right->prev == NULL) {
            curr = child_right;
            delete child_right;
            curr->prev = NULL;
        } else { // Right child has children
            if ((curr->prev)->next != NULL) { // Has a left child
                Node* left_curr;
                Node* lcurr_p;
                left_curr = (curr->prev)->next;
                lcurr_p = curr->prev;
                while (left_curr->next != NULL) {
                    lcurr_p = left_curr;
                    left_curr = left_curr->next;
                }
                curr->val = left_curr->val;
                delete left_curr;
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

void Tree::print() {
    print_tree(root, 0);
}

void Tree::print_tree(Node* leaf, int indent) {
    if (leaf != NULL) {
        if (leaf->prev) print_tree(leaf->prev, indent + 4);
        if (leaf->next) print_tree(leaf->next, indent + 4);
        if (indent) {
            cout << setw(indent) << "---";
        }
        cout << leaf->val << "\n ";
    }
}  