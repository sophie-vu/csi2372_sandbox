class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    bool is_directed;
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void insert_directed_edge_at_end(int);
        void insert_undirected_edge_at_end(int);
        bool delete_first();
        bool delete_last();
        bool delete_node(int);
};