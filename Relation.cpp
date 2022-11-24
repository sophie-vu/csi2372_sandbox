#include <iostream>
#include "Set.h"
#include "Relation.h"
#include <string>

using namespace std;
/**
 * @brief User constructor
 * 
 * @tparam T 
 * @param t 
 */
template <class T> Relation<T>::Relation() {
	size = 0;
	capacity = 0;
	elements = new Pair<T>[MAX_CARD];
	if (elements == NULL) {
		cout << "Not enough memory for this set!" << endl;
    } else {
		capacity = MAX_CARD;
    }
}

template <class T> Relation<T>::Relation(const Relation& r) {
	int i;
	size = 0;
	capacity = 0;
	elements = new Pair<T>[r.capacity];
	if (elements == NULL) {
		cout << "Not enough memory!" << endl;
    } else {
		capacity = r.capacity;
		size = r.size;
		root = r.root;
		for (i = 0; i < r.size; i++) {
			elements[i] = r.elements[i];
        }
	}
}

template <class T> Relation<T>& Relation<T>::operator=(Relation r)
{
	int i;
	Pair<T>* temp;
	size = 0;
	capacity = 0;
	temp = new Pair<T>[r.capacity];
	if (temp == NULL) {
		cout << "Not enough memory!" << endl;
    } else {
		capacity = r.capacity;
		size = r.size;
		root = r.root;
		for (i = 0; i < r.size; i++) {
			temp[i] = r.elements[i];
        }
		delete[] elements;
		elements = temp;
	}

	return (*this);
}

template <class T> Relation<T>::~Relation() {
	delete[] elements;
}


template <class T> int Relation<T>::cardinality() {
	return size;
}


template <class T> bool Relation<T>::is_member(Pair<T> p) {
	int i;
	for (i = 0; i < size; i++) {
		if (elements[i].first == p.first && elements[i].second == p.second) return true;
    }
	return false;
}


template <class T> bool Relation<T>::add_to_set(T x) {
	if (root.add_element(x)) {
		return true;
    }
	return false;
}


template <class T> T Relation<T>::get_item(int index) {
	if (index < size) {
		return elements[index];
    }
	cout << "Index out of Range!" << endl;
	return NULL;
}

template <class T> bool Relation<T>::add_element(Pair<T> p) {
	int i;
	if (!root.is_member(p.first) || !root.is_member(p.second)) {
		return false;
    }

	if (size == capacity) {
		int new_cap = capacity + MAX_CARD / 2;
		Pair<T>* temp;
		temp = new Pair<T>[new_cap];
		if (temp == NULL) {
			cout << "Not Enough Memory" << endl;
			return false;
		}
		for (i = 0; i < size; i++) {
			temp[i] = elements[i];
        }
		delete[] elements;
		elements = temp;
		capacity = new_cap;
	}

	for (i = 0; i < size; i++) {
		if (elements[i].first == p.first && elements[i].second == p.second) return true;
    }
	elements[size++] = p;
	return true;
}

template <class T> void Relation<T>::remove_element(Pair<T> p) {
	int i, pos = -1;
	for (i = 0; i < size; i++) {
		if (elements[i].first == p.first && elements[i].second == p.second) {
			pos = i;
			break;
		}
	}
	if (pos != -1) {
		for (i = pos; i < size; ++i) {
			elements[i] = elements[i + 1];
        }
		size--;
	}
}

template <class T> bool Relation<T>::subset(Relation r) {
	int i;
	for (i = 0; i < size; i++) {
		if (!r.is_member(elements[i])) return false;
    }

	return true;
}

template <class T> bool Relation<T>::equal(Relation r) {
	if (subset(r) && r.subset(*this)) {
		return true;
    }
	return false;
}

template <class T> bool Relation<T>::reflexive() {
	int i;
	for (i = 0; i < root.cardinality(); i++) {
		Pair<T> p;
		p.first = p.second = root.get_item(i);
		if (!is_member(p)) return false;
	}
	return true;
}

template <class T> bool Relation<T>::irreflexive() {
	int i;
	for (i = 0; i < root.cardinality(); i++) {
		Pair<T> p;
		p.first = p.second = root.get_item(i);
		if (is_member(p))
			return false;
	}
	return true;
}

template <class T> bool Relation<T>::symmetric() {
	int i;
	for (i = 0; i < size; i++) {
		Pair<T> p;
		p.first = elements[i].second;
		p.second = elements[i].first;
		if (!is_member(p)) return false;
	}
	return true;
}

template <class T> bool Relation<T>::asymmetric() {
	int i;
	for (i = 0; i < size; i++) {
		if (elements[i].first != elements[i].second) {
			Pair<T> p;
			p.first = elements[i].second;
			p.second = elements[i].first;
			if (is_member(p)) return false;
		}
	}

	return true;
}

template <class T> bool Relation<T>::transitive() {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (elements[i].second == elements[j].first) {
				Pair<T> p;
				p.first = elements[i].first;
				p.second = elements[j].second;
				if (!is_member(p)) return false;
			}
		}
	}
	return true;
}

template <class T> bool Relation<T>::is_function() {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (elements[i].first == elements[j].first && elements[i].second != elements[j].second)
				return false;
		}
	}

	return true;
}

template <class T> Relation<T> Relation<T>::inverse() {
	int i;
	Relation result("res");
	for (i = 0; i < root.cardinality(); i++) { 
		result.add_to_set(root.get_item(i));
    }
	for (i = 0; i < size; i++) {
		Pair<T> p;
		p.first = elements[i].second;
		p.second = elements[i].first;
		result.add_element(p);
	}
	return result;
}

template <class T> Relation<T> Relation<T>::combination(Relation r) {
	int i, j;
	Relation result("res");
	for (i = 0; i < root.cardinality(); i++) {
		result.add_to_set(root.get_item(i));
    }

	for (i = 0; i < size; i++) {
		for (j = 0; j < r.size; j++) {
			if (elements[i].second == r.elements[j].first) {
				Pair<T> p;
				p.first = elements[i].first;
				p.second = r.elements[j].second;
				result.add_element(p);
			}
		}
	}
	return result;
}

template <class T> void Relation<T>::print() {
	int i;
	cout << "{ ";
	for (i = 0; i < size; i++) {
		if (i != 0) cout << ", ";
		cout << "(" << elements[i].first << ", " << elements[i].second << ")";
	}
	cout << " }";
}