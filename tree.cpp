#include "tree.h"

Tree::Tree(int num) : Graph(num) {
    root = NULL;
}

Tree::~Tree() {
    destroy_tree();
}

void Tree::destroy_tree(Node* leaf) {
    if (leaf == NULL) {
        destroy_tree(leaf->next);
        destroy_tree(leaf->prev);
        delete leaf;
    }
}

void Tree::insert(int val, Node* leaf) {
    if (val < leaf->val) {
        if (leaf->next != NULL) {
            insert(val, leaf->next);
        } else {
            leaf->next = new Node;
            leaf->next->val = val;
            leaf->next->next = NULL;
        }
    } else if (val >= leaf->val) {
        if (leaf->prev != NULL) {
            insert(val, leaf->prev);
        } else {
            leaf->prev = new Node;
            leaf->prev->val = val;
            leaf->prev->prev = NULL;
            leaf->prev->next = NULL;
        }
    }
}

void Tree::insert(int val) {
    if (root != NULL) {
        insert(val, root);
    } else {
        root = new Node;
        root->val = val;
        root->prev = NULL;
        root->next = NULL;
    }
}

Node* Tree::search(int val, Node* leaf) {
    if (leaf != NULL) {
        if (val == leaf->val) {
            return leaf;
        }
        if (val < leaf->val) {
            return search(val, leaf->next);
        } else {
            return search(val, leaf->prev);
        }
    } else {
        return NULL;
    }
}

Node* Tree::search(int val) {
    return search(val, root);
}

void Tree::destroy_tree() {
    destroy_tree(root);
}

void Tree::print_tree(string prefix, Node* leaf, bool isNext) {
    if (leaf != NULL) {
        cout << prefix;
        cout << (isNext ? "├──" : "└──");
        cout << leaf->val << endl;
        string res = prefix + (isNext ? "│   " : "    ");
        print_tree(res, leaf->next, true);
        print_tree(res, leaf->prev, false);
    }
}

void Tree::print_tree(Node* leaf) {
    print_tree("", leaf, false);
}