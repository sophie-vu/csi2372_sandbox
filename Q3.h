#include <vector>
#include <set>
using namespace std;
template <typename T>
class FuzzySet {
    public:
    vector<vector<T>> set;
    FuzzySet();
    FuzzySet(FuzzySet&);
    FuzzySet<T> intersection(FuzzySet<T> f1, FuzzySet<T> f2);
};