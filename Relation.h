/**
 * @file Relation.h
 * @author svu043@uottawa.ca
 * @brief Relation class inspired by Lab 2 Solution
 * 
 */
#pragma once
#include <iostream>
#include <string>
#include "Set.h"
using namespace std;

template <class T> struct Pair {
	T first;
	T second;
};

template <class T> class Relation {
private:
	int size; // Number of pairs
	Set<T> root; 
	Pair<T>* elements; // Array of pairs 
	int capacity; 
public:
	Relation(); // User constructor
	Relation(const Relation&); // Copy constructor
	~Relation(); //Destructor
	int cardinality(); // Returns the number of pairs
	bool add_to_set(T); // Adds to root set
	bool add_element(Pair<T>); // Adds to the end of the array
	void remove_element(Pair<T>); // Removes a given pair
    T get_item(int); // Returns the element at a given index
	bool is_member(Pair<T>); // Checks if an element is in the array
	bool equal(Relation); // Checks for equal
	bool subset(Relation); // Checks for a given subset
	bool reflexive(); // Checks if reflexive
	bool irreflexive(); // Checks if irreflexive
	bool symmetric(); // Checks if symmetric
	bool asymmetric(); // Checks if asymmetric
	bool transitive(); // Checks if transitive
	bool is_function(); // Checks if a function
	Relation inverse(); // Reverses the relation
	Relation combination(Relation); // Combines the relation with another
	Relation& operator=(Relation); // Reassigns the relation
	void print(); // Print operator
};