#ifndef ARRAY_HPP
#define ARRAY_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
#  define RESET "\033[0m"
# endif

template <typename T>
class Array {
    private:
        unsigned int _arrayLen;
        T* _array;

    public:
        //CONSTRUCTORS AND DESTRUCTOR_______________________________§
        Array();
        Array(unsigned int n);
        Array (const Array& cpy);
        ~Array();


        //OPERATORS OVERLOADS ("=" and "[]")________________________§
        Array& operator=(const Array& cpy);
        T& operator[](unsigned int index) const;


        //MEMBER FUNCTIONS__________________________________________§
        unsigned int size() const;


        //CUSTOM EXCEPTION CLASS____________________________________§
        class IndexOutOfBoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

// I need to include the implementation file here
// because Array is a template class, and the compiler needs to see the implementation
// when it instantiates the template with a specific type.
// If I don't include it, the compiler won't know how to generate the code for the specific type I use.
#include "Array.tpp"

#endif