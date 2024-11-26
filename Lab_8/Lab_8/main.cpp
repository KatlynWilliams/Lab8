#include "Array.h"

int main() {
    {
        {
            Array<int> array1(2);
            Array<int> array2(array1); // Testing copy constructor
            Array<int> array3(3);
            array3 = array2; // Testing assignment operator
            std::cout << array3[1]; // Access an element
        } // array1 and array2 go out of scope here

        return 0;
    }