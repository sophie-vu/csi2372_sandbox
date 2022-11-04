#include <tuple>
#include <iostream>
using namespace std;
class Dynamic {
    private:
        int size;
        int max;
        int up;
        int down;
        int* arr;
    public:
        Dynamic(int n);
        Dynamic(int down, int up);
        Dynamic(const Dynamic& d);
        ~Dynamic();
        void add_item(int item);
        void remove_item();
        void insert_item(int item, int pos);
        void erase_item(int item, int pos);
        tuple<bool, int> find_item(int item);
        void operator=(const Dynamic& d);
        int operator[](int pos);
        bool isInBounds(int i);
        bool isFull();
        friend ostream& operator<<(ostream& out, const Dynamic& d);
};