#pragma once
#define MAX_CARD 1000
template <class T> class Set {
private:
	int card; // Number of elements
	T* elements[MAX_CARD]; // Array for the elements
    int capacity; // Capacity of array
public:
	Set(); // Default constructor
	Set(const Set&); // Copy constructor
	int cardinality(); // Returns the number of elements
	bool add_element(T); // Adds an element
	void remove_element(T); // Removes an element
	bool is_member(T); // Checks if an element is in the set
	bool operator==(Set); // Comparison operator
	bool subset(Set); // Checks if a set is a subset
	Set Union(Set); // Returns the union of 2 sets
	Set intersection(Set); // Returns the intersection of 2 sets
	Set difference(Set); // Returns the difference of 2 sets
	Set mutual_difference(Set); // Returns the mutual difference of 2 sets
};