#include <vector>
#include <iostream>
using namespace std;

class RandomGenerator {
    private:
        int s; // Number of digitts used in sequence to generate next number
    public:
        int first; // First seed
        int second; // Second seed
        vector<int> seq; // Vector for sequence
        RandomGenerator(); // Default constructor
        RandomGenerator(int s, int first, int second); // Constructor with parameters s, first and second
        RandomGenerator(RandomGenerator const &r); // Copy constructor
        ~RandomGenerator(); // Destructor
        RandomGenerator next(); // Generates next random number
        RandomGenerator previous(); // Gets previous random number
        int operator[](int i);
        bool operator==(RandomGenerator const &r);  
        bool operator!=(RandomGenerator const &r);  
        void operator=(RandomGenerator const &r);  
        RandomGenerator operator+(RandomGenerator const &r);  
        RandomGenerator operator-(RandomGenerator const &r);  
        RandomGenerator operator*(RandomGenerator const &r);  
        void operator+=(RandomGenerator const &r);  
        void operator-=(RandomGenerator const &r); 
        void operator*=(RandomGenerator const &r);          
        void operator++();  
        void operator--();  
        int getRand(); // Returns a random digit 
        int format(int e, int givenS); // Adds randomized element to back of sequence with given s
};