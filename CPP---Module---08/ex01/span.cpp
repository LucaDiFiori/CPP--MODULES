#include "span.hpp"

Span::Span() : _size(0) {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int size) : _size(size) {
    std::cout << GREEN << "Parameterized constructor called with size: " << size << RESET << std::endl;
}

Span::Span(const Span &cpy) {
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
    this->_size = cpy._size;
    this->_numbers = cpy._numbers;
}

Span::~Span() {
    std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Span &Span::operator=(const Span &cpy) {
    std::cout << GREEN << "Assignment operator called" << RESET << std::endl;
    if (this != &cpy) {
        this->_size = cpy._size;
        this->_numbers = cpy._numbers;
    }
    return *this;
}

const char *Span::FullSpanException::what() const throw() {
    return "ERROR: Span is full, cannot add more numbers.";
}

const char *Span::InvalidSpanSizeException::what() const throw() {
    return "ERROR: Invalid span size.";
}

// Adds a number to the span, throws FullSpanException if the span is full
void Span::addNumber(int n) {
    if (_numbers.size() >= _size) {
        throw FullSpanException();
    }
    _numbers.push_back(n);
}

/**
 * WHAT IT DOES:
 * - Finds the shortest span (minimum distance) between any two numbers in the container
 * - A span is the absolute difference between two numbers
 * - Returns the smallest possible span among all pairs of numbers
 * 
 * HOW IT WORKS:
 * - First checks if container has at least 2 elements (throws exception if not)
 * - Creates a sorted copy of the numbers vector using std::sort
 * - Iterates through consecutive elements in the sorted array
 * - Calculates the difference between each pair of adjacent elements
 * - Keeps track of the minimum difference found
 * - Returns the smallest span discovered
 * 
 * WHY SORTING IS USED:
 * - In a sorted array, the shortest span will always be between consecutive elements
 * - This avoids checking all possible pairs (O(n²) complexity)
 * - Sorting + linear scan = O(n log n) complexity, which is more efficient
 * 
 * WHAT IT RETURNS:
 * - SUCCESS: Returns the shortest span (minimum distance) as an integer
 * - FAILURE: Throws InvalidSpanSizeException if container has fewer than 2 elements
 */
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw InvalidSpanSizeException();
    }
    
    // Create a sorted copy of the vector
    std::vector<int> sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    //find the minimun difference between consecutive elements
    int min_span = sorted_numbers[1] - sorted_numbers[0];

    for (size_t i = 2; i < sorted_numbers.size(); i++) {
        int current_span = sorted_numbers[i] - sorted_numbers[i-1];
        if (current_span < min_span) {
            min_span = current_span;
        }
    }
    return min_span;
}

/**
 * LONGESTSPAN FUNCTION
 * 
 * WHAT IT DOES:
 * - Finds the longest span (maximum distance) between any two numbers in the container
 * - Returns the difference between the maximum and minimum values
 * 
 * HOW IT WORKS:
 * - Uses std::min_element and std::max_element algorithms to find extremes
 * - Calculates the difference between max and min values
 * - Much more efficient than sorting for this specific case
 * 
 * COMPLEXITY: O(n) - single pass through the container
 */
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw InvalidSpanSizeException();
    }
    
    std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
    
    return *max_it - *min_it;
}
