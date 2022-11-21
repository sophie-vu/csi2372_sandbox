#pragma once
#include <iostream>
#include "Set.h"
using namespace std;

template <class T> struct Pair {
    T first, second;
};

template <class T> class Relation {
    private:
        int card;
        Set<T> root;
        Pair<T>* elements;
        int capacity;
    public:
        Relation(); // Default constructor
        Relation(const Relation&); // Copy constructor
        ~Relation(); // Destructor
        int cardinality(); // Returns the number of pairs
        bool add_element(Pair<T> p); // Adds a pair
        void remove_element(T t); // Removes an element
        bool is_member(T t); // Checks if an element is present
        bool subset(Relation r); // Checks if a relation is a subset
        bool operator==(Relation &r); // Comparison operator
        T operator[](int); // Index operator
        bool reflexive(); // Checks if reflexive relation
        bool irreflexive(); // Checks if irreflexive relation
        bool symmetric(); // Checks if symmetric relation
        bool asymmetric(); // Checks if asymmetric relation
        bool transitive(); // Checks if transitive relation
        bool is_function(); // Checks if function relation
        friend ostream& operator<<(ostream& out, Relation r); // Printing operator
        Relation combination(Relation); // Returns the combination of 2 relations
};