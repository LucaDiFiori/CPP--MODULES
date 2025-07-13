#pragma once

#include <algorithm>

#ifndef COLORS
#define COLORS
#define PURPLE "\033[1;35m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#endif

// Custom exception class for not found elements
class NotFoundException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Element not found in the container";
        }
};

/*
 * EASYFIND FUNCTION TEMPLATE
 * 
 * WHAT IT DOES:
 * - Searches for the first occurrence of an integer value in any STL container
 * - Works with any container type T that supports iterators (vector, list, deque, etc.)
 * 
 * HOW IT WORKS:
 * - Uses std::find algorithm to search from container.begin() to container.end()
 * - std::find returns an iterator to the first element that matches the search value
 * - If no match is found, std::find returns container.end()
 * - Compares the returned iterator with container.end() to check if element was found
 * 
 * WHAT IT RETURNS:
 * - SUCCESS: Returns an iterator pointing to the first occurrence of the searched element
 * - FAILURE: Throws NotFoundException if the element is not found in the container
 * 
 * PARAMETERS:
 * - T& container: Any STL container containing integers (PASSED BY REFERENCE)
 * - int to_find: The integer value to search for
 * 
 * IMPORTANT NOTE - WHY PASS BY REFERENCE:
 * The container MUST be passed by reference (T&) and not by value (T) because:
 * 1. If passed by value, the function receives a COPY of the container
 * 2. The returned iterator would point to elements in this temporary copy
 * 3. When the function ends, the copy gets destroyed
 * 4. The returned iterator becomes invalid (points to destroyed memory)
 * 5. Dereferencing this iterator causes undefined behavior (garbage values)
 * 
 * By passing by reference, the iterator points to the original container,
 * ensuring it remains valid after the function returns.
 */
template <typename T>
typename T::iterator easyfind(T& container, int to_find) {
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
};