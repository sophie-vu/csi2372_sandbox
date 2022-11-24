/**
 * @file Set.h
 * @author svu043@uottawa.ca
 * @brief Set class inspired by Lab 2 Solution
 * 
 */
#pragma once

#define MAX_CARD 1000
template <class T> class Set {
private:
	int card; // Number of elements
	T *elements; // Array of elements
	int capacity;
public:
	Set(); // Default constructor
	Set(const Set&); // Copy constructor
	~Set(); // Desctructor
	int cardinality(); // Returns the number of elements
	bool add_element(T); // Adds an element into the array
	void remove_element(T); // Removes an element from the array
	T get_item(int); // Returns the element at a given index
	bool is_member(T); // Checks if an element is in the array
	bool equal(Set); // Checks if 2 sets are equal
	bool subset(Set); // Checks if a subset exists
	Set& operator=(Set); // Assignment operator
	Set Union(Set); // Returns the union
	Set intersection(Set); // Returns the intersection
	Set difference(Set); // Returns the difference
	Set mutual_difference(Set); // Returns the mutual difference
};