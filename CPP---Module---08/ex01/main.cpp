#include <iostream>
#include <vector>
#include <list>
#include "span.hpp"

int main() {
    std::cout << PURPLE << "=== SPAN CLASS TESTS ===" << RESET << std::endl;

    // Test 1: Basic addNumber and span calculation
    std::cout << CYAN << "\n1. Basic addNumber and span calculation:" << RESET << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 2: FullSpanException
    std::cout << CYAN << "\n2. FullSpanException:" << RESET << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    } catch (const std::exception& e) {
        std::cout << RED << "Expected: " << e.what() << RESET << std::endl;
    }

    // Test 3: InvalidSpanSizeException (not enough numbers)
    std::cout << CYAN << "\n3. InvalidSpanSizeException (not enough numbers):" << RESET << std::endl;
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << "Trying shortestSpan..." << std::endl;
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << RED << "Expected: " << e.what() << RESET << std::endl;
    }

    // Test 4: addNumbers with vector
    std::cout << CYAN << "\n4. addNumbers with vector:" << RESET << std::endl;
    try {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);
        Span sp(10);
        sp.addNumbers(v.begin(), v.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 5: addNumbers with list
    std::cout << CYAN << "\n5. addNumbers with list:" << RESET << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        Span sp(5);
        sp.addNumbers(lst.begin(), lst.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 6: addNumbers with array
    std::cout << CYAN << "\n6. addNumbers with array:" << RESET << std::endl;
    try {
        int arr[4];
        arr[0] = 7;
        arr[1] = 14;
        arr[2] = 21;
        arr[3] = 28;
        Span sp(10);
        sp.addNumbers(arr, arr + 4);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 7: addNumbers throws if too many elements
    std::cout << CYAN << "\n7. addNumbers throws if too many elements:" << RESET << std::endl;
    try {
        std::vector<int> v(20, 1); // 20 elements, all 1
        Span sp(10);
        sp.addNumbers(v.begin(), v.end()); // Should throw
    } catch (const std::exception& e) {
        std::cout << RED << "Expected: " << e.what() << RESET << std::endl;
    }

    // Test 8: Copy constructor and assignment
    std::cout << CYAN << "\n8. Copy constructor and assignment:" << RESET << std::endl;
    try {
        Span sp1(5);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);
        Span sp2(sp1); // Copy
        Span sp3(5);
        sp3 = sp1;     // Assignment
        std::cout << "sp2 Shortest: " << sp2.shortestSpan() << ", Longest: " << sp2.longestSpan() << std::endl;
        std::cout << "sp3 Shortest: " << sp3.shortestSpan() << ", Longest: " << sp3.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 9: Edge case - identical numbers
    std::cout << CYAN << "\n9. Edge case - identical numbers:" << RESET << std::endl;
    try {
        Span sp(3);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 10: Edge case - negative numbers
    std::cout << CYAN << "\n10. Edge case - negative numbers:" << RESET << std::endl;
    try {
        Span sp(4);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(15);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << PURPLE << "\n=== ALL TESTS COMPLETED ===" << RESET << std::endl;
    return 0;
}