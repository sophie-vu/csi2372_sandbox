#include <iostream>
#include "Set.h"
using namespace std;

/**
 * @brief Default constructor
 * 
 */
template <class T, class U> Set<T, U>::Set() {
	this->card = 0;
	this->capacity = 0;
	this->elements = new T[MAX_CARD];
	if (this->elements == NULL) {
		cout << "Not enough memory for this set!" << endl;
	} else {
		this->capacity = MAX_CARD;
	}
}

/**
 * @brief Copy constructor
 * 
 * @param s 
 */
Set::Set(const Set& s) {
	int i;
	this->card = s.card;
	this->elements = new int[s.capacity];
	if (this->elements == NULL) {
		cout << "Not enough memory!" << endl;
	} else {
		this->capacity = s.capacity;
		this->card = s.card;	
	}
	for (i = 0; i < s.card; i++) {
		this->elements[i] = s.elements[i];
	}
}

/**
 * @brief Desctructor
 * 
 */
Set::~Set() {
	delete[] elements;
}

/**
 * @brief Returns the number of elements in the set
 * 
 * @return int 
 */
int Set::cardinality() {
	return this->card;
}

/**
 * @brief Adds an element to the set
 * 
 * @param e
 */
void Set::add_element(int e) {
	int i;
	if (card >= MAX_CARD) { // If reached max amount of elems
		return;
	}
	if (card == capacity) { // If reached capacity
		int new_cap = capacity + MAX_CARD / 2;
		int *temp;
		temp = new int[new_cap];
		if (temp == NULL) {
			cout << "Not Enough Memory" << endl;
			return;
		}
		for (i = 0; i < this->card; ++i) {
			temp[i] = elements[i];
		}
		delete [] elements;
		elements = temp;
		capacity = new_cap;
		card++;
	}
	
	for (i = 0; i < card; i++) {
		if (elements[i] == e) { 
			return;
		}
	}
	elements[card++] = e;
}

/**
 * @brief Removes an element in the set
 * 
 * @param x 
 */
void Set::remove_element(int e) {
	int i, p = -1; 

	for (i = 0; i < card; ++i) {
		if (elements[i] == e) { // Found element
			p = i;
			break;
		}
	}

	if (p != -1) {
		for (i = p; i < card; ++i) { // Elements to the right
			elements[i] = elements[i + 1];
		}
		card--;
	}
}

/**
 * @brief Returns an element at a given index
 * 
 * @param index 
 * @return int 
 */
int Set::get_item(int idx) {
	if (idx >= 0 && idx < card) {
		return elements[idx];
	}
	cout << "Index out of range!" << endl;
	return 0; // Default
}

/**
 * @brief Checks if an element is a member of the set
 * 
 * @param e 
 * @return true 
 * @return false 
 */
bool Set::is_member(int e) {
	int i;
	for (i = 0; i < card; ++i) {
		if (elements[i] == e) {
			return true;
		}
	}
	return false;
}

/**
 * @brief Checks if two sets are equal
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool Set::equal(Set s) {
	if (subset(s) && s.subset(*this)) {
		return true;
	}
	return false;
}

/**
 * @brief Checks if a set is a subset of this set
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool Set::subset(Set s) {
	int i;
	for (i = 0; i < card; ++i) {
		if (!s.is_member(elements[i])) { // If there is a missing element in the subset
			return false;
		}
	}
	return true;
}

/**
 * @brief Assignment operator
 * 
 * @param s 
 * @return Set& 
 */
Set& Set::operator=(Set s) {
	int i;
	int* temp;
	temp = new int[s.capacity];
	if (temp == NULL) {
		cout << "Not enough memory!" << endl;
	}
	else {
		capacity = s.capacity;
		card = s.card;
		for (i = 0; i < s.card; i++) {
			temp[i] = s.elements[i]; 
		}
		delete[] elements;
		elements = temp;
	}
	return *this;
}

/**
 * @brief Returns the union of the current set and a given set
 * 
 * @param s 
 * @return Set 
 */
Set Set::Union(Set s) {
	int i;
	Set result;
	for (i = 0; i < card; i++) {
		result.add_element(elements[i]);
	}
	for (i = 0; i < s.card; i++) {
		result.add_element(s.elements[i]);
	}
	return result;
}

/**
 * @brief Returns the intersection the current set and a given set
 * 
 * @param s 
 * @return Set 
 */
Set Set::intersection(Set s) {
	int i;
	Set result;
	for (i = 0; i < card; i++) {
		if (s.is_member(elements[i])) {
			result.add_element(elements[i]);
		}
	}
	return result;
}

/**
 * @brief Returns the different between the current set and a given set
 * 
 * @param s 
 * @return Set 
 */
Set Set::difference(Set s) {
	int i;
	Set result;
	for (i = 0; i < card; i++) {
		if (!s.is_member(elements[i])) {
			result.add_element(elements[i]);
		}
	}
	return result;
}

/**
 * @brief Returns the mutual different between the current set and a given set
 * 
 * @param s 
 * @return Set 
 */
Set Set::mutual_difference(Set s) {
	int i;
	Set s1 = difference(s);
	Set s2 = s.difference(*this);
	return s1.Union(s2);
}
