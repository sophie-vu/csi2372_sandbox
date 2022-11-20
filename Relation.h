#pragma once
#include <iostream>
#include "Set.h"
using namespace std;
struct Pair {
    int first, second;
};

class Relation {
    private:
        Pair* elements;
        int size;
        int capacity;
        Set root;

    public:
        Relation(); // Default constructor
        Relation(const Relation& r); // Copy constructor
        ~Relation(); // Destructor
        int cardinality(); // Returns number of pairs
        void add_element(Pair elem); // Adds a pair into the relation
        void remove_element(int elem); // Removes an element from the relation
        bool is_member(int elem); // Checks if an element is in the relation
        bool operator==(Relation& r); // Checks if two relation are equal
        void operator[](int idx); // Return the list of elements that the given index mapped to
        bool reflexive(); // Checks if the relation is reflexive
        bool irreflexive(); // Checks if the relation is irreflexive
        bool symmetric(); // Check if the relation is symmetric
        bool asymmetric(); // Check if the relation is asymmetric
        bool transitive(); // Check if the relation is transitive
        bool is_function(); // Check if the relation is a function
        friend ostream& operator<<(ostream& out, Relation& r);
        Relation inverse(); // Returns the inverse 
        friend Relation combination(Relation& r1, Relation& r2); // Returns the combination of two relations
}; 

/*

#pragma once

#include <iostream>
#include <string>
#include "Set.h"

using namespace std;

struct Pair
{
	int first;
	int second;
};

class Relation
{
private:
	int size;
	Set root;
	Pair* elements;
	int capacity;
public:
	Relation(string);
	Relation(const Relation&);
	~Relation();//Destructor
	int cardinality();
	bool add_to_set(int);
	bool add_element(Pair);
	void remove_element(Pair);
	bool is_member(Pair);
	bool equal(Relation);
	bool subset(Relation);
	bool reflexive();
	bool irreflexive();
	bool symmetric();
	bool asymmetric();
	bool transitive();
	bool is_function();
	Relation inverse();
	Relation combination(Relation);
	Relation& operator=(Relation);
	void print();
};

*/