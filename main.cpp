#include "tree.cpp"
int main() {
	Tree t = Tree(); // Create a tree
	t.insert_node(10);
	t.insert_node(1);
	t.insert_node(30);
	t.insert_node(2);
	t.insert_node(3);
	t.print(); // Print prettily
    return 0;
}