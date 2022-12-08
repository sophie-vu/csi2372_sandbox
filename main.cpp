#include "tree.cpp"

int main() {
    // Graph g = Graph(8);
	// g.add_directed_edge(0, 1);
	// g.add_directed_edge(0, 3);
	// g.add_directed_edge(0, 5);
	// g.add_directed_edge(2, 1);
	// g.add_directed_edge(2, 7);
	// g.add_directed_edge(6, 0);
	// g.add_directed_edge(6, 7);
	// g.add_directed_edge(4, 0);
	// g.add_directed_edge(7, 5);

    // if (g.is_cyclic()) {
    //     cout << "Can't print. It's a cyclical graph." << endl;
    // } else {
    //     g.print();
    // }
	Tree t = Tree();
	// t.insert_node(10);
	t.insert_node(20);
	cout << "Root: " << t.get_root()->val << endl;
	// cout << "Max depth: " << t.get_max_depth(t.get_root());
	// t.insert_node(1);
	// t.insert_node(30);
	// t.insert_node(2);
	// t.insert_node(40);
	// t.insert(3);
	// cout << "Root: " << t.get_root()->val << endl;
    return 0;
}