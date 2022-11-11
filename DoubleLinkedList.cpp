#include "DoubleLinkedList.h"

/**
 * @brief Construct a new Double Linked List:: Double Linked List object
 * 
 */
DoubleLinkedList::DoubleLinkedList() {
    head = new Node(); // Init head
    head->next = head->prev = head; // Empty list
}

/**
 * @brief Construct a new Double Linked List:: Double Linked List object
 * 
 * @param d 
 */
DoubleLinkedList::DoubleLinkedList(DoubleLinkedList& d) {
    copy_list(d.head, head);
}

/**
 * @brief Destroy the Double Linked List:: Double Linked List object
 * 
 */
DoubleLinkedList::~DoubleLinkedList() {
    delete_list(head);
}

void DoubleLinkedList::insert_front(const int &data) {
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = head->next;
    tmp->prev = head;
    tmp->next->prev = tmp;
    tmp->prev->next = tmp;
}

void DoubleLinkedList::remove_front(const int &data) {
    Node *tmp = head->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->next;
    delete tmp;
}

/**
 * @brief Insert a new Node at the back of the list.
 * 
 * @param data 
 */
void DoubleLinkedList::insert_back(const int &data) {
    Node *tmp = new Node(); // Init temp node
    tmp->data = data; 
    tmp->next = head; // Circular list
    tmp->prev = head->prev; // Set the new node's prev as the current tail
    tmp->next->prev = tmp; // Set the head's prev to the new node
    tmp->prev->next = tmp; // 
}

/**
 * @brief Delete the Node at the back of the list.
 * 
 * @param data 
 */
void DoubleLinkedList::remove_back(const int &data) {
    Node *tmp = head->prev;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
}

/**
 * @brief Return the value of the front of the list.
 * 
 * @return int 
 */
int DoubleLinkedList::getHead() {
    return head->next->data;
}

/**
 * @brief Return the value of the back of the list.
 * 
 * @return int 
 */
int DoubleLinkedList::getTail() {
    return head->prev->data;
}

/**
 * @brief Remove all occurances of nodes with a specified data.
 * 
 * @param data 
 */
void DoubleLinkedList::remove(int data) {
    Node *tmp = new Node();
    while (tmp != head) {
        Node *next = tmp->next;
        if (tmp->data == data) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
        }
        tmp = next;
    }
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList &d) {
    if (this == &d) {
        return *this;
    }
    delete_list(head);
    copy_list(d.head, head);
    return *this;
}

bool DoubleLinkedList::isEmpty() {
    return head->next == head;
}

/**
 * @brief Delete the list.
 * 
 * @param head 
 */
void DoubleLinkedList::delete_list(Node *head) {
    Node *tmp = head->next;
    while (tmp != head) {
        Node *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    delete head;
}

/**
 * @brief Copy a list.
 * 
 * @param from 
 * @param to 
 */
void DoubleLinkedList::copy_list(const Node *from, Node *&to) {
    to = new Node(); 
    to->next = to->prev = to;
    for (Node *tmp = from->next; tmp != from; tmp = tmp->next) {
        Node *t = new Node();
        t->data = tmp->data;
        t->next = to;
        t->prev = to->prev;
        t->prev->next = t;
        t->next->prev = t;
    }
}

