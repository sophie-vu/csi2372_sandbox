#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

class Set {
    private:
        static const int LIMIT = 1000;
        set<int> set;

    public:
        /**
         * @brief Construct a new Set object
         */
        Set() {
            set = {};
        }

        /**
         * @brief Copy construct a new Set object
         *
         * @param s
         */
        Set(const Set &s);

        /**
         * @brief Returns the number of elements in the set
         * 
         * @return int 
         */
        int cardinality() {
            return set.size();
        }

        /**
         * @brief Get the Set object
         * 
         * @return ::set<int> 
         */
        ::set<int> getSet() {
            return this->set;
        }

        /**
         * @brief Checks if an element is in the set
         * 
         * @param e 
         * @return true 
         * @return false 
         */
        bool is_member(int e) {
            return set.count(e) >= 1;
        }

        /**
         * @brief Adds an element into the set
         * 
         * @param e 
         */
        void add_element(int e) {
            if (!is_member(e)) {
                if (cardinality() <= LIMIT) {
                    set.insert(e);
                    return;
                }
                cout << "The max size of " << LIMIT << " has already been reached." << endl;
            }
            cout << "Element " << e << " is already part of the set." << endl;
        }

        /**
         * @brief Removes an element into the set
         * 
         * @param e 
         */
        void remove_element(int e) {
            if (is_member(e)) {
                set.erase(e);
                return;
            }
            cout << "Element " << e << " is not part of the set." << endl;
        }

        /**
         * @brief Checks if 2 sets are equal
         * 
         * @param s
         * @return true 
         * @return false 
         */
        bool equal(Set s) {
            return s.set == set;
        }

        /**
         * @brief Checks if a set is a subset of the current set
         * 
         * @param s1 
         * @return true 
         * @return false 
         */
        bool subset(Set s1) {
            return std::includes(s1.set.begin(), s1.set.end(), set.begin(), set.end()); 
        }

        /**
         * @brief Returns the union of 2 sets
         * 
         * @param s1 
         * @param s2 
         * @return Set
         */
        Set Union(Set s1, Set s2) {
            Set res = {};
            res = set_union(s1.set.begin(), s1.set.end(), s2.set.begin(), s2.set.end(), res);
            return res;
        }

        /**
         * @brief Returns the union of a give set and the current set
         * 
         * @param s
         * @return Set
         */
        Set Union(Set s) {
            Set res = {};
            res = set_union(s.set.begin(), s.set.end(), set.begin(), set.end(), res);
            return res;
        }

        /**
         * @brief Returns the intersection of a given set and the current set
         * 
         * @param s1 
         * @return Set
         */
        Set intersection(Set s1) {
            Set res = {};
            res = set_intersection(s1.set.begin(), s1.set.end(), set.begin(), set.end(), res);
            return res;
        }

        /**
         * @brief Returns the difference between a given set and the current set
         * 
         * @param s 
         * @return Set
         */
        Set difference(Set s) {
            Set res = {};
            res = set_difference(s.set.begin(), s.set.end(), this->set.begin(), this->set.end(), res);
            return res;
        }

        /**
         * @brief Returns the difference between 2 sets
         * 
         * @param s1
         * @param s2 
         * @return Set
         */
        Set difference(::set<int> s1, ::set<int> s2) {
            Set res = {};
            res = set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), res);
            return res;
        }

        /**
         * @brief Returns the mutual different between a given set and the current set
         * 
         * @param s 
         * @return Set
         */
        Set mutual_difference(Set s) { 
            Set res, diff1, diff2 = {};
            diff1 = difference(s);
            diff2 = difference(set, s.set);
            res = Union(diff1, diff2);
            return res;
        }

        /**
         * @brief Get the element at a given idnex
         * 
         * @param index 
         * @return int 
         */
        int getElementAt(int index) {
            if (index >= 0 && index <= this->cardinality()) {
                return *std::next(set.begin(), index);
            }
            cout << "Invalid index: " << index << "." << endl;
            return -1;
        }

        /**
         * @brief Print the current set
         */
        void printSet() {
            for (int i = 0; i < this->cardinality(); i++) {
                cout << this->getElementAt(i) << endl;
            }
        }
};