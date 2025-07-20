#include <iostream>
#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
    std::cout << PURPLE << "=== MutantStack TESTS (default: std::deque) ===" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << CYAN << "Iterating through MutantStack elements:" << RESET << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << "Element: " << *it << std::endl;
        ++it;
    }

    std::cout << CYAN << "Copying MutantStack to std::stack..." << RESET << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Top of std::stack: " << s.top() << std::endl;
    std::cout << "Size of std::stack: " << s.size() << std::endl;

    // Test with std::vector as underlying container
    std::cout << PURPLE << "\n=== MutantStack TESTS (std::vector) ===" << RESET << std::endl;
    MutantStack<int, std::vector<int> > vstack;
    vstack.push(42);
    vstack.push(21);
    vstack.push(84);
    vstack.push(168);

    std::cout << CYAN << "Iterating through MutantStack<std::vector> elements:" << RESET << std::endl;
    MutantStack<int, std::vector<int> >::iterator vit = vstack.begin();
    MutantStack<int, std::vector<int> >::iterator vite = vstack.end();
    while (vit != vite)
    {
        std::cout << "Element: " << *vit << std::endl;
        ++vit;
    }

    // Test with std::list as underlying container
    std::cout << PURPLE << "\n=== MutantStack TESTS (std::list) ===" << RESET << std::endl;
    MutantStack<int, std::list<int> > liststack;
    liststack.push(100);
    liststack.push(200);
    liststack.push(300);

    std::cout << CYAN << "Iterating through MutantStack<std::list> elements:" << RESET << std::endl;
    MutantStack<int, std::list<int> >::iterator lit = liststack.begin();
    MutantStack<int, std::list<int> >::iterator lite = liststack.end();
    while (lit != lite)
    {
        std::cout << "Element: " << *lit << std::endl;
        ++lit;
    }

    // std::list comparison test
    std::cout << PURPLE << "\n=== std::list TESTS ===" << RESET << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    lstack.pop_back();
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);

    std::cout << CYAN << "Iterating through std::list elements:" << RESET << std::endl;
    std::list<int>::iterator l_it = lstack.begin();
    std::list<int>::iterator l_ite = lstack.end();
    while (l_it != l_ite)
    {
        std::cout << "Element: " << *l_it << std::endl;
        ++l_it;
    }

    std::cout << CYAN << "Copying std::list to another std::list..." << RESET << std::endl;
    std::list<int> s2(lstack);
    std::cout << "Back of copied std::list: " << s2.back() << std::endl;
    std::cout << "Size of copied std::list: " << s2.size() << std::endl;

    return 0;
}