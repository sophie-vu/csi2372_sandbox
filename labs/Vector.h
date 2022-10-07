class Vector {
    private:
        double* val;
        int dimension;
        double magnitude;
    public:
        Vector(); // Default constructor that initializes a vector in 2d
        Vector(double* arr, int num); // Default that initializes a vector in nd
        Vector(Vector& other); // Copy constructor
        ~Vector(); // Destructor
        int getDimension(); // Dimension getter
        void add_dimension(int n); // Add given dimension at the end
        void remove_dimension(int index); // Remove a dimension at a given index
        void insert_dimension(int index, int n); // Add a new dimension at a given index
        int getManitude(); // Length of vector getter
        bool operator[](int n); // Indexes dimensions
        bool operator==(Vector& other); // Checks if 2 vectors are equal (same dim, same elements in each dim)
        bool operator!=(Vector& other); // Check if 2 vectors are not equal (different dim, different element at a dim)
        void operator=(Vector& other); // Assigns vector to another vector
        Vector operator+(Vector& other); // New vector has larger dim and smaller vector has elements of 0
        Vector operator-(Vector& other); // New vector has larger dim and smaller vector has elements of 0
        Vector operator*(Vector& other);
        void operator+=(Vector& other); // Add + assign result
        void operator-=(Vector& other); // Substract + assign the result
        void operator<<(Vector& other); // Print vector in format v = (5, -6, 2)
};