#include "tree.h"
#include <cmath>
using namespace std;

Tree::Tree() {
    root = NULL;
    // root->next = root->prev = NULL;
    // root->is_directed = true;
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

void Tree::insert_node(int val) {
    Node n;
    n.val = val;
    if (root == NULL) {
        cout << "goes here" << endl;
        root = &n;
        return;
    } else {
        LinkedList lst;
        lst.insert_directed_edge_at_end(root);
        while (true) {
            Node node = *lst.tail;
            lst.delete_last();
            if (node.next != NULL && node.prev != NULL) { // Node has both left + right child -> add to list
                lst.insert_directed_edge_at_end(node.next);
                lst.insert_directed_edge_at_end(node.prev);
            } else {
                if (node.next == NULL) {
                    node.next = &n;
                    lst.insert_directed_edge_at_end(node.next);
                } else {
                    node.prev = &n;
                    lst.insert_directed_edge_at_end(node.prev);
                }
                break;
            }

        }
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

Node* Tree::get_root() {
    return root;
}

int Tree::get_max_depth(Node* node) {
    cout << "Node: " << node << endl;
    if (node == NULL) return 0;
    int left = get_max_depth(node->next);
    cout << "calculate left max dept " << left << endl;
    int right = get_max_depth(node->prev);
    cout << "calculate right max dept " << right << endl;
    return max(left + 1, right + 1);
}

int Tree::get_height() {
    return get_max_depth(root);
}