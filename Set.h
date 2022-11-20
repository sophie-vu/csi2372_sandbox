#pragma once
#define MAX_CARD 1000 

template <class T, class U> class Set {
private:
	int card; // Number of elements
	T *elements; // Array of elements in the set
	int capacity; // Capacity
public:
	Set(); // Default constructor
	Set(const Set& s); // Copy constructor
	~Set(); // Destructor
	int cardinality(); // Returns the cardinality
	void add_element(T elem); // Adds an element to the set
	void remove_element(T elem); // Removes an element in the set
	int get_item(int idx); // Returns the element at a given index
	bool is_member(T elem); // Checks if an element is a member of the set
	bool equal(const Set s); // Checks if two sets are equal
	bool subset(const Set s); // Checks if a set is a subset of this one
	Set& operator=(const Set s); // Assignment operator
	Set Union(const Set s); // Returns the union of the current set and a given set
	Set intersection(const Set s); // Returns the intersection the current set and a given set
	Set difference(const Set s); // Returns the different between the current set and a given set
	Set mutual_difference(const Set s); // Returns the mutual difference between the current set and a given set
};