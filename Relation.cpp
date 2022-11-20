#include <iostream>
#include "Relation.h"
#include "Set.h"
#include <string>
using namespace std;

/**
 * @brief Default constructor
 * 
 */
Relation::Relation() {
	this->size = 0;
	this->capacity = 0;
	this->elements = new Pair[MAX_CARD];
	if (this->elements == NULL) {
		cout << "Not enough memory for this set!" << endl;
    } else {
		this->capacity = MAX_CARD;
    }
}

/**
 * @brief Copy constructor
 * 
 * @param r 
 */
Relation::Relation(const Relation& r) {
	int i;
	this->size = 0;
	this->capacity = 0;
	this->elements = new Pair[r.capacity];
	if (this->elements == NULL) {
		cout << "Not enough memory!" << endl;
    } else {
		this->capacity = r.capacity;
		this->size = r.size;
		this->root = r.root;
		for (i = 0; i < r.size; i++)
			this->elements[i] = r.elements[i];
	}
}

/**
 * @brief Destructor
 * 
 */
Relation::~Relation() {
	delete[] elements;
}

/**
 * @brief Returns the number of pairs
 * 
 * @return int 
 */
int Relation::cardinality() {
	return this->size;
}

/**
 * @brief Adds a pair into the relation
 * 
 * @param elemb
 */
void Relation::add_element(Pair elem) {
    elements[size] = elem;
    size++;
}

/**
 * @brief Checks if an element is a member of the relation
 * 
 * @param elem 
 * @return true 
 * @return false 
 */
bool Relation::is_member(int elem) {
	int i;
	for (i = 0; i < size; i++) {
		if (elements[i].first == elem || elements[i].second == elem) {
            return true;
        }
    }
	return false;
}

/**
 * @brief Removes an element from the relation
 * 
 * @param elem 
 */
void Relation::remove_element(int elem) {
	int i, pos = -1;
	for (i = 0; i < size; i++) {
		if (elements[i].first == elem || elements[i].second == elem) {
			pos = i;
			break;
		}
	}
	if (pos != -1) {
		for (i = pos; i < size; i++) {
			elements[i] = elements[i + 1];
        }
		size--;
	}
}

/**
 * @brief Checks if the relation is reflexive
 * 
 * @return true 
 * @return false 
 */
bool Relation::reflexive() {
	int i;
	for (i = 0; i < root.cardinality(); i++) {
		Pair p;
		p.first = p.second = root.get_item(i);
		if (!is_member(p.first) && !is_member(p.second)) {
			return false;
        }
	}
	return true;
}

/**
 * @brief Checks if the relation is irreflexive
 * 
 * @return true 
 * @return false 
 */
bool Relation::irreflexive() {
	int i;
	for (i = 0; i < root.cardinality(); i++) {
		Pair p;
		p.first = p.second = root.get_item(i);
		if (is_member(p.first) || is_member(p.second)) {
			return false;
        }
	}
	return true;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Relation::symmetric() {
	int i;
	for (i = 0; i < size; ++i) {
		Pair p;
		p.first = elements[i].second;
		p.second = elements[i].first;
		if (!is_member(p.first) || !is_member(p.second)) {
			return false;
        }
	}
	return true;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Relation::asymmetric() {
	int i;
	for (i = 0; i < size; ++i) {
		if (elements[i].first != elements[i].second) {
			Pair p;
			p.first = elements[i].second;
			p.second = elements[i].first;
			if (is_member(p.first) || is_member(p.second)) {
				return false;
            }
		}
	}
	return true;
}

/**
 * @brief Checks if the relation is transitive
 * 
 * @return true 
 * @return false 
 */
bool Relation::transitive() {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; ++j) {
			if (elements[i].second == elements[j].first) {
				Pair p;
				p.first = elements[i].first;
				p.second = elements[j].second;
				if (!is_member(p.first) && !is_member(p.second)) {
					return false;
                }
			}
		}
	}
	return true;
}

/**
 * @brief Checks if the relation is a function
 * 
 * @return true 
 * @return false 
 */
bool Relation::is_function() {
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size; ++j) {
			if (elements[i].first == elements[j].first && elements[i].second != elements[j].second) {
				return false;
            }
		}
	}

	return true;
}

/**
 * @brief Returns the inverse of the relation
 * 
 * @return Relation 
 */
Relation Relation::inverse() {
	int i;
	Relation r;
	// for (i = 0; i < root.cardinality(); i++)
	// 	r.add_to_set(root.get_item(i));

	for (i = 0; i < size; i++) {
		Pair p;
		p.first = elements[i].second;
		p.second = elements[i].first;
		r.add_element(p);
	}
	return r;
}

Relation Relation::combination(Relation r)
{
	int i, j;
	Relation result("res");
	for (i = 0; i < root.cardinality(); ++i)
		result.add_to_set(root.get_item(i));

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < r.size; ++j)
		{
			if (elements[i].second == r.elements[j].first)
			{
				Pair p;
				p.first = elements[i].first;
				p.second = r.elements[j].second;
				result.add_element(p);
			}
		}
	}

	return result;
}

ostream& operator<<(ostream& out, Relation& r) {
	int i;
	cout << "{ ";
	for (i = 0; i < r.size; ++i) {
		if (i != 0) cout << ", ";
		cout << "(" << r.elements[i].first << ", " << r.elements[i].second << ")";
	}
	cout << " }";
}