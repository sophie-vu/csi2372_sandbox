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
        Set(Set& s);

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
         * @param s1 
         * @param s2 
         * @return true 
         * @return false 
         */
        bool equal(::set<int> s1, ::set<int> s2) {
            return s1 == s2;
        }

        /**
         * @brief Checks if a set is a subset of another set
         * 
         * @param s1 
         * @param s2 
         * @return true 
         * @return false 
         */
        bool subset(::set<int> s1, ::set<int> s2) {
            return std::includes(s1.begin(), s1.end(), s2.begin(), s2.end()); 
        }

        /**
         * @brief Checks if a set is a subset of the current set
         * 
         * @param s1 
         * @return true 
         * @return false 
         */
        bool subset(::set<int> s1) {
            return std::includes(s1.begin(), s1.end(), set.begin(), set.end()); 
        }

        /**
         * @brief Returns the union of 2 sets
         * 
         * @param s1 
         * @param s2 
         * @return Set
         */
        Set getUnion(::set<int> s1, ::set<int> s2) {
            Set res = {};
            res = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), res);
            return res;
        }

        /**
         * @brief Returns the union of a give set and the current set
         * 
         * @param s1 
         * @return Set
         */
        Set getUnion(::set<int> s1) {
            Set res = {};
            res = set_union(s1.begin(), s1.end(), set.begin(), set.end(), res);
            return res;
        }

        /**
         * @brief Returns the intersection of 2 sets
         * 
         * @param s1 
         * @param s2 
         * @return Set
         */
        Set intersection(::set<int> s1, ::set<int> s2) {
            Set res = {};
            res = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), res);
            return res;
        }

        /**
         * @brief Returns the intersection of a given set and the current set
         * 
         * @param s1 
         * @return Set
         */
        Set intersection(::set<int> s1) {
            Set res = {};
            res = set_intersection(s1.begin(), s1.end(), set.begin(), set.end(), res);
            return res;
        }

        /**
         * @brief Returns the difference between a given set and the current set
         * 
         * @param s 
         * @return Set
         */
        Set difference(::set<int> s) {
            Set res = {};
            res = set_difference(s.begin(), s.end(), this->set.begin(), this->set.end(), res);
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
        Set mutual_difference(::set<int> s) { 
            Set res, diff1, diff2 = {};
            diff1 = difference(s, this->set);
            diff2 = difference(this->set, s);
            res = getUnion(diff1.set, diff2.set);
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

int main() {
    Set a, b, uni, inter, diff, mutualdiff = {};
    a.add_element(1);
    a.add_element(4);
    a.add_element(5);
    a.add_element(6);

    b.add_element(1);
    b.add_element(2);
    b.add_element(4);
    b.add_element(10);

    cout << "ELEMENTS IN SET A " << endl;
    a.printSet();

    cout << "ELEMENTS IN SET B " << endl;
    b.printSet();

    cout << "IS A SUBSET OF B? " << b.subset({1, 4, 5, 6});
    cout << "IS B SUBSET OF A? " << a.subset({1, 2, 4, 10});

    cout << "UNION\n" << endl;
    uni = a.getUnion(b.getSet());
    uni.printSet();

    cout << "INTERSECTION\n" << endl;
    inter = a.intersection(b.getSet());
    inter.printSet();

    cout << "DIFFERENCE\n" << endl;
    diff = a.difference(b.getSet());
    diff.printSet();
    
    cout << "MUTUAL DIFFERENCE\n" << endl;
    mutualdiff = a.mutual_difference(b.getSet());
    mutualdiff.printSet();
}