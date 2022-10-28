#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

Node* head;
Node* first;
Node* tmp;
Node* tail;
int i = 0; 

DoubleLinkedList::DoubleLinkedList() {
    head = NULL, first = NULL, tmp = NULL, tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList() {
    while (head->next != head) {
        Node* tmp = head->next;
        tmp->next->prev = head;
        head->next = tmp->next;
        delete tmp;
    }
    delete head;
    i = 0;
}

void DoubleLinkedList::add_to_front(int data) {
    Node *ptr = (Node*) malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL) { // If empty list
        head = ptr;
        first = head;
        tail = head;
    } else {
        tmp = ptr;
        first->next = tmp;
        tmp->prev = first;
        first = tmp;
        tail = tmp;
    }
    i++;
}

void DoubleLinkedList::add_to_back(int data) {
    Node *ptr = (Node*) malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (head == NULL) { // If empty list
        first = ptr;
        first = head;
        tail = head;
    } else {
        tmp = ptr;
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
    i++;
}

void DoubleLinkedList::insert_item(int pos, int data) {
    if (pos < 1 || pos > i + 1) {
        cout << "Enter a valid position\n";
    } else if (pos == 1) {
        add_to_front(data);
    } else if (pos == i + 1) {
        add_to_back(data);
    } else {
        Node* dlt = head;
        while (pos--) {
            dlt = dlt->next;
        }
        Node** a, **b;
        Node* ptr = (Node*) malloc(sizeof(Node));
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->data = data;
        b = &dlt;
        a = &(dlt->prev);
        ptr->next = (*b);
        ptr->prev = (*a);
        (*a)->next = ptr;
        (*b)->prev = ptr;
        i++;
    }
}

void DoubleLinkedList::remove_from_front() {
    head = head->next;
    i--;
}

void DoubleLinkedList::remove_from_back() {
    tail = tail->prev;
    tail->next = NULL;
    i--;
}

void DoubleLinkedList::remove_item(int pos) {
    if (pos < 1 || pos > i + 1) {
        cout << "Enter a valid position" << endl;
    } else if (pos == 1) {
        remove_from_front();
    } else if (pos == i) {
        remove_from_back();
    } else {
        Node* dlt = head;
        pos--;
        while (pos--) {
            dlt = dlt->next;
        }
        Node** prev, **after;
        prev = &(dlt->prev);
        after = &(dlt->next);
        (*prev)->next = (*after);
        (*after)->prev = (*prev);
        i--;
    }
}

ostream& operator<<(ostream& os, const DoubleLinkedList d) {
    Node* ptr = head;
    while (ptr != NULL) {
        os << ptr->data << " ";
        ptr = ptr->next;
    }
    return os;
}

Node* DoubleLinkedList::operator[](int pos) {
    if (pos < 0 || pos > i) {
        cout << "Enter a valid position." << endl;
        return NULL;
    } else if (pos == 0) {
        return head;
    } else if (pos == i + 1) {
        return tail;
    } else {
        Node* res = new Node();
        pos--;
        while (pos > 1) {
            res = first->next;
            pos--;
        }
        return res;
    }
}
