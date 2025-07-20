#include "MutantStack.hpp"

// Default constructor
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}


// Copy assignment operator
template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& cpy) {
    if (this != &cpy)
        std::stack<T, Container>::operator=(cpy);
    return *this;
}


// Copy constructor
template<typename T, typename Container>
//  calling the copy constructor of the base class (std::stack<T, Container>) to initialize 
//  the base part of your MutantStack object with the contents of cpy.
MutantStack<T, Container>::MutantStack(const MutantStack& cpy) : std::stack<T, Container>(cpy) {}


// Destructor
template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}


// Iterator member functions
//
// NOTE: The keyword 'typename' is used to indicate that 'Container::iterator' is a type.
// This is necessary because 'Container' is a template parameter and its 'iterator' member
// is not known until the template is instantiated with a specific type.
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return this->c.end();
}