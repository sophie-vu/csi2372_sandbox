#include "Mapping.cpp"
#include <iostream>
using namespace std;

int main() {
	Mapping<string, vector<int>> m;
	vector<int> v;
  	vector<int>::iterator it;
	it = v.begin();
	v.insert(it, 19);
	v.insert(it, 35);
	v.insert(it, 60);
	m.add_item("Mike",v);
	cout << m << endl;
}
