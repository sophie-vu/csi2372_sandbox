#include "Relation.h"
#include "Set.cpp"
#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief Default constructor
 * 
 * @tparam T 
 */
template <class T> Relation<T>::Relation() {
    card = 0;
    elements = new Pair<T>[MAX_CARD];
    if (elements == NULL) {
        cout << "Memory error." << endl;
    } else {
        capacity = MAX_CARD;
    }
}

/**
 * @brief Copy constructor
 * 
 * @tparam T 
 * @param r 
 */
template <class T> Relation<T>::Relation(const Relation& r) {
    card = 0;
    elements = new Pair<T>[MAX_CARD];
    if (elements == NULL) {
        cout << "Memory error." << endl;
    } else {
        capacity = r.capacity;
        card = r.card;
        root = r.root;
        for (int i = 0; i < capacity; i++) {
            elements[i] = r.elements[i];
        }
    }
}
 
/**
 * @brief Destructor
 * 
 * @tparam T 
 */
template <class T> Relation<T>::~Relation() {
    delete[] elements;
}

/**
 * @brief Returns the number of pairs
 * 
 * @tparam T 
 * @return int 
 */
template <class T> int Relation<T>::cardinality() {
    return card;
}

/**
 * @brief Adds a pair
 * 
 * @tparam T 
 * @param p 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::add_element(Pair<T> p) {
    if (!is_member(p.first) || !is_member(p.second)) {
        return false;
    } else if (card == capacity) {
        Pair<T>* tmp;
        tmp = new Pair<T>[capacity + MAX_CARD / 2];
        if (tmp == NULL) {
            cout << "Memory error." << endl;
        }
        for (int i = 0; i < card; i++) {
            tmp[i] = elements[i];
        }
        capacity = capacity + MAX_CARD / 2;
        delete[] elements;
        elements = tmp;
    }
    for (int i = 0 ; i < card; i++) {
        if (elements[i].first == p.first && 
        elements[i].second == p.second) { // Element is already present
            return true;
        }
    }
    elements[card++] = p;
    return true;
}

/**
 * @brief Removes all occurrences of an element
 * 
 * @tparam T 
 * @param t 
 */
template <class T> void Relation<T>::remove_element(T t) {
    stack<int> pos; // Array of indexes for occurrences
    for (int i = 0; i < card; i++) {
        if (elements[i].first == t || elements[i].second == t) {
            pos.push(i);
        }
    }
    if (pos.empty()) {
        return;
    } else {
        while (!pos.empty()) {
            int idx = pos.top();
            for (int i = idx; i < card; i++) {
                elements[i] = elements[i + 1];
            }
            card--;
        }
    }
}

/**
 * @brief Checks if an element is present
 * 
 * @tparam T 
 * @param t 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::is_member(T t) {
    for (int i = 0; i < card; i++) {
        if (elements[i].first == t || elements[i].second == t) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Comparison opeartor
 * 
 * @tparam T 
 * @param r 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::operator==(Relation &r) {
    return (subset(r) && r.subset(*this));
}

/**
 * @brief Checks if a relation is a subset
 * 
 * @tparam T 
 * @param r 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::subset(Relation r) {
    for (int i = 0; i < card; i++) {
        if (!r.is_member(elements[i])) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Index operator
 * 
 * @tparam T 
 * @param idx 
 * @return T 
 */
template <class T> T Relation<T>::operator[](int idx) {
    if (idx >= 0 && idx < card) {
        return elements[idx];
    } else {
        return -1; // Default error
    }
}

/**
 * @brief Checks if reflexive relation
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::reflexive() {
    for (int i = 0; i < root.cardinality(); i++) {
        Pair<T> p;
        p.first = p.second = root[i];
        if (!is_member(p)) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if irreflexive relation
 * 
 */
template <class T> bool Relation<T>::irreflexive() {
    for (int i = 0; i < root.cardinality(); i++) {
        Pair<T> p;
        p.first = p.second = root[i];
        if (is_member(p)) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if symmetric relation
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::symmetric() {
    for (int i = 0; i < card; i++) {
        Pair<T> p;
        p.first = elements[i].first;
        p.second = elements[i].second;
        if (!is_member(p)) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if asymmetric relation
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::asymmetric() {
    for (int i = 0; i < card; i++) {
        Pair<T> p;
        p.first = elements[i].first;
        p.second = elements[i].second;
        if (is_member(p)) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if transitive relation
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::transitive() {
    for (int i = 0; i < card; i++) {
        for (int j = 0; j < card; j++) {
            if (elements[i].second == elements[j].first) {
                Pair<T> p;
                p.first = elements[i].first;
                p.second = elements[i].second;
                if (!is_member(p)) {
                    return false;
                }
            }
        }
        
    }
    return true;
}

/**
 * @brief Checks if function relation
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool Relation<T>::is_function() {
    for (int i = 0; i < card; i++) {
        for (int j = 0; j < card; j++) {
            if (elements[i].first == elements[j].first && 
            elements[i].second == elements[j].second) {
                    return false;
            }
        }
        
    }
    return true;
}
 
/**
 * @brief Printing operator
 * 
 * @tparam T 
 * @param out 
 * @param r 
 * @return ostream& 
 */
// template <class T> ostream& operator<<(ostream& out, Relation<T> r) {
//     out << "{ ";
//     for (int i = 0; i < r.card; i++) {
//         if (i != 0) {
//             out << ", ";
//         }
//         out << "( " << r.elements[i].first << ", " << r.elements[i].second << " )";
//     }
//     out << " }";
//     return out;
// }

/**
 * @brief Returns the combination of 2 relations
 * 
 * @tparam T 
 * @param r 
 * @return Relation<T> 
 */
template <class T> Relation<T> Relation<T>::combination(Relation<T> r) {
    Relation<T> tmp;
    for (int i = 0; i < root.cardinality(); i++) {
        tmp.add_element(root[i]);
    }
    for (int i = 0; i < card; i++) {
        for (int j = 0; j < card; j++) {
            if (elements[i].second == r.elements[j].first) {
                Pair<T> p;
                p.first = elements[i].first;
                p.second = elements[i].second;
                tmp.add_element(p);
            }
        }
    }
    return tmp;
}
