#include <iostream>
#include <stdexcept>

template <typename arrayType>
class Array {
private:
    int size;
    arrayType* data;
public:
    explicit Array(int size);
    Array(const Array& source);
    ~Array();
    Array& operator=(const Array& source);

    // Overloaded Subscript Operator
    arrayType& operator[](std::size_t index) const;

    // Overloaded Dereference (Indirection) Operator
    arrayType& operator*() const;
};

// Constructor
template <typename arrayType>
Array<arrayType>::Array(int size) : size(size) {
    std::cout << "Create an array." << std::endl;
    data = new arrayType[size]; // Allocate array
}

// Copy Constructor
template <typename arrayType>
Array<arrayType>::Array(const Array<arrayType>& source) {
    size = source.size;
    std::cout << "Copying array with copy constructor." << std::endl;
    data = new arrayType[size]; // Allocate new array
    for (int i = 0; i < size; i++) {
        data[i] = source.data[i]; // Copy elements
    }
}

// Destructor
template <typename arrayType>
Array<arrayType>::~Array() {
    std::cout << "Delete object." << std::endl;
    delete[] data; // Release allocated memory
}

// Assignment Operator
template <typename arrayType>
Array<arrayType>& Array<arrayType>::operator=(const Array& source) {
    std::cout << "Assigning array to a copy of an object." << std::endl;
    if (this == &source) return *this; // Handle self-assignment
    delete[] data; // Clean up existing resource
    size = source.size;
    data = new arrayType[size]; // Allocate new array
    for (int i = 0; i < size; i++) {
        data[i] = source.data[i]; // Copy elements
    }
    return *this;
}

// Subscript Operator
template <typename arrayType>
arrayType& Array<arrayType>::operator[](std::size_t index) const {
    if (index >= size) {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}

// Dereference (Indirection) Operator
template <typename arrayType>
arrayType& Array<arrayType>::operator*() const {
    return *data; // Return first element
}


int main() {
  Array<int> array1(2);
  Array<int> array2(array1); // Testing copy constructor
  Array<double> array3(3);
  Array<double> array4(3);
  array3 = array4; // Testing assignment operator
  std::cout << array3[1]; // Access an element
  return 0;
}
