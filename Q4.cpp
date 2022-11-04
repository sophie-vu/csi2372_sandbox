#include "Q4.h"
#include <iostream>
#include <tuple>

Dynamic::Dynamic(int n) {
    this->arr = new int[0];
    this->max = n;
    this->up = 0;
    this->down = 0;
}

Dynamic::Dynamic(int down, int up) {
    this->up = up;
    this->down = down;
    this->max = up - down;
    this->arr = new int[0];
}

Dynamic::Dynamic(const Dynamic& d) {
    this->arr = d.arr;
    this->max = d.max;
    this->up = d.up;
    this->down = d.down;
}

Dynamic::~Dynamic() {
    delete [] arr;
    this->max = 0;
    this->up = 0;
    this->down = 0;
}

void Dynamic::add_item(int item) {
    if (!isInBounds(item)) {
        cout << "Item " << item << " is out of bounds." << endl;
        return;
    }
    if (isFull()) {
        cout << "The array is full." << endl;
        return;
    }
    int size = sizeof(arr);
    cout << "size : " << size << endl;
    int* res = new int[size + 1];
    for (int i = 0; i <= size; i++) {
        res[i] = arr[i];
        cout << i << res[i] << endl;
    }
    res[size + 1] = item;
    cout << size + 1 << res[size + 1] << endl;
    arr = res;
    cout << "new size : " << sizeof(arr) << endl;
}

bool Dynamic::isInBounds(int i) {
    return (i <= up) && (i >= down);
}

bool Dynamic::isFull() {
    // cout << "Max: " << max << endl << "Size: " << sizeof(arr)/sizeof(arr[0]) << endl;
    return max == sizeof(arr)/sizeof(arr[0]);
}

void Dynamic::remove_item() {
    if (sizeof(*arr) == 0) {
        cout << "No items to remove." << endl;
        return;
    }
    int* res = new int[sizeof(*arr) - 1];
    for (int i = 0; i < (sizeof(*arr) - 1); i++) {
        res[i] = arr[i];
    }
    arr = res;
}

void Dynamic::insert_item(int item, int pos) {
    if (!isInBounds(item)) {
        cout << "Item " << item << " at " << pos << " is out of bounds." << endl;
        return;
    }
    if (isFull()) {
        cout << "The array is full." << endl;
        return;
    }
    int* res = new int[sizeof(*arr) + 1];
    for (int i = 0; i <= pos; i++) {
        if (i == pos) {
            res[i] = item;
        } else {
            res[i] = arr[i];
        }
    }

    for (int j = pos + 1; j < (sizeof(*arr) + 1); j++) {
        res[j] = arr[j + 1];
    }
    arr = res;
}

void Dynamic::erase_item(int item, int pos) {
    if (sizeof(*arr) == 0) {
        cout << "No items to remove." << endl;
        return;
    }
    if (find_item(item) == tuple<bool, int>(false, 0) ) {
        cout << "cannot find the item " << item << " at " << pos << "." << endl;
        return;
    }
    int* res = new int[sizeof(*arr) - 1];
    for (int i = 0; i <= pos; i++) {
        if (i == pos) {
            break;
        } else {
            res[i] = arr[i];
        }
    }

    for (int j = pos + 1; j < sizeof(*arr); j++) {
        res[j] = arr[j - 1];
    }
    arr = res;
}

tuple<bool, int> Dynamic::find_item(int item) {
    tuple<bool, int> res;
    for (int i = 0; i < sizeof(*arr); i++) {
        if (arr[i] == item) {
            res = make_tuple(true, i);
            return res;
        }
    }
    res = make_tuple(false, 0);
    return res;
}

void Dynamic::operator=(const Dynamic& d) {
    this->max = d.max;
    this->up = d.up;
    this->down = d.down;
    this->arr = d.arr;
}

int Dynamic::operator[](int pos) {
    return arr[pos];
}

ostream& operator<<(ostream& out, const Dynamic& d) {
    for (int i = 0; i < sizeof(*d.arr); i++) {
        if (i == (sizeof(*d.arr) - 1)) {
            out << d.arr[i];
        } else {
            out << d.arr[i] << ", "; 
        }
    }
    return out;
}