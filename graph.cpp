#include "graph.h"
Graph::Graph(int num) {
    num_vertices = num;
    list = new LinkedList[num];
}

Graph::~Graph() {
    delete [] list;
}

void Graph::add_directed_edge(int u, int w) {
    list[u].insert_directed_edge_at_end(w);
}

void Graph::add_undirected_edge(int u, int w) {
    list[u].insert_undirected_edge_at_end(w);
}

void Graph::remove_directed_edge(int u, int w) {
    if (list[u].delete_node(w)) {
        cout << "The vertex " << u << " and " << w << " does  not exist in the graph." << endl;
    } else {
        cout << "The vertex " << u << " and " << w << " is deleted." << endl;
    }
}

void Graph::print() {
    stack<int> stack;
    cout << "Num of vertices "  << num_vertices << endl;
    bool* visited = new bool[num_vertices]; // Visited nodes
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (visited[i] == false) {
            visit(i, visited, stack);
        }
    }
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    delete [] visited;
    cout << "In print function." << endl;
}

void Graph::visit(int u, bool visited[], stack<int>& stack) {
    visited[u] = true;
    Node* curr = list[u].head;
    if (curr != NULL) {
        for (int i = 0; i < list[u].size; i++) {
            if (!curr->is_directed) {
                cout << "Undirected vertice detected. Abort." << endl;
                abort();
            }
            if (!visited[curr->val]) {
                visit(curr->val, visited, stack);
            }
            curr = curr->next;
        }
    }
    stack.push(u);
}

bool Graph::is_cyclic() {
    bool* visited = new bool[num_vertices];
    bool* stack = new bool[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
        stack[i] = false;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (check_vertices(i, visited, stack)) {
            return true;
        }
    }
    return false;
}

bool Graph::check_vertices(int u, bool* visited, bool* stack) {
    if (visited[u] == false) {
        visited[u] = true;
        stack[u] = true;
        if (list[u].head != NULL) {
            Node* curr = list[u].head;
            while (curr != NULL) {
                bool contains_cycle = check_vertices(curr->val, visited, stack);
                if (!visited[curr->val] && contains_cycle) {
                    return true;
                } else if (stack[curr->val]) {
                    return true;
                } else {
                    curr = curr->next;
                }
            }
        }
    }
    stack[u] = false;
    return false;
}