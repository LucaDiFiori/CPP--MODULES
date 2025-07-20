#pragma once

#include <iostream>
#include <vector> // We use a vector to store the numbers
#include <algorithm> // For sorting and finding spans

#ifndef COLORS
#define COLORS
#define PURPLE "\033[1;35m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#endif

class Span {
    private:
        unsigned int _size;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int size);
        Span(const Span &cpy);
        ~Span();
        Span &operator=(const Span &cpy);

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
        
        /**
         * ADDNUMBERS FUNCTION TEMPLATE
         * 
         * WHAT IT DOES:
         * - Adds multiple numbers to the Span in a single call using a range of iterators
         * - Allows efficient filling of the Span from any iterable container (vector, list, array, etc.)
         * 
         * WHY IT'S A TEMPLATE:
         * - Being a template allows this function to accept any type of iterator (vector, list, array, etc.)
         * - This makes the function flexible and compatible with different container types and iterator categories
         * - The function can be used with any container that supports iterators, not just vectors
         *   It will insert all elements from the given range into the Span's internal vector
         * 
         * HOW IT WORKS:
         * - Calculates the number of elements in the given iterator range using std::distance
         * - Checks if the range is valid (non-negative distance)
         * - Checks if there is enough room in the Span to add all elements (throws FullSpanException if not)
         * - Uses static_cast to safely convert the count (which is std::ptrdiff_t, possibly negative) to size_t for comparison
         * - Inserts all elements from the range into the Span's internal container
         * 
         * WHAT IT RETURNS:
         * - SUCCESS: Adds all elements from the range to the Span
         * - FAILURE: Throws FullSpanException if there is not enough space, or InvalidSpanSizeException if the range is invalid
         * 
         * USAGE EXAMPLE:
         * std::vector<int> v = {1, 2, 3, 4, 5};
         * Span sp(10);
         * sp.addNumbers(v.begin(), v.end()); // Adds all numbers from v to sp
         */
        template <typename InputIterator>
        void addNumbers(InputIterator first, InputIterator last) {
            std::ptrdiff_t count = std::distance(first, last);

            if (count < 0)
                throw InvalidSpanSizeException();

            if (this->_numbers.size() + static_cast<size_t>(count) > this->_size)
                throw FullSpanException();

            this->_numbers.insert(this->_numbers.end(), first, last);
        }

        
        // Note: The "virtual" keyword is not strictly necessary,
        //       but it is a good practice to use it.
        //       The throw() method is marked as "virtual" in the base class already.
        class FullSpanException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class InvalidSpanSizeException : public std::exception {
            public:
                virtual const char *what() const throw();
        };


};