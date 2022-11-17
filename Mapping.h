#include <iostream>
#include <vector>
using namespace std;
template <typename K, typename V>
class MappingNode {
    public:
    K key;
    vector<V> val;

    MappingNode(K key) {
        this.key = key;
        val = new vector<V>;
    }

    void addVal(V entry) {
        if (entry == NULL) {
            cout << "Null entry.";
            return;
        }
        val.pop_back(entry);
    }

    void removeVal(V entry) {
        if (val == NULL) {
            cout << "Cannot remove from empty vector.";
        }
        if (entry == NULL) {
            cout << "Null entry.";
            return;
        }
        if (getIndex(entry) == -1) {
            cout << "Could not find the entry.";
        }
        val.erase(entry);
    }

    void setVal(vector<V> v) {
        this->val = v;
    }

    int getIndex(V entry) {
        int res = 0;
        for (V v : val) {
            if (v == entry) {
                return res;
            }
            res++;
        }
        return -1;
    }
};

template <typename K, typename V>
class Mapping {
    private:
        vector<MappingNode<K, V>> map;
    public:
        Mapping(); // Default constructor
        Mapping(Mapping& m); // Copy constructor
        ~Mapping(); // Destructor
        void add_item(const K &a, const V &b); // Adds b to set of type V + if a doesn't exist -> add it to map
        void remove_item(const K &a, const V &b); // Removes b from set of type K
        void clear_item(const K &a); // Remove a from mapping
        vector<V> find_item(const K &a); // Return set of a
        MappingNode<K,V> operator[](const K &a); 
        void operator=(const Mapping<K,V> &m);
        friend ostream& operator<<(ostream &out, const Mapping<K,V> &m);
        bool contains(const K &a);
};