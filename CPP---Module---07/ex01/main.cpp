#include "iter.hpp"
#include <iostream>

// TEST FUNCTION__________________________§

template <typename T>
void printElement(T& elem) {
    std::cout << elem << std::endl;
}

// MAIN____________________________________§
int main() {
    int arrInt[4] = {100, 234, 42, 3};
    double arrDouble[4] = {0.3, 4.2, 1.1, 5.9};
    std::string arrString[4] = {"Hello", "i", "love", "C++"};
    char arrChar[4] = {'L','u','c','a'};


    std::cout << "TEST --> Int array: int arrInt[4] = {100, 234, 42, 3}" << std::endl;
    std::cout << "Iter call:" << std::endl;
    iter(arrInt, 4, printElement);

    std::cout << "\nTEST --> double array: double arrDouble[4] = {0.3, 4.2, 1.1, 5.9}" << std::endl;
    std::cout << "Iter call:" << std::endl;
    iter(arrDouble, 4, printElement);

    std::cout << "\nTEST --> std::string arrString[4] = {Hello, i, love, C++}" << std::endl;
    std::cout << "Iter call:" << std::endl;
    iter(arrString, 4, printElement);

    std::cout << "\nTEST --> char array: char arrChar[4] = {'L','u','c','a'}" << std::endl;
    std::cout << "Iter call:" << std::endl;
    iter(arrChar, 4, printElement);
}
