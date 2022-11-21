#include <algorithm>
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
 }

/**
 * @brief Copy constructor
 * 
 * @tparam T 
 */
 template <class T> Set<T>::Set(const Set& s) {
    elements = new T[s.capacity];
    if (elements == NULL) {
        cout << "Memory error." << endl;
    } else {
        capacity = s.capacity;
        card = s.card;
    }
    for (int i = 0; i < s.card; i++) {
        elements[i] = s.elements[i];
    }
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
 * @brief Adds an element if it is not present already
 * 
 * @tparam T 
 * @param t 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::add_element(T t) {
    if (card > MAX_CARD) { // Cannot add
        return false;
    } else if (card == capacity) {
        T *tmp;
        tmp = new T[capacity + MAX_CARD / 2];
        if (tmp == NULL) {
            cout << "Memory error." << endl;
            return false;
        }
        for (int i =0; i < card; i++) {
            tmp[i] = elements[i];
        }
        delete[] elements;
        elements = tmp;
        capacity = capacity + MAX_CARD / 2;
        card++;
        return true;
    } else {
        for (int i = 0; i < card; i++) {
            if (elements[i] == t) { // Element already present
                return true;
            }
        }
        elements[card++] = t;;
        return true;
    }
}

/**
 * @brief Removes an element if it is present
 * 
 * @tparam T 
 * @param t 
 */
template <class T> void Set<T>::remove_element(T t) {
    int pos = -1;
    for (int i = 0; i < card; i++) {
        if (elements[i] == t) {
            pos = i;
            break;
        }
    }
    if (pos > -1) {
        for (int i = pos; i < card; i++) {
            elements[i] = elements[i + 1];
        }
        card--;
    }
}

/**
 * @brief Checks if an element is in the set
 * 
 * @tparam T 
 * @param t 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::is_member(T t) {
    for (int i = 0; i < card; i ++) {
        if (elements[i] == t) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Comparison operator
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::operator==(Set s) {
    return (subset(s) && s.subset(*this));
} 

/**
 * @brief Checks if a set is a subset
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Set<T>::subset(Set s) {
    for (int i = 0; i < card; i++) {
        if (!s.is_member(elements[i])) { // If element is not present in other set
            return false;
        }
    }
}

/**
 * @brief Returns the union of 2 sets
 * 
 * @tparam T 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::Union(Set s) {
    Set tmp;
    for (int i = 0; i < card; i++) {
        tmp.add_element(elements[i]);
    }
    for (int j = 0; j < s.card; j++) {
        tmp.add_element(s.elements[j]);
    }
    return tmp;
}

/**
 * @brief Returns the intersection of 2 sets
 * 
 * @tparam T 
 * @param s 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::intersection(Set s) {
    Set tmp;
    for (int i = 0; i < card; i++) {
        if (s.is_member(elements[i])) {
            tmp.add_element(elements[i]);
        }
    }
    return tmp;
} 

/**
 * @brief Returns the difference of 2 sets
 * 
 * @tparam T 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::difference(Set s) {
    Set tmp;
    for (int i = 0; i < card; i++) {
        if (!s.is_member(elements[i])) {
            tmp.add_element(elements[i]);
        }
    }
    return tmp;
}

/**
 * @brief Returns the mutual difference of 2 sets
 * 
 * @tparam T 
 * @return Set<T> 
 */
template <class T> Set<T> Set<T>::mutual_difference(Set s) {
    Set s1 = difference(s);
    Set s2 = s.difference(*this);
    return s1.Union(s2);
}
