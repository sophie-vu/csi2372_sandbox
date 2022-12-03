#include "linkedlist.h"
#include <stddef.h>

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

LinkedList::~LinkedList() {
    Node* curr = head;
    while (head != NULL) {
        curr = curr->next;
        delete head;
        head = curr;
    }
    head = NULL;
    tail = NULL;
}

void LinkedList::insert_directed_edge_at_end(int val) {
    Node* new_node = new Node;
    new_node->val = val;
    new_node->is_directed = true;
    new_node->next = NULL;
    new_node->prev = tail;

    if (head == NULL) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

void LinkedList::insert_undirected_edge_at_end(int val) {
    Node* new_node = new Node;
    new_node->val = val;
    new_node->is_directed = false;
    new_node->next = NULL;
    new_node->prev = tail;

    if (head == NULL) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

bool LinkedList::delete_first() {
    if (head != NULL) {
        Node* delete_node = head;
        head = delete_node->next;
        delete delete_node;
        delete_node = NULL;
        size--;
        return true;
    } else {
        return false;
    }
}

bool LinkedList::delete_last() {
    if (tail != NULL) {
        Node* delete_node = tail;
        tail = delete_node->prev;
        delete delete_node;
        delete_node = NULL;
        size--;
        return true;
    } else {
        return false;
    }
}

bool LinkedList::delete_node(int val) {
    if (head != NULL) {
        if (head->val == val) {
            delete_first();
        } else if (tail->val == val) {
            delete_last();
        } else {
            Node* curr = head;
            Node* delete_node;
            while (curr != NULL) {
                delete_node = curr;
                if (curr->val == val) {
                    curr->prev->next = delete_node->next;
                    curr->next->prev = delete_node->prev;
                    delete delete_node;
                    delete_node = NULL;
                    size--;
                    return true;
                }
                curr = curr->next;
            }
        }
    }
    return false;
}