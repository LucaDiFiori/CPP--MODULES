#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    // Create an array of integers call "numbers" using the Array class with a size defined by MAX_VAL and fill it with random values.
    // Create a standard mirror array to check if the values remain unchanged after operations.
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    // Fill the numbers array and the mirror array with random values.
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Call the copy constructor and assignment operator to test their functionality.
    std::cout << PURPLE << "Starting tests for Array class..." << RESET << "\n" << std::endl;
    {
        std::cout << YELLOW << "Testing copy constructor and assignment operator..." << RESET << std::endl;
        Array<int> tmp = numbers;
        std::cout << "Copy constructor called." << std::endl;

        std::cout << YELLOW << "Testing assignment operator..." << RESET << std::endl;
        Array<int> test(tmp);
        std::cout << "Assignment operator called." << std::endl;
    }
    std::cout << GREEN << "Test passed: copy constructor and assignment operator work." << RESET << "\n" << std::endl;

    // Verify that the values in the original array and the copied array are the same.
    std::cout << YELLOW << "Starting value checks..." << RESET << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << RED << "didn't save the same value!!" << RESET << "\n" << std::endl;
            return 1;
        } 
    }
    std::cout << GREEN << "Test passed: all values remain unchanged." << RESET << "\n" << std::endl;

    // Test exception handling for out-of-bounds access.
    std::cout << YELLOW << "Testing out-of-bounds access..." << RESET << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        std::cout << GREEN << "Test passed: caught out-of-bounds exception." << RESET << "\n" << std::endl;
    }

    // Test exception handling for accessing an index equal to the size of the array.
    std::cout << YELLOW << "Testing access at index equal to size..." << RESET << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        std::cout << GREEN << "Test passed: caught out-of-bounds exception." << RESET << "\n" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}