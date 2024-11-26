#pragma once
#include <iostream>
#include <stdexcept>

template <typename arrayType>
class Array {
private:
    arrayType<int> size;
    arrayType<int>* data;
public:
    explicit Array(arrayType size);
    Array(const Array& source);
    ~Array();
    Array& operator=(const Array& source);

    // Overloaded Subscript Operator
    int& operator[](std::size_t index) const;

    // Overloaded Dereference (Indirection) Operator
    arrayType<int>& operator*() const;
};
