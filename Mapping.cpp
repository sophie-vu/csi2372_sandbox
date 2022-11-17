#include "Mapping.h"
#include <iostream>
#include <map>
#include <vector>
 using namespace std;

template <typename K, typename V>
Mapping<K,V>::Mapping() { // Default constructor
    this->map = new vector<MappingNode<K,V>>(10000);
}

template <typename K, typename V>
Mapping<K,V>::Mapping(Mapping& m) { // Copy constructor
    this->map = m.map;
}

template <typename K, typename V>
Mapping<K,V>::~Mapping() { // Destructor
    map.clear();
}

template <typename K, typename V>
void Mapping<K,V>::add_item(const K &a, const V &b) { // Adds b to set of type V + if a doesn't exist -> add it to map
    if (!(contains(a))) {
        MappingNode<K, V> entry = new MappingNode<K, V>(a);
        map.pop_back(entry);
        return;
    } else {
        for (MappingNode<K,V> elem : map) {
            if (elem.key == a) {
                elem.addVal(b);
                return;
            }
        }
    }
    return;
}

template <typename K, typename V>
void Mapping<K,V>::remove_item(const K &a, const V &b) { // Removes b from set of type K
    for (MappingNode<K,V> elem : map) {
        if (elem.key == a) {
            elem.removeVal(b);
            return;
        }
    }
    return;
}

template <typename K, typename V>
void Mapping<K,V>::clear_item(const K &a) { // Remove a from mapping
    if (!(contains(a))) {
        return;
    } else {
        for (MappingNode<K,V> elem : map) {
            if (elem.key == a) {
                map.erase(elem);
                return;
            }
        }
    }
    return;
}

template<typename K, typename V>
vector<V> Mapping<K,V>::find_item(const K &a) { // Return set of a
    for (MappingNode<K, V> elem : map) {
        if (elem.key == a) {
            return elem.val;
        }
    }
    vector<V> v;
    return v;
}

template<typename K, typename V>
bool Mapping<K,V>::contains(const K &a) { // Return set of a
    for (MappingNode<K, V> elem : map) {
        if (elem.key == a) {
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
MappingNode<K,V> Mapping<K,V>::operator[](const K &a) { // Mapping operator=(const Mapping<K,V> m);
    for (MappingNode<K,V> elem : map) {
        if (elem.key == a) {
            return elem;
        }
    }
    return NULL;
}

template<typename K, typename V>
ostream& operator<<(ostream &out, const Mapping<K,V> &m) {
    out << "[ ";
    for (MappingNode<K,V> elem : m.map) {
        out << elem.key << "{ ";
        for (V v : elem) {
            out << v << " ";
        }
        out << " } ";
    }
    out << "]" << endl;
    return out;
}

template<typename K, typename V>
void Mapping<K,V>::operator=(const Mapping<K,V> &m) {
    this = Mapping(m);
}
