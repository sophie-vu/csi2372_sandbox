#include "Q3.h"
// class Fuzzy {
//     Fuzzy();
//     Fuzzy(Fuzzy&);
//     ~Fuzzy();
// };
template <typename T> FuzzySet<T>::FuzzySet() {
    set = vector<vector<T>>();
}

template <typename T> FuzzySet<T>::FuzzySet(FuzzySet& f1) {
    set = f1.set;
}

template <typename T> FuzzySet<T> FuzzySet<T>::intersection(FuzzySet<T> f1, FuzzySet<T> f2) {
    FuzzySet<T> res;
    for (vector<T> x : f1.set) {
        vector<T> to_push;
        for (T y : x) {
            if (find(f2.set.begin(), f2.set.end(), y) != f2.set.end()) {
                if (to_push.size() < 2) {
                    to_push.push_back(y);
                } else { // Size == 2
                    res.set.push_back(to_push);
                    to_push.clear();
                }
            } 
        }
    }
    return res;
}
