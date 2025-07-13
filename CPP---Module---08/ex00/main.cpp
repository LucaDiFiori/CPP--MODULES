#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

int main() {
    std::cout << PURPLE << "=== EASYFIND FUNCTION TESTS ===" << RESET << std::endl;

    // Test 1: std::vector
    std::cout << CYAN << "\n1. Testing with std::vector:" << RESET << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << GREEN << "Found in vector: " << *it << RESET << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        easyfind(vec, 100);
    } catch (const NotFoundException& e) {
        std::cout << RED << "Expected error for 100: " << e.what() << RESET << std::endl;
    }

    // Test 2: std::list
    std::cout << CYAN << "\n2. Testing with std::list:" << RESET << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);

    try {
        std::list<int>::iterator it = easyfind(lst, 4);
        std::cout << GREEN << "Found in list: " << *it << RESET << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        easyfind(lst, 10);
    } catch (const NotFoundException& e) {
        std::cout << RED << "Expected error for 10: " << e.what() << RESET << std::endl;
    }

    // Test 3: std::deque
    std::cout << CYAN << "\n3. Testing with std::deque:" << RESET << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);

    try {
        std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << GREEN << "Found in deque: " << *it << RESET << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        easyfind(deq, 500);
    } catch (const NotFoundException& e) {
        std::cout << RED << "Expected error for 500: " << e.what() << RESET << std::endl;
    }

    // Test 4: Empty container
    std::cout << CYAN << "\n4. Testing with empty container:" << RESET << std::endl;
    std::vector<int> empty_vec;

    try {
        easyfind(empty_vec, 1);
    } catch (const NotFoundException& e) {
        std::cout << RED << "Expected error for empty container: " << e.what() << RESET << std::endl;
    }

    // Test 5: Single element container
    std::cout << CYAN << "\n5. Testing with single element container:" << RESET << std::endl;
    std::vector<int> single_vec;
    single_vec.push_back(42);

    try {
        std::vector<int>::iterator it = easyfind(single_vec, 42);
        std::cout << GREEN << "Found in single element container: " << *it << RESET << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    // Test 6: Container with duplicates (finds first occurrence)
    std::cout << CYAN << "\n6. Testing with duplicates (should find first):" << RESET << std::endl;
    std::vector<int> dup_vec;
    dup_vec.push_back(1);
    dup_vec.push_back(2);
    dup_vec.push_back(3);
    dup_vec.push_back(2);  // duplicate
    dup_vec.push_back(4);

    try {
        std::vector<int>::iterator it = easyfind(dup_vec, 2);
        std::cout << GREEN << "Found first occurrence of 2 at position: " << (it - dup_vec.begin()) << RESET << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }

    std::cout << PURPLE << "\n=== ALL TESTS COMPLETED ===" << RESET << std::endl;
    return 0;
}