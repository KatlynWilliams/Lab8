#include "Array.h"

template <typename arrayType>
// Constructor
Array::Array(arrayType size) : size(size) {
    std::cout << "Create an array." << std::endl;
    data = new arrayType[size]; // Allocate array
}

// Copy Constructor
Array::Array(const Array& source) {
    size = source.size;
    std::cout << "Copying array with copy constructor." << std::endl;
    data = new arrayType[size]; // Allocate new array
    for (int i = 0; i < size; i++) {
        data[i] = source.data[i]; // Copy elements
    }
}

// Destructor
Array::~Array() {
    std::cout << "Delete object." << std::endl;
    delete[] data; // Release allocated memory
}

// Assignment Operator
Array& Array::operator=(const Array& source) {
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
int& Array::operator[](std::size_t index) const {
    if (index >= size) {
        throw std::out_of_range("index out of range");
    }
    return data[index];
}

// Dereference (Indirection) Operator
arrayType& Array::operator*() const {
    return *data; // Return first element
}