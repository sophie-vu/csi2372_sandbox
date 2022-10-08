/**
 * @brief Header file for the Big Integer class.
 * @author Sophie Vu
 */

class BigInteger {
    private:
        int num;
        int base; 
    public: 
        BigInteger(); // Default constructor
        BigInteger(int num, int base); // Constructor takes number and base
        BigInteger(BigInteger& other); // Copy constructor
        ~BigInteger(); // Desctructor
        int set_num_digits(int num); // Setter for the digit
        int num_digits(); // Getter for the number of digits in the given base
        int base_digit(); // Getter for the base
        void set_base_digit(int num); // Setter for the base;
        void add_digit(int num); // Adds a digit at the least significant digit
        void remove_digit(int num); // Removes the least significant digit
        void insert_digit(int idx, int num); // Inserts a digit at a given index
        void operator[](int idx); // Indexing
        void operator==(BigInteger& other); // Checking if 2 numbers are equal
        void operator>(BigInteger& other);
        void operator<(BigInteger& other);
        void operator>=(BigInteger& other);
        void operator<=(BigInteger& other);
        void operator!=(BigInteger& other);
        void operator=(BigInteger& other);
        void operator+(BigInteger& other);
        void operator-(BigInteger& other);
        void operator*(BigInteger& other);
        void operator++();
        void operator--();
        void operator/(BigInteger& other);
        void operator%(BigInteger& other);
        void operator<<(BigInteger& other);
        void operator>>(BigInteger& other);  
};