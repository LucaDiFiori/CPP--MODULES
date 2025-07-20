#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

#ifndef COLORS
#define COLORS
#define PURPLE "\033[1;35m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#endif

// I specify the default container in the template parameter
// This allows the user to specify a different container if needed
// For example, std::vector or std::list can be used instead of std::deque
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        // creates an alias called iterator for the iterator type of the underlying 
        // container (Container) used by your MutantStack.
        // If Container is std::deque<T>, then iterator is std::deque<T>::iterator.
        typedef typename Container::iterator iterator;

        // Orthodox Canonical Form
        MutantStack();
        MutantStack& operator=(const MutantStack& cpy);
        MutantStack(const MutantStack& cpy);
        ~MutantStack();

        // Iterator member functions:
        // Return iterators to the beginning and end of the underlying container.
        iterator begin();
        iterator end();
};


#endif