/**
 * @file Set.cpp
 * @author svu043@uottawa.ca
 * @brief Set implementation inspired by Lab 2 Solution
 * 
 */
#include <iostream>
#include "Set.h"
using namespace std;

/**
 * @brief Default constructor
 * 
 * @tparam T 
 */
template <class T> Set<T>::Set() {
	card = 0;
	capacity = 0;
	elements = new T[MAX_CARD];
	if (elements == NULL) {
		cout << "Not enough memory for this set!" << endl;
    } else {
		capacity = MAX_CARD;
    }
}

/**
 * @brief Copy constructor
 * 
 * @tparam T 
 * @param s 
 */
template <class T> Set<T>::Set(const Set& s) {
	int i;
	card = s.card;
	elements = new int[s.capacity];
	if (elements == NULL) {
		cout << "Not enough memory!" << endl;
    } else {
		capacity = s.capacity;
		card = s.card;		
	}
	for (i = 0; i < s.card; i++) {
		elements[i] = s.elements[i];
    }
}

/**
 * @brief Assignment operator
 * 
 * @tparam T 
 * @param s 
 * @return Set<T>& 
 */
template <class T> Set<T>& Set<T>::operator=(Set s) {
	int i;
	T* temp;
	temp = new T[s.capacity];
	if (temp == NULL) {
		cout << "Not enough memory!" << endl;
    } else {
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
 * @brief Destructor
 * 
 * @tparam T 
 */
template <class T> Set<T>::~Set() {
	delete[] elements;
}

/**
 * @brief Returns the number of elements
 * 
 * @tparam T 
 * @return int 
 */
template <class T> int Set<T>::cardinality() {
	return card;
}

/**
 * @brief Checks if an elements is in the array
 * 
 * @tparam T 
 * @param x 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::is_member(T x) {
	int i;
	for (i = 0; i < card; i++) {
		if (elements[i] == x) return true;
    }
	return false;
}

/**
 * @brief Returns the element at a given array
 * 
 * @tparam T 
 * @param index 
 * @return T 
 */
template <class T> T Set<T>::get_item(int index) {
	if (index >= 0 && index < card) {
		return elements[index];
    }
	cout << "Index out of Range!" << endl;
	return NULL; //just a default
}

/**
 * @brief Adds an element at the end of the array
 * 
 * @tparam T 
 * @param x 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::add_element(T x) {
	int i;
	if (card >= MAX_CARD) {
		return false;
    }
	if (card == capacity) {
		int new_cap = capacity + MAX_CARD / 2;
		T *temp;
		temp = new T[new_cap];
		if (temp == NULL) {
			cout << "Not Enough Memory" << endl;
			return false;
		}
		for (i = 0; i < card; ++i) {
			temp[i] = elements[i];
        }
		delete [] elements;
		elements = temp;
		capacity = new_cap;
		card++;
		return true;
	}
	
	for (i = 0; i < card; i++) {
		if (elements[i] == x) return true;
    }
	elements[card++] = x;
	return true;
}

/**
 * @brief Removes a given element in the array
 * 
 * @tparam T 
 * @param x 
 */
template <class T> void Set<T>::remove_element(T x) {
	int i, p = -1;
	for (i = 0; i < card; i++) {
		if (elements[i] == x) { 
			p = i;
			break;
		}
	}

	if (p != -1) {
		for (i = p; i < card; i++) {
			elements[i] = elements[i + 1];
        }
		card--;
	}
}

/**
 * @brief 
 * 
 * @tparam T 
 * @param s 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::subset(Set s)
{
	int i;
	for (i = 0; i < card; ++i)
		if (!s.is_member(elements[i])) return false;

	return true;
}

/**
 * @brief Checks for a given subset
 * 
 * @tparam T 
 * @param s 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::equal(Set s) {
	if (subset(s) && s.subset(*this)) {
		return true;
    }
	return false;
}

/**
 * @brief Returns the union with a given set
 * 
 * @tparam T 
 * @param s 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::Union(Set s) {
	int i;
	Set result;
	for (i = 0; i < card; i++) {
		result.add_element(elements[i]);
    }

	for (i = 0; i < s.card; ++i) {
		result.add_element(s.elements[i]);
    }
	return result;
}

/**
 * @brief Returns the intersection with a given set
 * 
 * @tparam T 
 * @param s 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::intersection(Set s) {
	int i;
	Set result;
	for (i = 0; i < card; i++) {
		if (s.is_member(elements[i])) result.add_element(elements[i]);
    }
	return result;
}

/**
 * @brief Returns the difference with a given set
 * 
 * @tparam T 
 * @param s 
 * @return Set 
 */
template <class T> Set<T> Set<T>::difference(Set s) {
	int i;
	Set result;
	for (i = 0; i < card; i++) {
		if (!s.is_member(elements[i])) result.add_element(elements[i]);
    }
	return result;
}

/**
 * @brief Returns the mutual difference with a given set
 * 
 * @tparam T 
 * @param s 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::mutual_difference(Set s) {
	int i;
	Set s1 = difference(s);
	Set s2 = s.difference(*this);
	return s1.Union(s2);
}
